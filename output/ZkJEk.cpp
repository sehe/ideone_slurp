// error:	OK
// langId:	44
// langName:	C++11
// langVersion:	gcc-4.8.1
// time:	0
// date:	2012-02-06 20:30:33
// status:	0
// result:	11
// memory:	0
// signal:	0
// public:	false
// ------------------------------------------------
#include <boost/tuple/tuple.hpp>
#include <boost/tuple/tuple_comparison.hpp>
#include <boost/tuple/tuple_io.hpp>
#include <vector>
#include <set>
#include <algorithm>
#include <iostream>

int main()
{
    typedef boost::tuple<int,int> entry;
    typedef std::set<entry> Set;

    const Set A = { 
        entry (3,5),
        entry (3,6),
        entry (6,8),
        entry (8,10),
        entry (4,9) 
    };

    const std::vector<entry> V = { 
        entry (3,5),
        entry (5,10),
        entry (10,3),
        entry (4,10),
    };

    for (auto& el : V)
        std::cout << el << " -> " << std::boolalpha << (A.end()!=A.find(el)) << "\n";
}

// ------------------------------------------------
#if 0 // stdin

#endif
#if 0 // stdout

#endif
#if 0 // stderr

#endif
#if 0 // cmpinfo
prog.cpp:1:33: fatal error: boost/tuple/tuple.hpp: No such file or directory
compilation terminated.

#endif
