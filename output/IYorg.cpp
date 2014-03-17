// error:	OK
// langId:	1
// langName:	C++ 4.8.1
// langVersion:	gcc-4.8.1
// time:	0.01
// date:	2012-06-11 13:19:23
// status:	0
// result:	15
// memory:	2852
// signal:	0
// public:	false
// ------------------------------------------------
#include <string>

int main()
{
     std::string a = "hello world";

     std::string().swap(a);
//   a.swap(std::string()); -- can't work due to temp
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
