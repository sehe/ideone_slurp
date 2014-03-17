// error:	OK
// langId:	1
// langName:	C++ 4.8.1
// langVersion:	gcc-4.8.1
// time:	0.02
// date:	2011-12-29 03:47:38
// status:	0
// result:	15
// memory:	4940
// signal:	0
// public:	true
// ------------------------------------------------
#include <string>
#include <locale>
#include <iostream>
#include <sstream>

std::string read(std::istream &is)
{
    std::locale loc("");
    
    std::string str;

    char c;
    while(is.get(c))
    {
        str += std::tolower(c, loc);
    }
    
    return str;
}

int main()
{
    std::istringstream ss("WHOA BOY!");
    std::string str = read(ss);
    std::cout << str;
}
// ------------------------------------------------
#if 0 // stdin

#endif
#if 0 // stdout
whoa boy!
#endif
#if 0 // stderr

#endif
#if 0 // cmpinfo

#endif
