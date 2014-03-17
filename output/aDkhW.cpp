// error:	OK
// langId:	1
// langName:	C++ 4.8.1
// langVersion:	gcc-4.8.1
// time:	0.01
// date:	2012-03-26 17:28:47
// status:	0
// result:	15
// memory:	2724
// signal:	0
// public:	false
// ------------------------------------------------
#include <iostream>
#include <algorithm>

template <typename T, size_t N> const T* mybegin(const T (&a)[N]) { return a; }    
template <typename T, size_t N> const T* myend  (const T (&a)[N]) { return a+N; }

int main()
{
	const int cloud[] = { 1,2,3,4,-7,999,5,6 };

	std::cout << *std::max_element(mybegin(cloud), myend(cloud)) << '\n';
	std::cout << *std::min_element(mybegin(cloud), myend(cloud)) << '\n';
}

// ------------------------------------------------
#if 0 // stdin

#endif
#if 0 // stdout
999
-7

#endif
#if 0 // stderr

#endif
#if 0 // cmpinfo

#endif
