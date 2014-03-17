// error:	OK
// langId:	44
// langName:	C++11
// langVersion:	gcc-4.8.1
// time:	0
// date:	2011-09-13 07:48:20
// status:	0
// result:	15
// memory:	2964
// signal:	0
// public:	true
// ------------------------------------------------
#include <vector>
#include <iostream>
#include <algorithm>
#include <iterator>

template <typename Containers>
	std::vector<typename Containers::value_type::value_type>
         reduce_minelement(const Containers& containers)
{
	std::vector<typename Containers::value_type::value_type> result;
	result.reserve(containers.size()); // pre-allocate

	for (auto it=containers.begin(); it!=containers.end(); ++it)
		result.push_back(*std::max_element(it->begin(), it->end()));

	return result;
}

static const std::vector<std::vector<int> > data = { 
	   { 52,    1, 93, 74 },
	    { 2,   18, 67, 77 },
	   { 85,   35, -4     },
	   { 48 },
	   { 68,   18, 91,  0 },
};

int main()
{
	auto reduced = reduce_minelement(data);
	std::copy(reduced.begin(), reduced.end(), std::ostream_iterator<int>(std::cout, ", "));

	return 0;
}



// ------------------------------------------------
#if 0 // stdin

#endif
#if 0 // stdout
93, 77, 85, 48, 91, 
#endif
#if 0 // stderr

#endif
#if 0 // cmpinfo

#endif
