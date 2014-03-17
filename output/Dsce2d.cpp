// error:	OK
// langId:	44
// langName:	C++11
// langVersion:	gcc-4.8.1
// time:	0
// date:	2013-09-25 02:23:26
// status:	0
// result:	15
// memory:	3344
// signal:	0
// public:	false
// ------------------------------------------------
#include <algorithm>
#include <iostream>
#include <cstring>

int main()
{
    char const* strings[] = {
        "hello",
        "world",
        "computers",
        "are",
        "awesome"
    };

    struct { 
        bool operator()(char const* a, char const* b) const {
            return (a && b)? 0 > strcmp(a,b) : a < b;
        }
    } cmp;

    std::sort(std::begin(strings), std::end(strings), cmp);

    for (auto& s : strings)
        std::cout << s << "\n";
}

// ------------------------------------------------
#if 0 // stdin

#endif
#if 0 // stdout
are
awesome
computers
hello
world

#endif
#if 0 // stderr

#endif
#if 0 // cmpinfo

#endif
