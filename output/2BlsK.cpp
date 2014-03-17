// error:	OK
// langId:	1
// langName:	C++ 4.8.1
// langVersion:	gcc-4.8.1
// time:	0
// date:	2011-09-12 23:22:06
// status:	0
// result:	15
// memory:	2860
// signal:	0
// public:	true
// ------------------------------------------------
#include <vector>
#include <iostream>
#include <algorithm>
#include <iterator>

template <typename Containers>
	std::vector<typename Containers::value_type::value_type> reduce_minelement(const Containers& containers)
{
	typedef typename Containers::value_type slice_t;
	typedef typename Containers::const_iterator slice_ci;
	typedef typename slice_t::value_type element_t;
	std::vector<element_t> result;
	result.reserve(containers.size()); // pre-allocated

	for (slice_ci it=containers.begin(); it!=containers.end(); ++it)
	{
		result.push_back(*std::min_element(it->begin(), it->end()));
	}

	return result;
}

typedef int ints_t[6];
static const ints_t s_data[] = { 
	{ 19152,     1, 21193, 17574,  8484, 30333 },
	{ 20189, 18837, 30734,     2, 22440,  3534 },
	    { 3, 26118, 19367, 17877, 24605,  7838 },
	{ 30885, 20135,    -4, 31316, 11838,  8926 },
	{ 26830, 20209, 27286, 16105, 16601, 28304 },
	{ 10208, 28062, 15612, 26270, 19234, 21326 },
	 { 5208, 17473,  3383, 15659, 32494, 24231 },
	{ 31685, 22500, 18860, 21318, 18893, 21385 },
	{ 14295, 17163,  8920, 15986, 13448, 21143 },
	{ 20199,  8954,   599, 17459,  3884,  8634 },
	{ 16768, 20563,  6727, 26305, 11053,  6418 },
	 { 7446,  6853,  5283,  6193, 28291,  4205 },
	{ 27056, 17514,  5359, 29656, 10910,  6034 },
	{ 21984,  1261,  2404, 17644, 25969,  1735 },
	  { 797,  8457, 23584, 29363, 26362, 17383 },
	  { 768, 11018, 14991,     0, 28720,  6159 },
};

int main()
{
	std::vector<std::vector<int> > data;
	
	for (const ints_t *it=s_data; it!=s_data+(sizeof(s_data)/sizeof(*s_data)); ++it)
		data.push_back(std::vector<int>(*it+0, *it+sizeof(*it)/sizeof(**it)));

	std::vector<int> reduced = reduce_minelement(data);

	std::copy(reduced.begin(), reduced.end(), std::ostream_iterator<int>(std::cout, ", "));

	return 0;
}



// ------------------------------------------------
#if 0 // stdin

#endif
#if 0 // stdout
1, 2, 3, -4, 16105, 10208, 3383, 18860, 8920, 599, 6418, 4205, 5359, 1261, 797, 0, 
#endif
#if 0 // stderr

#endif
#if 0 // cmpinfo

#endif
