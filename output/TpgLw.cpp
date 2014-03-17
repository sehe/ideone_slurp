// error:	OK
// langId:	1
// langName:	C++ 4.8.1
// langVersion:	gcc-4.8.1
// time:	0
// date:	2011-09-03 14:16:35
// status:	0
// result:	15
// memory:	2720
// signal:	0
// public:	true
// ------------------------------------------------
#include <map>
#include <functional>

template <typename T>
	static bool indirectLess(const T* a, const T* b)
{
	if (a==b) 
		return false;
	if (!a)
		return true;
	if (!b)
		return false;
	return std::less<T>()(*a, *b);
}

typedef int T;
typedef int V;

int main()
{
	typedef bool (*cmp_t)(const T*, const T*);

	std::map<T*,V,cmp_t> tsMap(&indirectLess<T>);
}


// ------------------------------------------------
#if 0 // stdin

#endif
#if 0 // stdout

#endif
#if 0 // stderr

#endif
#if 0 // cmpinfo

#endif
