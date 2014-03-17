// error:	OK
// langId:	44
// langName:	C++11
// langVersion:	gcc-4.8.1
// time:	0
// date:	2011-09-16 16:03:11
// status:	0
// result:	15
// memory:	2824
// signal:	1
// public:	true
// ------------------------------------------------
/////////////////////////////////////////////////////
// unit1.cpp

extern auto lambda = [] (int i) { return i+1; };

/////////////////////////////////////////////////////
// main.cpp

/*
 * what type specify in your other compilation unit? probably, the actual type has no 
 * external linkage ....
 */
// extern auto lambda; 

int main()
{
    return lambda(0);
}
// ------------------------------------------------
#if 0 // stdin

#endif
#if 0 // stdout

#endif
#if 0 // stderr

#endif
#if 0 // cmpinfo
prog.cpp:4:13: warning: 'lambda' initialized and declared 'extern'

#endif
