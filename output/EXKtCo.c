// error:	OK
// langId:	11
// langName:	C
// langVersion:	gcc-4.8.1
// time:	0
// date:	2013-09-03 12:11:34
// status:	0
// result:	15
// memory:	2244
// signal:	0
// public:	false
// ------------------------------------------------
struct X
{
   int some;
   const char* really_long;
   double and_annoying_variable_names;
};

int main()
{
    struct X x = { 42, "hello world", 3.14 };
    // reassign:
    struct X y = { 0, "dummy", 0.0 };
    x = y;
    
    
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

#endif
