// error:	OK
// langId:	44
// langName:	C++11
// langVersion:	gcc-4.8.1
// time:	0
// date:	2012-10-19 01:59:44
// status:	0
// result:	11
// memory:	0
// signal:	0
// public:	false
// ------------------------------------------------
#include <vector>
#include <iostream>
#include <functional>

struct Base {};

template <typename U> struct B : Base 
{ 
    void bar() {} 
    void foo() 
    {
        std::bind(&B::bar, this);
    } 
};

template <typename T> struct A {
    typedef typename T::value_type type;
};

void freefunction(Base& /*acceptAll*/) {}

int main ()
{
    B< A<std::vector<int> > >  a;
    B< A<void> >               b;

    // surrounding with parens prevents ADL:
    (freefunction)(a);
    (freefunction)(b); // selects ::freefunction(Base&)

    freefunction(a);   // ADL selects friend inline freefunction(B< A<std::vector<int> > >&)

    a.foo();
    b.foo();
}

// ------------------------------------------------
#if 0 // stdin

#endif
#if 0 // stdout

#endif
#if 0 // stderr

#endif
#if 0 // cmpinfo
prog.cpp: In instantiation of 'A<void>':
prog.cpp:29:21:   instantiated from here
prog.cpp:17:36: error: 'void' is not a class, struct, or union type

#endif
