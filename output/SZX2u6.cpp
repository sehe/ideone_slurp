// error:	OK
// langId:	44
// langName:	C++11
// langVersion:	gcc-4.8.1
// time:	0
// date:	2013-09-03 14:52:54
// status:	0
// result:	0
// memory:	0
// signal:	0
// public:	false
// ------------------------------------------------
#define BOOST_SPIRIT_USE_PHOENIX_V3
#include <boost/spirit/include/qi.hpp>
#include <boost/spirit/include/phoenix.hpp>
#include <boost/phoenix/function/adapt_function.hpp>

struct add_operand { 
    template<typename...> struct result { typedef void type; };
    template<typename L, typename R>
    void operator()(L& lhs, R rhs) const { lhs += rhs; } 
};

struct sub_operand { 
    template<typename...> struct result { typedef void type; };
    template<typename L, typename R>
    void operator()(L& lhs, R rhs) const { lhs -= rhs; } 
};

int main()
{
    const std::string INPUT_DATA = "12e-1 + 3.4 - .67";
    typedef std::string::const_iterator iterator_type;
    iterator_type begin = std::begin(INPUT_DATA);
    iterator_type end   = std::end(INPUT_DATA);

    namespace qi    = boost::spirit::qi;
    namespace ascii = boost::spirit::qi::ascii;
    namespace phx   = boost::phoenix;

    bool ok;
    double result;
    {
        using namespace qi;
        phx::function<add_operand> add_;
        phx::function<sub_operand> sub_;

        auto parser = 
               double_                  [_val  = _1]
            >> *(   (lit('+') >> double_[add_(_val, _1)])
                  | (lit('-') >> double_[sub_(_val, _1)])
                );

        ok = phrase_parse(begin, end, parser, ascii::space, result);
    }

    if (ok  && begin == end)
        std::cout << "parsed, result = " << result << std::endl;
    else
        std::cout << "not parsed" << std::endl;
}

// ------------------------------------------------
#if 0 // stdin

#endif
#if 0 // stdout

#endif
#if 0 // stderr

#endif
#if 0 // cmpinfo

#endif
