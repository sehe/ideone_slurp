// error:	OK
// langId:	44
// langName:	C++11
// langVersion:	gcc-4.8.1
// time:	0
// date:	2013-10-14 02:09:17
// status:	0
// result:	11
// memory:	0
// signal:	0
// public:	false
// ------------------------------------------------
int main()
{
    static_assert('B'>'b', "Whoops");
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
prog.cpp:3:5: error: static assertion failed: Whoops
     static_assert('B'>'b', "Whoops");
     ^

#endif
