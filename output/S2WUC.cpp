// error:	OK
// langId:	44
// langName:	C++11
// langVersion:	gcc-4.8.1
// time:	0
// date:	2012-01-26 12:31:24
// status:	0
// result:	15
// memory:	2968
// signal:	0
// public:	false
// ------------------------------------------------
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

typedef std::vector<int> ivec;

template <class T> bool flag_delete(pair<T,int> a) { return (a.second == 1); }

template <class T> void fun_delete_by_flag(vector<T> &vec_data, const ivec &vec_flag)
{
	size_t n = vec_data.size();
	vector< pair<T,int> > vec;
	vec.reserve(n);
	for ( size_t i = 0; i < n; i += 1 ) 
		vec.push_back(std::make_pair(vec_data[i], vec_flag[i]));

	auto it = remove_if(vec.begin(), vec.end(), flag_delete<T>);
	vec.erase(it);

	n = vec.size();
	vec_data.resize(n);

	for ( size_t i = 0; i < n; i += 1 )
		vec_data[i] = vec[i].first;

	return;
}

template <class T> void simpler(vector<T> &vec_data, const ivec &vec_flag)
{
	T *begin = &vec_data.front();
	size_t newsize = std::distance(begin, 
			std::remove_if(
				begin, begin + vec_data.size(), [&] (T& el) 
				{ 
					return 1 == vec_flag[std::distance(begin, &el)]; 
                                        // or maybe: return vec_flag[&el-begin];
				}));

	vec_data.resize(newsize);
}

int main()
{ 
	vector<std::string> data = { "hello", "world" };
	vector<int> flags = { 0, 1 };

	std::cout << "BEFORE: "; std::copy(data.begin(), data.end(), std::ostream_iterator<std::string>(std::cout, ", ")); std::cout << "\n";
	fun_delete_by_flag(data, flags);
	// simpler(data, flags);
	std::cout << "AFTER:  "; std::copy(data.begin(), data.end(), std::ostream_iterator<std::string>(std::cout, ", ")); std::cout << "\n";
}

// ------------------------------------------------
#if 0 // stdin

#endif
#if 0 // stdout
BEFORE: hello, world, 
AFTER:  hello, 

#endif
#if 0 // stderr

#endif
#if 0 // cmpinfo

#endif
