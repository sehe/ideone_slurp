// error:	OK
// langId:	1
// langName:	C++ 4.8.1
// langVersion:	gcc-4.8.1
// time:	0.01
// date:	2012-04-27 12:17:32
// status:	0
// result:	15
// memory:	2724
// signal:	0
// public:	false
// ------------------------------------------------
#include <iostream>
#include <boost/optional.hpp>

struct X
{
	int x;
	boost::optional<X&> parent;
};

int main()
{
	X a, b;
	a.x = 1; b.x = 2;
	b.parent = a;
	std::cout << b.parent->x << "\n";

	a.x = 42;
	std::cout << b.parent->x << "\n";
}

// ------------------------------------------------
#if 0 // stdin

#endif
#if 0 // stdout
1
42

#endif
#if 0 // stderr

#endif
#if 0 // cmpinfo

#endif
