// error:	OK
// langId:	44
// langName:	C++11
// langVersion:	gcc-4.8.1
// time:	0
// date:	2012-07-12 15:17:42
// status:	0
// result:	11
// memory:	0
// signal:	0
// public:	true
// ------------------------------------------------
#include <cstring>
#include <cassert>

class Test
{
	struct PrivatePointers
	{
		int  *a = std::null_ptr;
		void *b = std::null_ptr;
	};

	PrivatePointers p;

public:

	Test(): p() 
	{
		assert(p.a == 0);
		assert(p.b == 0);
	};
};

int main()
{
	Test test;
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
prog.cpp:8:13: error: 'null_ptr' is not a member of 'std'
prog.cpp:8:18: error: ISO C++ forbids initialization of member 'a'
prog.cpp:8:18: error: making 'a' static
prog.cpp:8:18: error: invalid in-class initialization of static data member of non-integral type 'int*'
prog.cpp:9:13: error: 'null_ptr' is not a member of 'std'
prog.cpp:9:18: error: ISO C++ forbids initialization of member 'b'
prog.cpp:9:18: error: making 'b' static
prog.cpp:9:18: error: invalid in-class initialization of static data member of non-integral type 'void*'
prog.cpp: In constructor 'Test::Test()':
prog.cpp:18:3: error: 'struct Test::PrivatePointers' has no member named 'a'
prog.cpp:19:3: error: 'struct Test::PrivatePointers' has no member named 'b'

#endif
