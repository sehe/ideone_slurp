// error:	OK
// langId:	1
// langName:	C++ 4.8.1
// langVersion:	gcc-4.8.1
// time:	0.02
// date:	2012-10-14 21:07:43
// status:	0
// result:	15
// memory:	2680
// signal:	0
// public:	false
// ------------------------------------------------
#include <cstdio>

struct A
{
    A() { puts("A"); }
    A(A const&) { puts("copy"); }
   ~A() { puts("~A"); }
};

int main()
{
    A f[10];
    A g[10] = f;
}
// ------------------------------------------------
#if 0 // stdin

#endif
#if 0 // stdout
A
A
A
A
A
A
A
A
A
A
copy
copy
copy
copy
copy
copy
copy
copy
copy
copy
~A
~A
~A
~A
~A
~A
~A
~A
~A
~A
~A
~A
~A
~A
~A
~A
~A
~A
~A
~A

#endif
#if 0 // stderr

#endif
#if 0 // cmpinfo

#endif
