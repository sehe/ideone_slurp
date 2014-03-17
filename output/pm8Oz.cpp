// error:	OK
// langId:	44
// langName:	C++11
// langVersion:	gcc-4.8.1
// time:	0
// date:	2012-06-11 17:47:36
// status:	0
// result:	15
// memory:	3020
// signal:	0
// public:	true
// ------------------------------------------------
#include <tuple>
#include <unordered_map>
#include <cassert>
#include <iostream>

struct triplet 
{ 
	unsigned a,b,c;
	bool operator< (triplet const& o) const { return std::tie(a,b,c) < std::tie(o.a,o.b,o.c); }
	bool operator==(triplet const& o) const { return std::tie(a,b,c) ==std::tie(o.a,o.b,o.c); }
};

namespace std {
    template<> struct hash<triplet> {
        unsigned int operator()(triplet const& key) const { 
            return  ~key.a + 17u*key.b + 17u*key.c; // totally made that up, could be better, I suppose
        }
    };
}

static std::ostream& operator<<(std::ostream& os, triplet const& key) {
    return os << '[' << key.a << ',' << key.b << ',' << key.c << ']';
}

int main()
{
    std::unordered_multimap<triplet, double> map;
    
    // insert items dynamically
    map.insert({ triplet{ /*I*/ 1, /*J*/ 2, /*K*/ 3 },  0.1 } );
    map.insert({ triplet{ /*I*/ 4, /*J*/ 5, /*K*/ 6 },  0.2 } );
    map.insert({ triplet{ /*I*/ 7, /*J*/ 8, /*K*/ 9 },  0.3 } );
    map.insert({ triplet{ /*I*/ 1, /*J*/ 2, /*K*/ 0 },  0.4 } ); // duplicate (I,J) ok

    map.insert({ triplet{ /*I*/ 1, /*J*/ 2, /*K*/ 0 }, 0.5 } );

    assert(0 == map.count(triplet {1,5,6}));
    assert(1 == map.count(triplet {4,5,6}));

    auto range = map.equal_range(triplet { 1,2,0 });
    for (auto it=range.first; it!=range.second; ++it)
        std::cout << it->first << ": " << it->second << "\n";
}

// ------------------------------------------------
#if 0 // stdin

#endif
#if 0 // stdout
[1,2,0]: 0.4
[1,2,0]: 0.5

#endif
#if 0 // stderr

#endif
#if 0 // cmpinfo

#endif
