// error:	OK
// langId:	44
// langName:	C++11
// langVersion:	gcc-4.8.1
// time:	0
// date:	2012-07-13 12:27:48
// status:	0
// result:	11
// memory:	0
// signal:	0
// public:	true
// ------------------------------------------------
#include <string>
#include <iostream>

std::string interface(const char* value, uint32_t length)
{
	std::string s(value, length);
    std::transform(s.begin(), s.end(), [] (char ch) { return std::tolower(ch); });
    return s.substr(0, s.find(";"));
}

int main()
{
     std::cout << interface("Test Case Number 1; ignored text") << '\n';
}

// ------------------------------------------------
#if 0 // stdin

#endif
#if 0 // stdout

#endif
#if 0 // stderr

#endif
#if 0 // cmpinfo
prog.cpp: In function 'std::string interface(const char*, uint32_t)':
prog.cpp:7:5: error: 'transform' is not a member of 'std'
prog.cpp: In function 'int main()':
prog.cpp:13:63: error: too few arguments to function 'std::string interface(const char*, uint32_t)'
prog.cpp:4:13: note: declared here

#endif
