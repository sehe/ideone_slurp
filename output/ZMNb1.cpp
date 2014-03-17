// error:	OK
// langId:	44
// langName:	C++11
// langVersion:	gcc-4.8.1
// time:	0
// date:	2011-11-13 01:53:50
// status:	0
// result:	11
// memory:	0
// signal:	0
// public:	true
// ------------------------------------------------
#include <type_traits>
#include <iostream>

template <typename T>
    void cannot_take_pointer(T ptr)
{
    static_assert(!std::is_pointer<T>::value, 
        "cannot_take_pointer requires non-pointer argument");
    std::cout << "ok\n";
}

int main()
{
    int x;
    cannot_take_pointer(x);
    cannot_take_pointer(&x);  // fails to compile
}
// ------------------------------------------------
#if 0 // stdin

#endif
#if 0 // stdout

#endif
#if 0 // stderr

#endif
#if 0 // cmpinfo
prog.cpp: In function 'void cannot_take_pointer(T) [with T = int*]':
prog.cpp:16:27:   instantiated from here
prog.cpp:7:5: error: static assertion failed: "cannot_take_pointer requires non-pointer argument"

#endif
