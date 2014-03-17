// error:	OK
// langId:	44
// langName:	C++11
// langVersion:	gcc-4.8.1
// time:	0
// date:	2012-01-16 08:50:55
// status:	0
// result:	11
// memory:	0
// signal:	0
// public:	true
// ------------------------------------------------
#include <memory>

std::unique_ptr<void> blah2(std::unique_ptr<void>&& foo)
{
   return foo;
}



int main()
{
   std::unique_ptr<void> f;
   std::unique_ptr<void> t = blah2(std::move(f));
}
// ------------------------------------------------
#if 0 // stdin

#endif
#if 0 // stdout

#endif
#if 0 // stderr

#endif
#if 0 // cmpinfo
/usr/lib/gcc/i686-pc-linux-gnu/4.5.1/../../../../include/c++/4.5.1/bits/unique_ptr.h: In function 'std::unique_ptr<void> blah2(std::unique_ptr<void>&&)':
/usr/lib/gcc/i686-pc-linux-gnu/4.5.1/../../../../include/c++/4.5.1/bits/unique_ptr.h:207:7: error: deleted function 'std::unique_ptr<_Tp, _Tp_Deleter>::unique_ptr(const std::unique_ptr<_Tp, _Tp_Deleter>&) [with _Tp = void, _Tp_Deleter = std::default_delete<void>, std::unique_ptr<_Tp, _Tp_Deleter> = std::unique_ptr<void>]'
prog.cpp:5:11: error: used here

#endif
