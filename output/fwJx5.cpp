// error:	OK
// langId:	44
// langName:	C++11
// langVersion:	gcc-4.8.1
// time:	0
// date:	2012-07-13 12:30:15
// status:	0
// result:	15
// memory:	3016
// signal:	0
// public:	true
// ------------------------------------------------
#include <string>
#include <iostream>
#include <algorithm>

std::string interface(const char* value, uint32_t length)
{
	std::string s(value, length);
    std::transform(s.begin(), s.end(), s.begin(), [] (char ch) { return std::tolower(ch); });
    return s.substr(0, s.find(";"));
}

int main()
{
     std::cout << interface("Test Case Number 1; ignored text", 32) << '\n';
}

// ------------------------------------------------
#if 0 // stdin

#endif
#if 0 // stdout
test case number 1

#endif
#if 0 // stderr

#endif
#if 0 // cmpinfo

#endif
