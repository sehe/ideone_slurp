// error:	OK
// langId:	44
// langName:	C++11
// langVersion:	gcc-4.8.1
// time:	0
// date:	2012-06-12 23:30:01
// status:	0
// result:	11
// memory:	0
// signal:	0
// public:	false
// ------------------------------------------------
#define BOOST_RESULT_OF_USE_DECLTYPE
#include <boost/range/istream_range.hpp>
#include <boost/range/algorithm.hpp>
#include <boost/range/adaptors.hpp>
#include <iostream>

using boost::copy;
using boost::for_each;
using boost::adaptors::transformed;
using boost::adaptors::indexed;

template <typename Rng, unsigned per_line=8>
    void dump(const Rng& data)
{
    auto idx = data | indexed(1);
    for(auto it = begin(idx); it != end(idx); ++it)
        std::cout << *it << ((it.index() % per_line == 0)? '\n' : ' ');
}

int main() {
    using std::string;

    auto toupper = [](string s) -> string { for_each(s, [](char& c) { c = std::toupper((unsigned char) c); }); return s; };
    auto input = boost::istream_range<string>(std::cin);

    dump(input | transformed(toupper));

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
prog.cpp:2:41: fatal error: boost/range/istream_range.hpp: No such file or directory
compilation terminated.

#endif
