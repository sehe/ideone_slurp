// error:	OK
// langId:	44
// langName:	C++11
// langVersion:	gcc-4.8.1
// time:	0
// date:	2011-11-06 20:38:27
// status:	0
// result:	15
// memory:	2828
// signal:	0
// public:	true
// ------------------------------------------------
#include <iostream>

int main()
{
    std::cout << "std::string(\"-I\\\"/path/to/dir\\\" \");" << std::endl;
    std::cout  << R"(std::string("-I\"/path/to/dir\" ");)" << std::endl;
}
// ------------------------------------------------
#if 0 // stdin

#endif
#if 0 // stdout
std::string("-I\"/path/to/dir\" ");
std::string("-I\"/path/to/dir\" ");

#endif
#if 0 // stderr

#endif
#if 0 // cmpinfo

#endif
