// error:	OK
// langId:	44
// langName:	C++11
// langVersion:	gcc-4.8.1
// time:	0
// date:	2013-06-20 17:07:23
// status:	0
// result:	15
// memory:	3024
// signal:	0
// public:	false
// ------------------------------------------------
#include <list>

int main()
{
    std::list<int> l { 1,2,3,4,5,6,7,8 };
    auto it = begin(l);
    advance(it, 3);
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
