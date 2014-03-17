// error:	OK
// langId:	44
// langName:	C++11
// langVersion:	gcc-4.8.1
// time:	0
// date:	2011-11-13 19:02:59
// status:	0
// result:	15
// memory:	2956
// signal:	0
// public:	true
// ------------------------------------------------
#include <functional>

struct SomeT { static int magic(unsigned char*) {} };

template<typename T> void example()
{
    std::function<int (unsigned char*)> test = [=](unsigned char* start) -> int
    {
        return T::magic(start);
    };
}

int main()
{
    example<SomeT>();
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
