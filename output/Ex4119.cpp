// error:	OK
// langId:	1
// langName:	C++ 4.8.1
// langVersion:	gcc-4.8.1
// time:	0
// date:	2012-11-21 08:54:34
// status:	0
// result:	11
// memory:	0
// signal:	0
// public:	false
// ------------------------------------------------
#include <iostream>
int main()
{
    long l = 42;
    auto& ref = static_cast<int const&>(l);
    std::cout << l << " " << ref << "\n";
    l+=1;
    std::cout << l << " " << ref << "\n";
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
prog.cpp:5: error: ISO C++ forbids declaration of ‘ref’ with no type
prog.cpp:5: error: invalid initialization of reference of type ‘int&’ from expression of type ‘const int’

#endif
