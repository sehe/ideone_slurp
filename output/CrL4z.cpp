// error:	OK
// langId:	1
// langName:	C++ 4.8.1
// langVersion:	gcc-4.8.1
// time:	0
// date:	2011-11-25 21:58:29
// status:	0
// result:	15
// memory:	2724
// signal:	0
// public:	false
// ------------------------------------------------
#include <iostream>

int main()
{
    int a[5];

    std::cout << (a+1) << " " << (a+0) << std::endl;
    std::cout << (reinterpret_cast<char*>(a+1) - reinterpret_cast<char*>(a+0)) << std::endl;
}
// ------------------------------------------------
#if 0 // stdin

#endif
#if 0 // stdout
0xbfdd64a0 0xbfdd649c
4

#endif
#if 0 // stderr

#endif
#if 0 // cmpinfo

#endif
