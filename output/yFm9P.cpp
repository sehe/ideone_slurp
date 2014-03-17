// error:	OK
// langId:	44
// langName:	C++11
// langVersion:	gcc-4.8.1
// time:	0
// date:	2011-12-01 16:40:49
// status:	0
// result:	15
// memory:	2960
// signal:	0
// public:	false
// ------------------------------------------------
#include <chrono>
#include <ctime>
#include <iostream>

using namespace std;

typedef std::chrono::system_clock Clock;

int main()
{
	auto now = Clock::now();
	std::time_t now_c = Clock::to_time_t(now);
	struct tm *parts = std::localtime(&now_c);

	std::cout << 1900 + parts->tm_year  << std::endl;
	std::cout << 1    + parts->tm_mon   << std::endl;
	std::cout <<        parts->tm_mday  << std::endl;

    return 0;
}

// ------------------------------------------------
#if 0 // stdin

#endif
#if 0 // stdout
2011
12
1

#endif
#if 0 // stderr

#endif
#if 0 // cmpinfo

#endif
