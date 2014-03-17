// error:	OK
// langId:	1
// langName:	C++ 4.8.1
// langVersion:	gcc-4.8.1
// time:	0
// date:	2012-04-23 12:32:59
// status:	0
// result:	11
// memory:	0
// signal:	0
// public:	false
// ------------------------------------------------
#include<type_info>
#include<string>

template <typename T>
inline std::string typestr(T const&)
{ return typestr<T>(); }

int main()
{
    struct X {} ;
    std::string s = typestr(X());
}
// ------------------------------------------------
#if 0 // stdin

#endif
#if 0 // stdout

#endif
#if 0 // stderr

#endif
#if 0 // cmpinfo
prog.cpp:1:20: error: type_info: No such file or directory
prog.cpp: In function ‘int main()’:
prog.cpp:11: error: no matching function for call to ‘typestr(main()::X)’
prog.cpp:11: warning: unused variable ‘s’

#endif
