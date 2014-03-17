// error:	OK
// langId:	1
// langName:	C++ 4.8.1
// langVersion:	gcc-4.8.1
// time:	0
// date:	2011-12-09 15:11:01
// status:	0
// result:	15
// memory:	2720
// signal:	0
// public:	true
// ------------------------------------------------
#include <iostream>
#include <string>

struct EmptyType {  };

template<class  arg1=EmptyType, class arg2=EmptyType, class arg3=EmptyType>
class my_class
{
    // FILL_MY_CLASS_DEFINE(3)
};
template<class  arg1, class arg2>
class my_class<arg1,arg2,EmptyType>
{
    // FILL_MY_CLASS_DEFINE(2)
};
template<class  arg1>
class my_class<arg1,EmptyType,EmptyType>
{
    // FILL_MY_CLASS_DEFINE(1)
};
template<>
class my_class<EmptyType,EmptyType,EmptyType>
{
    // FILL_MY_CLASS_DEFINE(0)
};

int main(int argc, const char *argv[])
{
    my_class<std::string, double, int> a;
    my_class<std::string, int> b;
    my_class<void> c;

    return 0;
}

// ------------------------------------------------
#if 0 // stdin

#endif
#if 0 // stdout

#endif
#if 0 // stderr

#endif
#if 0 // cmpinfo
prog.cpp: In function ‘int main(int, const char**)’:
prog.cpp:29: warning: unused variable ‘a’
prog.cpp:30: warning: unused variable ‘b’
prog.cpp:31: warning: unused variable ‘c’

#endif
