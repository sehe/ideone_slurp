// error:	OK
// langId:	44
// langName:	C++11
// langVersion:	gcc-4.8.1
// time:	0
// date:	2011-08-29 16:49:37
// status:	0
// result:	15
// memory:	2956
// signal:	0
// public:	true
// ------------------------------------------------
#include <vector>

struct S
{
    S(int) {};
    S(S&&) {};
};

int main()
{
    std::vector<S> v = {S(1), S(2), S(3)};

    std::vector<S> or_even_just = {1, 2, 3};
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
