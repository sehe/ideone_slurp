// error:	OK
// langId:	44
// langName:	C++11
// langVersion:	gcc-4.8.1
// time:	0
// date:	2011-10-06 10:24:46
// status:	0
// result:	15
// memory:	2964
// signal:	0
// public:	true
// ------------------------------------------------
#include <iostream>
#include <utility>
#include <vector>

int i = 0;
struct A
{
    A() : j( ++i )
    {
        std::cout<<"constructor "<<j<<std::endl;
    }
    A( const A & c) : j(c.j)
    {
        std::cout<<"copy "<<j<<std::endl;
    }
    A( const A && c) : j(c.j)
    {
        std::cout<<"move "<<j<<std::endl;
    }
    ~A()
    {
        std::cout<<"destructor "<<j<<std::endl;
    }

    int j;
};

typedef std::vector< A > vec;

void foo( vec & v )
{
    v.push_back( std::move( A() ) );
}

int main()
{
    vec v;
    v.reserve(2);

    foo( v );
    foo( v );
}
// ------------------------------------------------
#if 0 // stdin

#endif
#if 0 // stdout
constructor 1
move 1
destructor 1
constructor 2
move 2
destructor 2
destructor 1
destructor 2

#endif
#if 0 // stderr

#endif
#if 0 // cmpinfo

#endif
