// error:	OK
// langId:	44
// langName:	C++11
// langVersion:	gcc-4.8.1
// time:	0
// date:	2011-09-28 20:57:51
// status:	0
// result:	15
// memory:	2824
// signal:	0
// public:	true
// ------------------------------------------------

void takeArraryRef(const char (&)[13])
{
}

const char (&returnArrayRef())[13]
{
     return "abcdefghijkl";
}


int main()
{
    const char (&x)[13] = returnArrayRef();
    takeArraryRef(x);
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
