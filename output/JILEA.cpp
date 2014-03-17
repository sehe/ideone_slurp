// error:	OK
// langId:	44
// langName:	C++11
// langVersion:	gcc-4.8.1
// time:	0
// date:	2011-11-23 21:17:25
// status:	0
// result:	15
// memory:	2960
// signal:	0
// public:	false
// ------------------------------------------------
#include <string>
#include <iostream>
#include <functional>

using namespace std::placeholders;

struct overloaded
{
    int operator()(const std::string& s) const { return 1; }
    int operator()(double d)             const { return 2; }
};

template <typename T>
auto makefoo(const T& t) -> decltype(std::bind(overloaded(), t))
{
    return std::bind(overloaded(), t);
}

int main()
{
    overloaded foo;

    // based on local bind expression:
    auto unresolved = std::bind(foo, _1);
    std::cout << unresolved(3.14)   << std::endl;  // should print 2
    std::cout << unresolved("3.14") << std::endl;  // should print 1

    // based on a factory function template
    std::cout << makefoo(3.14)()   << std::endl;  // should print 2
    std::cout << makefoo("3.14")() << std::endl;  // should print 1
}
// ------------------------------------------------
#if 0 // stdin

#endif
#if 0 // stdout
2
1
2
1

#endif
#if 0 // stderr

#endif
#if 0 // cmpinfo

#endif
