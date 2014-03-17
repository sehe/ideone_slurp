// error:	OK
// langId:	44
// langName:	C++11
// langVersion:	gcc-4.8.1
// time:	0
// date:	2011-11-18 16:29:56
// status:	0
// result:	11
// memory:	0
// signal:	0
// public:	false
// ------------------------------------------------
#include <iostream>
#include <iomanip>
#include <ctime>
#include <chrono>

using namespace std::chrono;

template <typename Clock>
    void dayList(Clock from, Clock till)
{
	for (Clock day=from; day<=till; day += hours(24))
	{
		std::time_t day_c = system_clock::to_time_t(day);
		std::cout << std::put_time(std::localtime(&day_c), "%Y-%M-%D") << '\n';
	}
}

int main()
{
    time_point<system_clock> now = system_clock::now();

	dayList(now, now + hours(190000));
}

// ------------------------------------------------
#if 0 // stdin

#endif
#if 0 // stdout

#endif
#if 0 // stderr

#endif
#if 0 // cmpinfo
prog.cpp: In function 'void dayList(Clock, Clock)':
prog.cpp:14:16: error: 'put_time' is not a member of 'std'

#endif
