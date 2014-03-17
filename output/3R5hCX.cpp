// error:	OK
// langId:	44
// langName:	C++11
// langVersion:	gcc-4.8.1
// time:	0
// date:	2013-04-21 17:35:46
// status:	0
// result:	11
// memory:	0
// signal:	0
// public:	true
// ------------------------------------------------
#include <boost/spirit/include/qi.hpp>
#include <boost/spirit/include/support_istream_iterator.hpp>
#include <boost/spirit/include/karma.hpp>
 
namespace spirit = boost::spirit;
namespace qi     = boost::spirit::qi;
namespace karma  = boost::spirit::karma;
 
int main()
{
    std::cin.unsetf(std::ios::skipws);
    spirit::istream_iterator b(std::cin), e;
 
    std::vector<std::vector<int> > vectors;
 
    if (qi::phrase_parse(b, e, +qi::int_ % qi::eol >> qi::eoi, qi::blank, vectors))
    {
        std::cerr << "Parse failed at '" << std::string(b,e) << "'\n";
        return 255;
    }
 
    // check all rows have equal amount of elements:
    const auto number_of_elements = vectors.front().size();
    for (auto& v : vectors)
        if (v.size() != number_of_elements)
            std::cerr << "Unexpected number of elements: " << v.size() << " (expected: " << number_of_elements << ")\n";
 
    // print the data for verification
    std::cout 
        << karma::format(karma::right_align(8)[karma::auto_] % ',' % '\n', vectors)
        << std::endl;
 
    return 0;
}
// ------------------------------------------------
#if 0 // stdin
1 2 3 4 5
6 7 8 9 10
11 12 13 14 15 

#endif
#if 0 // stdout

#endif
#if 0 // stderr

#endif
#if 0 // cmpinfo
prog.cpp:1:39: fatal error: boost/spirit/include/qi.hpp: No such file or directory
compilation terminated.

#endif
