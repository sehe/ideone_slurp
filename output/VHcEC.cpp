// error:	OK
// langId:	1
// langName:	C++ 4.8.1
// langVersion:	gcc-4.8.1
// time:	0
// date:	2011-11-23 23:59:59
// status:	0
// result:	15
// memory:	2856
// signal:	0
// public:	false
// ------------------------------------------------
#include <string>
#include <iostream>
#include <boost/bind.hpp>
#include <boost/typeof/typeof.hpp>

struct overloaded
{
    typedef int result_type;

    int operator()(const std::string& s) const { return 1; }
    int operator()(double d)             const { return 2; }
};

struct factory
{
    template <typename T> struct result { typedef BOOST_TYPEOF_TPL(boost::bind(overloaded(), T())) type; };

    template <typename T>
    typename result<T>::type operator()(T t) const 
    {
        return boost::bind(overloaded(), t);
    }
};

int main()
{
    overloaded foo;

    // based on local bind expression:
    BOOST_AUTO(unresolved, boost::bind(foo, _1));
    std::cout << unresolved("3.14") << std::endl;  // should print 1
    std::cout << unresolved(3.14)   << std::endl;  // should print 2

    // based on a factory function template
    factory makefoo;
    std::cout << makefoo("3.14")() << std::endl;  // should print 1
    std::cout << makefoo(3.14)()   << std::endl;  // should print 2
}
// ------------------------------------------------
#if 0 // stdin

#endif
#if 0 // stdout
1
2
1
2

#endif
#if 0 // stderr

#endif
#if 0 // cmpinfo

#endif
