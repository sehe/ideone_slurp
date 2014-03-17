// error:	OK
// langId:	1
// langName:	C++ 4.8.1
// langVersion:	gcc-4.8.1
// time:	0
// date:	2013-06-11 13:18:14
// status:	0
// result:	11
// memory:	0
// signal:	0
// public:	true
// ------------------------------------------------
#include <sstream>

int main()
{
    std::istringstream iss(" abcd 1234    -6242          1212");

    std::string s;
    int a, b, c;

    iss >> s >> a >> b >> c;

    std::cout << s << " " << a << " " << b << " " << c << std::endl;
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
prog.cpp:12:5: error: ‘cout’ is not a member of ‘std’

#endif
