// error:	OK
// langId:	1
// langName:	C++ 4.8.1
// langVersion:	gcc-4.8.1
// time:	0
// date:	2011-10-31 00:31:41
// status:	0
// result:	15
// memory:	2860
// signal:	0
// public:	true
// ------------------------------------------------
#include <iostream>
#include <algorithm>
#include <set>
 
class Solution 
{ 
   public: 
     template<size_t N>
         static size_t distinct (int (&a)[N])
     {
         std::cerr << "DEBUG: size of array: " << N << " elements" << std::endl;
         return std::set<int>(a, a+N).size();
     }

     template<size_t N>
         static size_t distinct_optim(int (&a)[N])
     {
         std::sort(a, a+N);
         int* newend = std::unique(a, a+N);
         return newend - a;
     }
};
 
int main()
{
    int data[] = { 19415, -2611, 12092, -3942, -2535, 12105, 21079, 4660, 3,
        27131, 13647, 24428, 15159, 9029, 24827, -979, 17194, 25102, -3631,
        20914, -3223, 25801, 6652, 26208, -77, 15606, 8764, 1896, 7430, 24323,
        -152, 23805, -4259, 11243, 13367, 23559, 19293, 18581, 1639, 15671,
        7929, 18386, 5168, 13816, 465, 15801, 16750, -3340, -202, 10412, 11068,
        13458, 24304, 14814, 6530, 1178, -974, 12882, 757, 583, 4897, 24541,
        12490, -119, 2240, -4833, 569, 24700, 24522, 8708, 9760, 26837, 26060,
        20914, -3223, 25801, 6652, 26208, -77, 15606, 8764, 1896, 7430, 24323,
        3377, 6972, 25689, 2334, 1567, 21670, 23233, 14711, 4650, -4703, 25057,
        16057, 19488, 14575, 18936, 13346, 2779, 5644, 17165, 4526, 4390,
        9616, 2413, 14459, -1070, -4079, 22126, 9063, 4362, 8182, 24439, 23625,
        7929, 18386, 5168, 13816, 465, 15801, 16750, -3340, -202, 10412, 11068,
        4184, 25930, 24767, 2785, 17361, 18033, 12366, 20548, -3831, -4101,
        16841, -193, 23217, 6351, 19077, 23565, 10482, 4100, 27488, 15956,
        -2577, 7161, 20943, 25708, -2877, 7900, -4564, -3647, 12008, 1648,
        10533 };
 
    // using std::set (max O(n) additional storage)
    std::cout << Solution::distinct(data) << std::endl;
 
    // using std::unique (inplace mutation; no additional storage)
    std::cout << Solution::distinct_optim(data) << std::endl;
}

// ------------------------------------------------
#if 0 // stdin

#endif
#if 0 // stdout
136
136

#endif
#if 0 // stderr

#endif
#if 0 // cmpinfo

#endif
