// error:	OK
// langId:	44
// langName:	C++11
// langVersion:	gcc-4.8.1
// time:	0
// date:	2011-12-18 05:06:16
// status:	0
// result:	15
// memory:	2960
// signal:	0
// public:	false
// ------------------------------------------------
#include <iostream>
#include <functional>
using namespace std::placeholders;

int foo(int i)
{
    return i*2;
}

int main(int argc, const char *argv[])
{
    std::function<int(int, int)> barfunc = std::bind(foo, (_1, _2));
    std::cout << barfunc(-999, 21) << std::endl;

    // or even (thanks Xeo)
    barfunc = std::bind(foo, _2);
    std::cout << barfunc(-999, 21) << std::endl;
}

// ------------------------------------------------
#if 0 // stdin

#endif
#if 0 // stdout
42
42

#endif
#if 0 // stderr

#endif
#if 0 // cmpinfo

#endif
