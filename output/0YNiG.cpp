// error:	OK
// langId:	1
// langName:	C++ 4.8.1
// langVersion:	gcc-4.8.1
// time:	0.01
// date:	2012-10-07 22:29:34
// status:	0
// result:	15
// memory:	2680
// signal:	0
// public:	true
// ------------------------------------------------
#include <cstdio>

struct A     { virtual void foo() const { puts("A"); } };

struct B : A { virtual void foo() const { puts("B"); } };

int main() {

    const A& a = B();

    a.foo();

}

// ------------------------------------------------
#if 0 // stdin

#endif
#if 0 // stdout
B

#endif
#if 0 // stderr

#endif
#if 0 // cmpinfo

#endif
