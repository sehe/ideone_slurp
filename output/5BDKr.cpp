// error:	OK
// langId:	1
// langName:	C++ 4.8.1
// langVersion:	gcc-4.8.1
// time:	0
// date:	2011-09-12 15:05:17
// status:	0
// result:	15
// memory:	2724
// signal:	0
// public:	true
// ------------------------------------------------
#include <iostream>
#include <algorithm>

void a() { std::cout<<"a"<<std::endl; }
void b() { std::cout<<"b"<<std::endl; }
void c() { std::cout<<"c"<<std::endl; }
void d() { std::cout<<"d"<<std::endl; }
void e() { std::cout<<"e"<<std::endl; }

int main()
{
    typedef void(*flashfunc)();
    static flashfunc flashes[] = {a,b,c,d,e};

    std::random_shuffle(flashes, flashes+5);

    for (flashfunc *flash=flashes; flash!=flashes+5; ++flash)
        (*flash)();

    return 0;   
}
// ------------------------------------------------
#if 0 // stdin

#endif
#if 0 // stdout
e
d
b
c
a

#endif
#if 0 // stderr

#endif
#if 0 // cmpinfo

#endif
