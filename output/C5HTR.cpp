// error:	OK
// langId:	1
// langName:	C++ 4.8.1
// langVersion:	gcc-4.8.1
// time:	0
// date:	2011-09-19 15:08:33
// status:	0
// result:	15
// memory:	2856
// signal:	0
// public:	true
// ------------------------------------------------
#include <functional>
#include <string>
#include <algorithm>
#include <iostream>

bool pred(const std::string& s)
{
    return s.size() % 2;
}

int main()
{
    std::string data[] = { "hello", "world!" };

    std::cout << std::count_if(data, data+2, 
            pred) << std::endl;

    std::cout << std::count_if(data, data+2, 
            std::ptr_fun(pred) ) << std::endl;

    std::cout << std::count_if(data, data+2, 
            std::not1(std::ptr_fun(pred))) << std::endl;

    return 0;
}
// ------------------------------------------------
#if 0 // stdin

#endif
#if 0 // stdout
1
1
1

#endif
#if 0 // stderr

#endif
#if 0 // cmpinfo

#endif
