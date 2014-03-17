// error:	OK
// langId:	1
// langName:	C++ 4.8.1
// langVersion:	gcc-4.8.1
// time:	0
// date:	2011-10-03 16:16:17
// status:	0
// result:	15
// memory:	2724
// signal:	0
// public:	true
// ------------------------------------------------
#include <iostream>
using namespace std;

template<typename T>
void f(const T& t)
{
    cout << "In template function." << endl;
}

class C
{
public:
    void f() { cout << "In class function." << endl; }
    void g() { using ::f; int i=0; f(i); }
};

int main()
{
    cout << "Test" << endl;
    C c;
    c.g();
    return 0;
}

// ------------------------------------------------
#if 0 // stdin

#endif
#if 0 // stdout
Test
In template function.

#endif
#if 0 // stderr

#endif
#if 0 // cmpinfo

#endif
