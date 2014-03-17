// error:	OK
// langId:	1
// langName:	C++ 4.8.1
// langVersion:	gcc-4.8.1
// time:	0.01
// date:	2012-10-19 02:17:49
// status:	0
// result:	15
// memory:	2676
// signal:	0
// public:	false
// ------------------------------------------------
#include <vector>
#include <iostream>
#include <tr1/functional>
#include <boost/utility.hpp>

template <typename T> struct A {
    typedef typename T::value_type type;
};

template <typename U> struct B
{ 
    void bar() {} 
    void foo() 
    {
        std::tr1::bind(&B::bar,  this);
        std::tr1::bind(&B::bar, *this);
        // std::tr1::bind(&B::bar, &*this); -- the usual problem here
        std::tr1::bind(&B::bar, boost::addressof(*this));
    }
};

int main ()
{
    B< A<std::vector<int> > >  a;
    B< A<void> >               b;

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

#endif
