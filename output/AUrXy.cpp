// error:	OK
// langId:	1
// langName:	C++ 4.8.1
// langVersion:	gcc-4.8.1
// time:	0
// date:	2011-11-29 13:26:09
// status:	0
// result:	15
// memory:	2724
// signal:	0
// public:	false
// ------------------------------------------------
#include <iostream>

struct bits
{
    signed int field : 5;
};

int main()
{
    bits a = { -16 };     
    bits b = {  28 };

    bits c = { a.field - b.field };
    std::cout << c.field << std::endl;
}
// ------------------------------------------------
#if 0 // stdin

#endif
#if 0 // stdout
-12

#endif
#if 0 // stderr

#endif
#if 0 // cmpinfo

#endif
