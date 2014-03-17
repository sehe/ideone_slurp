// error:	OK
// langId:	44
// langName:	C++11
// langVersion:	gcc-4.8.1
// time:	0
// date:	2013-06-25 12:23:05
// status:	0
// result:	15
// memory:	3032
// signal:	0
// public:	false
// ------------------------------------------------
#include <vector>
#include <iostream>

int main()
{
    std::vector<int> a { 1,2,3 },
                     b {9,0,-7};

    auto c = a;
    c.insert(end(c), begin(b), end(b));
    
    for(auto i : c)
       std::cout << i << " ";
}
// ------------------------------------------------
#if 0 // stdin

#endif
#if 0 // stdout
1 2 3 9 0 -7 
#endif
#if 0 // stderr

#endif
#if 0 // cmpinfo

#endif
