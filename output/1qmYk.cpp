// error:	OK
// langId:	44
// langName:	C++11
// langVersion:	gcc-4.8.1
// time:	0
// date:	2011-09-18 02:28:56
// status:	0
// result:	15
// memory:	2964
// signal:	0
// public:	true
// ------------------------------------------------
#include <iostream>
#include <list>
#include <vector>
#include <numeric>

namespace detail { template <typename T> struct bytes_impl; }

template <typename T> size_t bytes(const T& t)
{
	return detail::bytes_impl<T>()(t);
}

namespace detail
{
	template <typename T>
		struct bytes_impl
	{ 
		template <typename T1=T>
			size_t operator()(const T1& t) const { return sizeof(T1); }
		
		template <typename T1=T, typename V=typename T1::value_type>
			size_t operator()(const T& t) const 
		{
			return sizeof(T) + std::accumulate(t.begin(), t.end(), 0ul, &helper<V>);
		}

		private:
		template <typename V> static size_t helper(size_t accu, const V& v) { return accu + bytes(v); }
	};
}

int main()
{
	char x = char();
	std::string hello = "hello";
	std::string world = "world";

	std::vector<std::string> v;

	std::cout << bytes(hello) << std::endl;
	std::cout << bytes(world) << std::endl;
	std::cout << bytes(v) << std::endl;

	v.push_back(hello);
	v.push_back(world);
	std::cout << bytes(v) << std::endl;

	v.push_back(hello); v.push_back(hello); v.push_back(hello); v.push_back(hello); v.push_back(hello);
	v.push_back(world); v.push_back(world); v.push_back(world); v.push_back(world); v.push_back(world);
	std::cout << bytes(v) << std::endl;

	std::list<std::string> l;
	std::cout << bytes(l) << std::endl;
	l.insert(l.end(), v.begin(), v.end());
	std::cout << bytes(l) << std::endl;

	return 0;
}

// ------------------------------------------------
#if 0 // stdin

#endif
#if 0 // stdout
9
9
12
30
120
8
116

#endif
#if 0 // stderr

#endif
#if 0 // cmpinfo

#endif
