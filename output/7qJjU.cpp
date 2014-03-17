// error:	OK
// langId:	44
// langName:	C++11
// langVersion:	gcc-4.8.1
// time:	0
// date:	2012-02-22 22:59:09
// status:	0
// result:	11
// memory:	0
// signal:	0
// public:	false
// ------------------------------------------------
// #define BOOST_SPIRIT_DEBUG
#ifdef __GXX_EXPERIMENTAL_CXX0X__
    #define BOOST_RESULT_OF_USE_DECLTYPE
#endif
#include <boost/fusion/adapted.hpp>
// #include <boost/optional.hpp>
// #include <boost/variant.hpp>
// #include <boost/variant/recursive_wrapper.hpp>
#include <boost/spirit/include/qi.hpp>
#include <boost/spirit/include/karma.hpp>
// #include <boost/spirit/include/phoenix.hpp>
// #include <boost/spirit/include/phoenix_operator.hpp>

namespace qi    = boost::spirit::qi;
namespace karma = boost::spirit::karma;
namespace phx   = boost::phoenix;

typedef std::string attr_t;

template <typename It, typename Skipper = qi::space_type>
    struct parser : qi::grammar<It, attr_t(), Skipper>
{
    parser() : parser::base_type(start)
    {
        using namespace qi;
        // using phx::bind; using phx::ref; using phx::val;

        start %= eps;
        BOOST_SPIRIT_DEBUG_NODE(start);
    }

  private:
    qi::rule<It, attr_t(), Skipper> start;
};

template <typename C, typename Skipper>
    bool doParse(const C& input, const Skipper& skipper)
{
    auto f(std::begin(input)), l(std::end(input));

    parser<decltype(f), Skipper> p;
    attr_t data;
    bool ok = qi::phrase_parse(f,l,p,skipper,data);

    try
    {
        if (ok)   
        {
            std::cout << "parse success\n";
            std::cout << "data: " << karma::format_delimited(karma::auto_, ' ', data) << "\n";
        }
        else      std::cerr << "parse failed: '" << std::string(f,l) << "'\n";

        if (f!=l) std::cerr << "trailing unparsed: '" << std::string(f,l) << "'\n";
        return ok;
    } catch(const qi::expectation_failure<decltype(f)>& e)
    {
        std::string frag(e.first, e.last);
        std::cerr << e.what() << "'" << frag << "'\n";
    }

    return false;
}

template <typename C>
    bool doParse(const C& input)
{
    return doParse(input, qi::space);
}


// ------------------------------------------------
#if 0 // stdin

#endif
#if 0 // stdout

#endif
#if 0 // stderr

#endif
#if 0 // cmpinfo
prog.cpp:5:36: fatal error: boost/fusion/adapted.hpp: No such file or directory
compilation terminated.

#endif
