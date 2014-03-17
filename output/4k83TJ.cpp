// error:	OK
// langId:	44
// langName:	C++11
// langVersion:	gcc-4.8.1
// time:	0
// date:	2013-07-19 10:11:40
// status:	0
// result:	15
// memory:	2852
// signal:	0
// public:	true
// ------------------------------------------------
#include <cstdio>

template <typename F>
void repeat(unsigned n, F f)
{
    while (n--) f();
}

int main(int argc, const char *argv[])
{
    repeat(10, []{puts("puts");});
}

// ------------------------------------------------
#if 0 // stdin

#endif
#if 0 // stdout
puts
puts
puts
puts
puts
puts
puts
puts
puts
puts

#endif
#if 0 // stderr

#endif
#if 0 // cmpinfo

#endif
