// error:	OK
// langId:	1
// langName:	C++ 4.8.1
// langVersion:	gcc-4.8.1
// time:	0
// date:	2011-09-16 16:24:20
// status:	0
// result:	15
// memory:	2724
// signal:	0
// public:	true
// ------------------------------------------------
#include <iostream>

struct myclass
{
     bool m_isOk;

     myclass() : m_isOk(true) { }
     operator void* () const { return (void*) (m_isOk? 0x1 : 0x0); }
};

myclass instance;

int main()
{
    if (instance)
        std::cout << "Ok" << std::endl;
    return 0;
}
// ------------------------------------------------
#if 0 // stdin

#endif
#if 0 // stdout
Ok

#endif
#if 0 // stderr

#endif
#if 0 // cmpinfo

#endif
