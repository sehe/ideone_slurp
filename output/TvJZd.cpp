// error:	OK
// langId:	44
// langName:	C++11
// langVersion:	gcc-4.8.1
// time:	0
// date:	2011-09-11 20:32:45
// status:	0
// result:	15
// memory:	2960
// signal:	0
// public:	true
// ------------------------------------------------
#include <vector>
#include <algorithm>
#include <iostream>

int main()
{
	std::vector<int> a = { 1,2,3,4,5,6,7 };

	int sum=0, product=1;

	std::for_each(a.begin(), a.end(), [&] (int i) { sum+=i; product*=i; });

	std::cout << "sum: " << sum << ", product: " << product << std::endl;

	return 0;
}

// ------------------------------------------------
#if 0 // stdin

#endif
#if 0 // stdout
sum: 28, product: 5040

#endif
#if 0 // stderr

#endif
#if 0 // cmpinfo

#endif
