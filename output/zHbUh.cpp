// error:	OK
// langId:	44
// langName:	C++11
// langVersion:	gcc-4.8.1
// time:	0
// date:	2011-09-11 21:34:34
// status:	0
// result:	15
// memory:	2960
// signal:	0
// public:	true
// ------------------------------------------------
#include <tuple>
#include <vector>
#include <algorithm>
#include <iostream>

template <typename Tuple, typename T>
Tuple handle(Tuple t, T v)
{
    std::get<0>(t) += v;
    std::get<1>(t) *= v;
    return t;
}

int main()
{
    std::vector<int> a = { 1,2,3,4,5,6,7 };

    for (auto i=1ul << 12; i;)
    {
        auto accum = std::make_tuple(0,1);
        accum = std::accumulate(a.begin(), a.end(), accum, handle<decltype(accum), int>);

        if (!--i)
            std::cout << "sum: " << std::get<0>(accum) << ", product: " << std::get<1>(accum) << std::endl;
    }

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
