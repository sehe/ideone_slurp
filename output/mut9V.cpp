// error:	OK
// langId:	1
// langName:	C++ 4.8.1
// langVersion:	gcc-4.8.1
// time:	0
// date:	2011-10-14 11:19:23
// status:	0
// result:	15
// memory:	2724
// signal:	0
// public:	true
// ------------------------------------------------
#include <iostream>

struct MyBase
{
     virtual void DoStuff(int, float) { std::cout << "Base" << std::endl; } 
};

struct MyDerived : MyBase
{
     virtual void DoStuff(int, float) { std::cout << "Derived" << std::endl; } 
};

int main()
{
    typedef void (MyBase::*memfun)(int, float);

    memfun event(&MyBase::DoStuff);

    MyBase base;
    MyDerived derived;

    (base.*event)(42, 3.14);
    (derived.*event)(42, 3.14);
}

// ------------------------------------------------
#if 0 // stdin

#endif
#if 0 // stdout
Base
Derived

#endif
#if 0 // stderr

#endif
#if 0 // cmpinfo

#endif
