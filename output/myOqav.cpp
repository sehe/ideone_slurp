// error:	OK
// langId:	44
// langName:	C++11
// langVersion:	gcc-4.8.1
// time:	0
// date:	2013-08-23 16:06:17
// status:	0
// result:	11
// memory:	0
// signal:	0
// public:	false
// ------------------------------------------------
#include <boost/dynamic_bitset.hpp>
#include <numeric>
#include <iostream>

using bs = boost::dynamic_bitset<>;

int main()
{
    std::cout << std::accumulate(
            std::istream_iterator<bs>(std::cin), {}, 
            std::string{}, [](std::string& accum, bs bits) {
                do accum.insert(accum.begin(), (bits & bs(bits.size(), 0xFF)).to_ulong());
                while ((bits>>=8).count());
                return accum;
            });
}

// ------------------------------------------------
#if 0 // stdin
01010100011101010111001001101001011011100110011101110111011101110111011100101110011000110110000101101101011100000111010101110011001011010111000001100001011100100111010001111001001011100110010101110101

#endif
#if 0 // stdout

#endif
#if 0 // stderr

#endif
#if 0 // cmpinfo
prog.cpp:1:36: fatal error: boost/dynamic_bitset.hpp: No such file or directory
 #include <boost/dynamic_bitset.hpp>
                                    ^
compilation terminated.

#endif
