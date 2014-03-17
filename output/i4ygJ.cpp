// error:	OK
// langId:	44
// langName:	C++11
// langVersion:	gcc-4.8.1
// time:	0
// date:	2011-12-23 14:46:12
// status:	0
// result:	15
// memory:	2968
// signal:	0
// public:	false
// ------------------------------------------------
#include <cstdint>
#include <sstream>
#include <iostream>
#include <bitset>

int main()
{
    std::istringstream iss("0011111111101111111101111100111011011001000101101000011100101011");

    std::bitset<32> hi, lo;
    if (iss >> hi >> lo)
    {
        struct { uint32_t lo, hi; } words = { lo.to_ulong(), hi.to_ulong() };
        double converted = *reinterpret_cast<double*>(&words);

        std::cout << hi << std::endl;
        std::cout << lo << std::endl;
        std::cout << converted << std::endl;
    }
}
// ------------------------------------------------
#if 0 // stdin

#endif
#if 0 // stdout
00111111111011111111011111001110
11011001000101101000011100101011
0.999

#endif
#if 0 // stderr

#endif
#if 0 // cmpinfo

#endif
