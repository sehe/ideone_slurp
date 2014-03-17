// error:	OK
// langId:	1
// langName:	C++ 4.8.1
// langVersion:	gcc-4.8.1
// time:	0
// date:	2011-12-06 17:42:31
// status:	0
// result:	15
// memory:	2720
// signal:	0
// public:	true
// ------------------------------------------------
struct X
{
    int data1, data2;
    int X::*ptr;

    X() : ptr(&X::data1) {}
};

int main()
{
    X a;      // now, `a.ptr` points to `a.data1`
    X b = a;  //      `b.ptr` points to `b.data1`

    a.ptr = &X::data2;  // now `a.ptr` points to `a.data2`
                        //     `b.ptr` points to `b.data1`
    b = a;              //     `b.ptr` points to `b.data2` too

    // Usage hint:
    int deref = a.*(a.ptr); // gets the field pointed to by a.ptr, from the instance a
        deref = b.*(b.ptr); // gets the field pointed to by b.ptr, from the instance b

    // but of course you could get fancy and do
        deref = a.*(b.ptr); // gets the field pointed to by b.ptr, **but** from the instance a
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
