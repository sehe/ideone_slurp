// error:	OK
// langId:	44
// langName:	C++11
// langVersion:	gcc-4.8.1
// time:	0
// date:	2012-11-21 08:54:46
// status:	0
// result:	15
// memory:	2884
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
42 42
43 42

#endif
#if 0 // stderr

#endif
#if 0 // cmpinfo

#endif
