// error:	OK
// langId:	44
// langName:	C++11
// langVersion:	gcc-4.8.1
// time:	0
// date:	2012-02-07 23:39:42
// status:	0
// result:	12
// memory:	2960
// signal:	-1
// public:	false
// ------------------------------------------------
#include <deque>
#include <vector>
#include <list>
#include <algorithm>

template <typename Container>
    int test()
{
    Container a;
    for (int i=0; i<100; ++i) a.push_back(i);
    std::reverse(a.begin(), a.end());
    
    a.erase(a.begin()+10);
    a.erase(a.begin()+10);
    a.erase(a.begin()+10);
    a.erase(a.begin()+10);

    return a[53]; // returns 42
}

int main()
{
    int    r = test<std::deque<int> >();  // 42
    return r = test<std::vector<int> >(); // 42
    return 42;
}

// ------------------------------------------------
#if 0 // stdin

#endif
#if 0 // stdout

#endif
#if 0 // stderr

#endif
#if 0 // cmpinfo

#endif
