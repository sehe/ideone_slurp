// error:	OK
// langId:	44
// langName:	C++11
// langVersion:	gcc-4.8.1
// time:	0
// date:	2013-07-12 00:58:51
// status:	0
// result:	15
// memory:	2984
// signal:	0
// public:	false
// ------------------------------------------------
#include <iostream>
#include <type_traits>
#include <functional>

#if 1
template <typename F>
auto myFunc(F f) -> decltype(!f('0'), std::function<bool(char)>(f), void()) {
    std::cout << "std::function<bool(char)> overload" << std::endl;
}
#else
template <typename F>
void myFunc(F f, typename std::enable_if<std::is_constructible<
       std::function<bool(char)>, F>::value>::type* = nullptr)
{
    std::cout << "std::function<bool(char)> overload" << std::endl;
}
#endif


void myFunc(const std::string &seperator) {
    std::cout << "std::string overload" << std::endl;
}

bool testCallback(char) {
    return true;
}

int main()
{
    myFunc("String literal");
    myFunc(std::string("std::string"));
    myFunc(testCallback);
}

// ------------------------------------------------
#if 0 // stdin

#endif
#if 0 // stdout
std::string overload
std::string overload
std::function<bool(char)> overload

#endif
#if 0 // stderr

#endif
#if 0 // cmpinfo

#endif
