// error:	OK
// langId:	44
// langName:	C++11
// langVersion:	gcc-4.8.1
// time:	0
// date:	2013-10-17 23:35:36
// status:	0
// result:	15
// memory:	3336
// signal:	0
// public:	false
// ------------------------------------------------
#include <cassert>

int main() {

     char c = 0;
     assert(c == '\0');
     assert(!c);
     assert(c == 0);
     
     c = '\x01';
     assert(c != '\0');
     assert(c);
     assert(c != 0);
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
