// error:	OK
// langId:	44
// langName:	C++11
// langVersion:	gcc-4.8.1
// time:	0
// date:	2011-09-16 17:13:01
// status:	0
// result:	11
// memory:	0
// signal:	0
// public:	true
// ------------------------------------------------
#include <vector>
#include <tuple>
#include <string>
#include <iostream>
#include <iterator>
#include <algorithm>

struct Interesting
{
	typedef int T;
	int operator[] (std::tuple<T,T> const&) { return 42; }
};

int main()
{
	Interesting object;

	std::cout << object[{1,4}] << std::endl;
	//std::cout << object["compound", "key"] << std::endl;

	return 0;
}

// ------------------------------------------------
#if 0 // stdin

#endif
#if 0 // stdout

#endif
#if 0 // stderr

#endif
#if 0 // cmpinfo
prog.cpp: In function 'int main()':
prog.cpp:18:22: error: expected primary-expression before '{' token
prog.cpp:18:22: error: expected ']' before '{' token
prog.cpp:18:22: error: expected ';' before '{' token
prog.cpp:18:27: error: expected primary-expression before ']' token
prog.cpp:18:27: error: expected ';' before ']' token

#endif
