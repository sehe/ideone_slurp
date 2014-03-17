// error:	OK
// langId:	1
// langName:	C++ 4.8.1
// langVersion:	gcc-4.8.1
// time:	0
// date:	2011-09-30 16:53:44
// status:	0
// result:	15
// memory:	2852
// signal:	0
// public:	false
// ------------------------------------------------
int* getA(int no)
{
   int *a = new int[no];
   return a;
}

main()
{
  int* a = getA(10);
  delete []a;
}
// ------------------------------------------------
#if 0 // stdin

#endif
#if 0 // stdout

#endif
#if 0 // stderr

#endif
#if 0 // cmpinfo
prog.cpp:7: warning: ISO C++ forbids declaration of ‘main’ with no type

#endif
