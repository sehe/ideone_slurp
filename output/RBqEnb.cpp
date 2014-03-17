// error:	OK
// langId:	44
// langName:	C++11
// langVersion:	gcc-4.8.1
// time:	0
// date:	2012-11-28 19:02:48
// status:	0
// result:	11
// memory:	0
// signal:	0
// public:	false
// ------------------------------------------------
#include <iostream>
#include <boost/function_output_iterator.hpp>
#include <boost/variant.hpp>
#include <string>
#include <map>
#include <algorithm>

typedef std::map<int,   std::string> FirstMap;
typedef std::map<short, double>      SecondMap;

typedef boost::variant<FirstMap::mapped_type, SecondMap::mapped_type> Both;
typedef std::map<long,  Both>        BothMap;

struct CustomOutput {
    CustomOutput(BothMap& ref) : _ref(ref) {}

    template <typename Pair>
    void operator()(const Pair& pair) const { 
        _ref.insert(BothMap::value_type { pair.first, pair.second }); 
    }
    private: BothMap& _ref;
};

struct CustomPred {
    template <typename P1, typename P2>
    bool operator()(const P1& p1, const P2& p2) const { return p1.first < p2.first; }
};

int main()
{
    FirstMap  first_map  { { 1, "aap" }, { 3, "noot" }, { 5, "mies" }  };
    SecondMap second_map { { 1, 1/3.  }, { 2, 2/3.   }, { 4, 4/3.}  };

    BothMap   both_map;

    // iterate over maps union
    std::set_union(
            first_map.begin(), first_map.end(),
            second_map.begin(), second_map.end(),
            boost::make_function_output_iterator(CustomOutput(both_map)),
            CustomPred()
            );

    for (auto& pair : both_map)
        std::cout << pair.first << ":\t" << pair.second << "\n";
}

// ------------------------------------------------
#if 0 // stdin
E:\mingw64>.\a.exe
1:      aap
2:      0.666667
3:      noot
4:      1.33333
5:      mies
#endif
#if 0 // stdout

#endif
#if 0 // stderr

#endif
#if 0 // cmpinfo
prog.cpp:2:46: fatal error: boost/function_output_iterator.hpp: No such file or directory
compilation terminated.

#endif
