// error:	OK
// langId:	44
// langName:	C++11
// langVersion:	gcc-4.8.1
// time:	0
// date:	2012-11-17 23:00:00
// status:	0
// result:	15
// memory:	2928
// signal:	0
// public:	false
// ------------------------------------------------
#include <algorithm>
#include <iostream>

using namespace std;

#define IDEONE_BROKEN_CXX11_SUPPORT
#ifdef IDEONE_BROKEN_CXX11_SUPPORT
template <typename T, size_t N> T* begin(T(&arr)[N]) { return arr;   }
template <typename T, size_t N> T* end  (T(&arr)[N]) { return arr+N; }
#endif
unsigned char data[/*70*1000*1000*/]   = {0,2,1,1,0,2,1,4,2,/*...*/};
unsigned int offsets[/*10*1000*1000*/] = {0,1,2,4,6,7,8,/*...*/};

void do_something_for_data_index(unsigned int data_index)
{
    cout << "visited: " << (int) data[data_index] << " (at index " << data_index << ")\n";
}

void foo(size_t first_data_index, size_t high_data_index)
{
    const auto low  = lower_bound(begin(offsets), end(offsets), first_data_index);
    const auto high = upper_bound(low           , end(offsets), high_data_index);
    for(auto offset_it = low; offset_it != high; ++offset_it)
    {
        do_something_for_data_index(*offset_it);
    }
}

int main()
{
    foo(1,4);
}

// ------------------------------------------------
#if 0 // stdin

#endif
#if 0 // stdout
visited: 2 (at index 1)
visited: 1 (at index 2)
visited: 0 (at index 4)

#endif
#if 0 // stderr

#endif
#if 0 // cmpinfo

#endif
