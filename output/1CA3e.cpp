// error:	OK
// langId:	44
// langName:	C++11
// langVersion:	gcc-4.8.1
// time:	0
// date:	2012-06-11 15:50:53
// status:	0
// result:	11
// memory:	0
// signal:	0
// public:	true
// ------------------------------------------------
#include <tuple>
#include <unordered_map>

namespace std
{
	template <> struct hash<std::tuple<unsigned, unsigned> > 
	{
		unsigned int operator()(std::tuple<unsigned, unsigned> const& a) const { return ~get<0>(a) + 17*get<1>(a); }
	};
}

int main()
{
	std::unordered_multimap<std::tuple<unsigned, unsigned>, unsigned> map = {
		{ std::make_tuple(/*I*/ 1, /*J*/ 2), /*K*/ 3 },
		{ std::make_tuple(/*I*/ 4, /*J*/ 5), /*K*/ 6 },
		{ std::make_tuple(/*I*/ 7, /*J*/ 8), /*K*/ 9 },
		{ std::make_tuple(/*I*/ 1, /*J*/ 2), /*K*/ 42 }, // duplicate (I,J) ok
	};

	map.emplace(std::make_tuple(/*I*/ 1, /*J*/ 2), /*K*/ 43);
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
prog.cpp:21:6: error: 'class std::unordered_multimap<std::tuple<unsigned int, unsigned int>, unsigned int>' has no member named 'emplace'

#endif
