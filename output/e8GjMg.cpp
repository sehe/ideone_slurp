// error:	OK
// langId:	1
// langName:	C++ 4.8.1
// langVersion:	gcc-4.8.1
// time:	0
// date:	2013-06-11 13:18:39
// status:	0
// result:	15
// memory:	3028
// signal:	0
// public:	true
// ------------------------------------------------
#include <sstream>
#include <iostream>

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
abcd 1234 -6242 1212

#endif
#if 0 // stderr

#endif
#if 0 // cmpinfo

#endif
