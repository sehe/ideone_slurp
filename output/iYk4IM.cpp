// error:	OK
// langId:	44
// langName:	C++11
// langVersion:	gcc-4.8.1
// time:	0
// date:	2012-11-23 01:18:57
// status:	0
// result:	15
// memory:	2928
// signal:	0
// public:	true
// ------------------------------------------------
#include <vector>
#include <iostream>

struct Base {};

template <typename U> struct B : Base { 
    template<typename T> operator T() const { return T(); } 
};

template <typename T> struct A {
    typedef typename T::value_type type;
    friend void freefunction(B<A>&) { std::cout << "ADL was here!\n"; }
};

void freefunction(Base& /*acceptAll*/) {}

int main ()
{
    B< A<std::vector<int> > >  a;
    B< A<int> >                b;

	&a;
    (int) a;
    (std::string&) a;

    (int) b;

    // surrounding with parens prevents ADL:
    (freefunction)(a);
    //(freefunction)(b); // selects ::freefunction(Base&)

    freefunction(a);   // ADL selects friend inline freefunction(B< A<std::vector<int> > >&)
    //freefunction(b);   // ADL fails: template arg cannot be (shallow) instantiated
}
// ------------------------------------------------
#if 0 // stdin

#endif
#if 0 // stdout
ADL was here!
ADL was here!

#endif
#if 0 // stderr

#endif
#if 0 // cmpinfo

#endif
