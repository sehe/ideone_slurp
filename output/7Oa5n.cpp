// error:	OK
// langId:	1
// langName:	C++ 4.8.1
// langVersion:	gcc-4.8.1
// time:	0
// date:	2011-09-30 00:15:28
// status:	0
// result:	15
// memory:	2860
// signal:	0
// public:	true
// ------------------------------------------------
#include <iostream>
#include <algorithm>
#include <map>
 
bool log_copies = false;
struct tester {
    tester(int value) : value(value) {}
    tester(tester const & rhs) : value(rhs.value) {
        if (log_copies)
            std::cout << "tester(tester const &)" << std::endl;
    }
    int value;
};
 
 
typedef std::map< tester, int > map_t;
 
bool operator<( tester const & lhs, tester const & rhs ) {
    return lhs.value < rhs.value;
}
int getAge( map_t::value_type const & p ) {
    return p.second;
}
int getAge2( std::pair<const tester, int> const & p ) {
    return p.second;
}
 
int main() {
    const int count = 10;
    map_t m;
    for ( int i = 0; i < count; ++i ) {
        m[ tester(i) ] = i;
    }
    int array[ count ] = {};
    log_copies = true;
    std::cout << "--------------------start test 1" << std::endl;
    std::transform( m.begin(), m.end(), array, getAge );
    std::cout << "--------------------end test 1" << std::endl;
    std::cout << "--------------------start test 2" << std::endl;
    std::transform( m.begin(), m.end(), array, getAge2 );
    std::cout << "--------------------end test 2" << std::endl;
}

// ------------------------------------------------
#if 0 // stdin

#endif
#if 0 // stdout
--------------------start test 1
--------------------end test 1
--------------------start test 2
--------------------end test 2

#endif
#if 0 // stderr

#endif
#if 0 // cmpinfo

#endif
