// error:	OK
// langId:	44
// langName:	C++11
// langVersion:	gcc-4.8.1
// time:	0
// date:	2012-03-05 02:50:02
// status:	0
// result:	15
// memory:	2960
// signal:	0
// public:	false
// ------------------------------------------------
#include <list>
#include <iterator>
#include <algorithm>
#include <iostream>

int main(int argc, const char *argv[])
{
    std::list<int> l { 1,2,3,4,5,6,7,8 };
    std::list<int> filtered;

    int threshold = 5; // user input?
    std::remove_copy_if(l.begin(), l.end(), std::inserter(filtered, filtered.end()), [threshold] (int i) { return i>threshold; });

    std::copy(filtered.begin(), filtered.end(), std::ostream_iterator<int>(std::cout, ", "));
    std::cout << "\n";

    return 0;
}

// ------------------------------------------------
#if 0 // stdin

#endif
#if 0 // stdout
1, 2, 3, 4, 5, 

#endif
#if 0 // stderr

#endif
#if 0 // cmpinfo

#endif
