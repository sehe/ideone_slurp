// error:	OK
// langId:	44
// langName:	C++11
// langVersion:	gcc-4.8.1
// time:	0
// date:	2012-11-30 00:38:48
// status:	0
// result:	11
// memory:	0
// signal:	0
// public:	false
// ------------------------------------------------
#include <boost/lexical_cast.hpp>

template<typename T>
T atot(const char *s)
{
    return boost::lexical_cast<T>(s);
}

int main()
{
    auto i = atot<int>("3");
	auto d = atot<double>("-INF");
	auto f = atot<double>("314e-2");
	auto ul = atot<unsigned long>("65537");
}

// ------------------------------------------------
#if 0 // stdin

#endif
#if 0 // stdout

#endif
#if 0 // stderr

#endif
#if 0 // cmpinfo
prog.cpp:1:34: fatal error: boost/lexical_cast.hpp: No such file or directory
compilation terminated.

#endif
