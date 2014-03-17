// error:	OK
// langId:	44
// langName:	C++11
// langVersion:	gcc-4.8.1
// time:	0
// date:	2013-10-25 22:47:21
// status:	0
// result:	15
// memory:	3336
// signal:	0
// public:	false
// ------------------------------------------------
template <typename T> struct X
{
    T v;

    void foo();
};

typedef X<int> SomeTypedef;

#if 1
template <typename T> void X<T>::foo() {
    //
}
#else
template<> void SomeTypedef::foo() {
    //
}
#endif


int main()
{
    SomeTypedef a;
    a.foo();
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
