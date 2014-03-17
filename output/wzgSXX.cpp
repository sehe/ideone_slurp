// error:	OK
// langId:	44
// langName:	C++11
// langVersion:	gcc-4.8.1
// time:	0
// date:	2013-08-07 14:33:36
// status:	0
// result:	0
// memory:	0
// signal:	0
// public:	false
// ------------------------------------------------
#include <boost/variant.hpp>
#include <boost/spirit/include/karma.hpp>

namespace karma = boost::spirit::karma;
typedef boost::variant<int, std::string> Parameter;
typedef std::vector<Parameter> Parameters;

void test(boost::variant<Parameters, Parameter> const& v)
{
    typedef boost::spirit::ostream_iterator It;
    using namespace karma;

    const static rule<It, std::string()> quoted
        = '"' << *('\\' << char_('"') | char_) << '"'
        ;
    const static rule<It, Parameter()>   param
        = int_ | quoted
        ;
    const static rule<It, boost::variant<Parameters, Parameter>()> rule
        = param | param % ", "
        ;

    std::cout << karma::format(rule, v) << '\n';
}

int main()
{
    test(1);
    test("foo");
    test("escape: \"foo\"");
    test(Parameters { 1, 2, 3, "escape: \"foo\"" });
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
