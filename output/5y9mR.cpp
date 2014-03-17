// error:	OK
// langId:	1
// langName:	C++ 4.8.1
// langVersion:	gcc-4.8.1
// time:	0
// date:	2011-11-12 18:29:43
// status:	0
// result:	15
// memory:	2724
// signal:	0
// public:	true
// ------------------------------------------------
#include<iostream>

class abc
{
    int x;
    virtual void t();
};

template <int unique> struct interm : virtual abc 
{
    virtual void t();
    virtual void s();
};

struct xyz : 
    /*virtual*/ interm<1>, 
    /*virtual*/ interm<2>, 
    /*virtual*/ interm<3>, 
    /*virtual*/ interm<4>,
    /*virtual*/ interm<5>, 
    /*virtual*/ interm<6>, 
    /*virtual*/ interm<7>, 
    /*virtual*/ interm<8>
{
    int b;
    virtual void t();
    virtual void s();
};


int main()
{
    std::cout << sizeof(abc)       << std::endl;
    std::cout << sizeof(interm<1>) << std::endl;
    std::cout << sizeof(xyz)       << std::endl;
    return 0;
}

// ------------------------------------------------
#if 0 // stdin

#endif
#if 0 // stdout
8
12
44

#endif
#if 0 // stderr

#endif
#if 0 // cmpinfo

#endif
