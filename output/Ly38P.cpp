// error:	OK
// langId:	44
// langName:	C++11
// langVersion:	gcc-4.8.1
// time:	0
// date:	2011-10-24 22:07:53
// status:	0
// result:	15
// memory:	2956
// signal:	42
// public:	true
// ------------------------------------------------
#include <functional>

std::function<int()> dowork()
{
    int answer = 42;
    auto lambda = [answer] () { return answer; };

    // can do what we want
    answer = 666;
    return lambda;
}

int main()
{
    auto ll = dowork();
    return ll(); // 42
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
