// error:	OK
// langId:	44
// langName:	C++11
// langVersion:	gcc-4.8.1
// time:	0
// date:	2012-11-24 00:58:19
// status:	0
// result:	11
// memory:	0
// signal:	0
// public:	true
// ------------------------------------------------
#define BOOST_SPIRIT_DEBUG
#define BOOST_SPIRIT_USE_PHOENIX_V3

#include <boost/spirit/include/qi.hpp>
#include <boost/config/warning_disable.hpp>
#include <boost/spirit/include/qi.hpp>
#include <boost/spirit/include/phoenix.hpp>
#include <string>
#include <iostream>

namespace client
{
    namespace qi = boost::spirit::qi;
    namespace ascii = boost::spirit::ascii;

    struct binary_op;
    struct unary_op;
    struct nil {};

    struct expression_ast
    {
        typedef
            boost::variant<
            nil // can't happen!
            , double
            , std::string
            , boost::recursive_wrapper<expression_ast>
            , boost::recursive_wrapper<binary_op>
            , boost::recursive_wrapper<unary_op>
            >
            type;

        expression_ast()
            : m_expr(nil()) {}

        template <typename Expr>
            expression_ast(Expr const& expr)
            : m_expr(expr) {}

        expression_ast& operator+=(expression_ast const& rhs);
        expression_ast& operator-=(expression_ast const& rhs);
        expression_ast& operator*=(expression_ast const& rhs);
        expression_ast& operator/=(expression_ast const& rhs);

        type m_expr;
    };

    struct binary_op
    {
        binary_op(
                char op
                , expression_ast const& left
                , expression_ast const& right)
            : m_op(op), m_left(left), m_right(right) {}

        char m_op;
        expression_ast m_left;
        expression_ast m_right;
    };

    struct unary_op
    {
        unary_op(
                char op
                , expression_ast const& subject)
            : m_op(op), m_subject(subject) {}

        char m_op;
        expression_ast m_subject;
    };

    expression_ast& expression_ast::operator+=(expression_ast const& rhs)
    {
        m_expr = binary_op('+', m_expr, rhs);
        return *this;
    }

    expression_ast& expression_ast::operator-=(expression_ast const& rhs)
    {
        m_expr = binary_op('-', m_expr, rhs);
        return *this;
    }

    expression_ast& expression_ast::operator*=(expression_ast const& rhs)
    {
        m_expr = binary_op('*', m_expr, rhs);
        return *this;
    }

    expression_ast& expression_ast::operator/=(expression_ast const& rhs)
    {
        m_expr = binary_op('/', m_expr, rhs);
        return *this;
    }


    struct ast_print
    {
        typedef std::string result_type;

        std::string operator()(qi::info::nil) const
        {
            return "";
        }
        std::string operator()(std::string const& str) const
        {
            return str;
        }
        std::string operator()(double d) const
        {
            std::ostringstream oss;
            oss << d;
            return oss.str();
        }

        std::string operator()(expression_ast const& ast) const
        {
            return boost::apply_visitor(*this, ast.m_expr);
        }

        std::string operator()(binary_op const& expr) const
        {
            std::ostringstream oss;
            oss << "op:" << expr.m_op << "(";
            oss << boost::apply_visitor(*this, expr.m_left.m_expr);
            oss << ", ";
            oss << boost::apply_visitor(*this, expr.m_right.m_expr);
            oss << ')';
            return oss.str();
        }

        std::string operator()(unary_op const& expr) const
        {
            std::ostringstream oss;
            oss << "op:" << expr.m_op << "(";
            oss << boost::apply_visitor(*this, expr.m_subject.m_expr);
            oss << ')';
            return oss.str();
        }
    };

    std::ostream& operator << (std::ostream& stream, const expression_ast& expr)
    {
        ast_print printer;
        stream << printer(expr) << std::endl;
        return stream;
    }

    // CODE ADDED HERE ------------------------------------------------------------
#if 1
    template <char OP> struct operator_expr {
        template <typename T, typename=T> struct result 
        { typedef expression_ast type; };

        expression_ast operator()(expression_ast const& expr) const
        { return expression_ast(unary_op(OP, expr)); }

        expression_ast operator()(expression_ast const&a, expression_ast const&b) const 
        { return binary_op(OP, a, b); }
    };

    boost::phoenix::function<operator_expr<'-'>> neg;
    boost::phoenix::function<operator_expr<'>'>> gt;
#else
    expression_ast neg_expr(expression_ast const&a)                         { return unary_op ('-', a); }
    expression_ast gt_expr (expression_ast const&a, expression_ast const&b) { return binary_op('>', a, b); }

    BOOST_PHOENIX_ADAPT_FUNCTION(expression_ast, neg, neg_expr, 1)
    BOOST_PHOENIX_ADAPT_FUNCTION(expression_ast, gt,  gt_expr,  2)
#endif
    // CODE ADDED END HERE -------------------------------------------------------

    template <typename Iterator>
    struct ParserGenerator : qi::grammar<Iterator, expression_ast(), ascii::space_type>
    {
        ParserGenerator() : ParserGenerator::base_type(expression)
        {
            using qi::_val;
            using qi::_1;
            using qi::double_;
            using qi::iso8859_1::char_;
            using qi::iso8859_1::space;
            using qi::eol;
            using boost::spirit::ascii::string;

            comment =
                space >> ("//" >> *(char_ - eol) >> eol)
                ;

            expression =
                term                            [_val = _1]
                >> *(   ('+' >> term            [_val += _1])
                        |   ('-' >> term        [_val -= _1])
                    )
                ;

            term =
                factor                          [_val = _1]
                >> *(   ('*' >> factor          [_val *= _1])
                        |   ('/' >> factor      [_val /= _1])
                        |   ('>' >> factor      [_val = gt(qi::_val,_1)])
                    )
                ;

            factor =
                symbol                          [_val = _1]
                | double_                       [_val = _1]
                |   '(' >> expression           [_val = _1] >> ')'
                |   ('-' >> factor              [_val = neg(_1)])
                |   ('+' >> factor              [_val = _1])
                ;

            symbol %= 
                (symbol_raw 
                 >> *( string("[") >> +qi::digit >> string("]"))
                 >> *( string(".") >> symbol ))
                ;

            symbol_raw %= 
                +(qi::alpha | qi::char_( "_" ))
                ;

            BOOST_SPIRIT_DEBUG_NODE(expression);
            BOOST_SPIRIT_DEBUG_NODE(term);
            BOOST_SPIRIT_DEBUG_NODE(factor);
            BOOST_SPIRIT_DEBUG_NODE(comment);
            BOOST_SPIRIT_DEBUG_NODE(symbol);
            BOOST_SPIRIT_DEBUG_NODE(symbol_raw);
        }

        qi::rule<Iterator, expression_ast(), ascii::space_type>
            expression, term, factor, comment;

        qi::rule<Iterator, std::string(), ascii::space_type>
            symbol, symbol_raw;
    };
}

int main(int argc, char* argv[])
{
    using boost::spirit::ascii::space;
    using client::expression_ast;
    using client::ast_print;

    typedef std::string::const_iterator iterator_type;
    typedef client::ParserGenerator<iterator_type> ParserGenerator;

    ParserGenerator pg;   // our grammar
    std::string predicate( "i_.c>x[0]" );
    expression_ast  ast;
    ast_print       printer;

    iterator_type iter = predicate.begin(), end = predicate.end();
    if ( phrase_parse( iter, end, pg, space, ast ))
    {
        std::cerr << printer( ast ) << std::endl;
    }

    if (iter != end)
        std::cout << "Remaining: '" << std::string(iter, end) << std::endl;

    return 0;
}

// ------------------------------------------------
#if 0 // stdin

#endif
#if 0 // stdout

#endif
#if 0 // stderr

#endif
#if 0 // cmpinfo
prog.cpp:4:39: fatal error: boost/spirit/include/qi.hpp: No such file or directory
compilation terminated.

#endif
