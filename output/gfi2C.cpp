// error:	OK
// langId:	44
// langName:	C++11
// langVersion:	gcc-4.8.1
// time:	0
// date:	2011-09-11 20:45:38
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

	struct accu_t
	{
		int sum, product;
		static accu_t& handle(accu_t& a, int i)
		{
			a.sum+=i;
			a.product*=i;
			return a;
		}
	} accum = { 0, 1 };

	accum = std::accumulate(a.begin(), a.end(), accum, &accu_t::handle);

	std::cout << "sum: " << accum.sum << ", product: " << accum.product << std::endl;

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
