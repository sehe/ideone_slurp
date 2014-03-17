// error:	OK
// langId:	1
// langName:	C++ 4.8.1
// langVersion:	gcc-4.8.1
// time:	0
// date:	2012-09-03 23:28:36
// status:	0
// result:	11
// memory:	0
// signal:	0
// public:	false
// ------------------------------------------------
#include <iostream>
int main(){ 
#if 1
    auto number = 0ULL;// xFFFFFFFFULL;
#else
    auto number = 0xFFFFFFFFFFFFULL;
#endif
    const auto last   = number + (1ULL<<34);
    for(auto i=number; i <= last; ++i){ 
        number += i; 
    } 
    std::cout << number << std::endl; 
}

// ------------------------------------------------
#if 0 // stdin

#endif
#if 0 // stdout

#endif
#if 0 // stderr

#endif
#if 0 // cmpinfo
prog.cpp: In function ‘int main()’:
prog.cpp:4: error: ISO C++ forbids declaration of ‘number’ with no type
prog.cpp:8: error: ISO C++ forbids declaration of ‘last’ with no type
prog.cpp:9: error: ISO C++ forbids declaration of ‘i’ with no type

#endif
