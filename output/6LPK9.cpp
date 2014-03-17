// error:	OK
// langId:	44
// langName:	C++11
// langVersion:	gcc-4.8.1
// time:	0
// date:	2012-04-23 14:02:32
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
prog.cpp:1:20: fatal error: type_info: No such file or directory
compilation terminated.

#endif
