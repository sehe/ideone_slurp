// error:	OK
// langId:	1
// langName:	C++ 4.8.1
// langVersion:	gcc-4.8.1
// time:	0
// date:	2012-10-07 22:29:06
// status:	0
// result:	11
// memory:	0
// signal:	0
// public:	true
// ------------------------------------------------
#include <cstdio>

struct A     { virtual foo() const { puts("A"); } };

struct B : A { virtual foo() const { puts("B"); } };

int main() {

    const A& a = B();

    a.foo();

}

// ------------------------------------------------
#if 0 // stdin

#endif
#if 0 // stdout

#endif
#if 0 // stderr

#endif
#if 0 // cmpinfo
prog.cpp:3: error: ISO C++ forbids declaration of ‘foo’ with no type
prog.cpp: In member function ‘virtual int A::foo() const’:
prog.cpp:3: warning: no return statement in function returning non-void
prog.cpp: At global scope:
prog.cpp:5: error: ISO C++ forbids declaration of ‘foo’ with no type
prog.cpp: In member function ‘virtual int B::foo() const’:
prog.cpp:5: warning: no return statement in function returning non-void

#endif
