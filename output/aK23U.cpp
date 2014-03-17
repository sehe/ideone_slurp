// error:	OK
// langId:	1
// langName:	C++ 4.8.1
// langVersion:	gcc-4.8.1
// time:	0
// date:	2012-02-03 13:48:46
// status:	0
// result:	11
// memory:	0
// signal:	0
// public:	false
// ------------------------------------------------
namespace {
    template <typename V>
    /*static*/ int& operator=(int& i, const V& v) { return i = v; }
}

int main()
{
	int x;

        if(operator=(x, 42))
        {
        }
}
// ------------------------------------------------
#if 0 // stdin

#endif
#if 0 // stdout

#endif
#if 0 // stderr

#endif
#if 0 // cmpinfo
prog.cpp:3: error: ‘int&<unnamed>::operator=(int&, const V&)’ must be a nonstatic member function
prog.cpp: In function ‘int main()’:
prog.cpp:10: error: ‘operator=’ not defined

#endif
