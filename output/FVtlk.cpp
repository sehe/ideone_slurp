// error:	OK
// langId:	44
// langName:	C++11
// langVersion:	gcc-4.8.1
// time:	0
// date:	2011-10-25 22:39:50
// status:	0
// result:	15
// memory:	2828
// signal:	0
// public:	true
// ------------------------------------------------
#include <iostream>

int main() {
    const int b = ({ int a; std::cin >> a; a; });
    const int c = []() -> int { int a; std::cin >> a; return a; }();
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
