// error:	OK
// langId:	1
// langName:	C++ 4.8.1
// langVersion:	gcc-4.8.1
// time:	0.01
// date:	2011-12-19 15:17:42
// status:	0
// result:	15
// memory:	2724
// signal:	0
// public:	false
// ------------------------------------------------
#include <iostream>

template <typename> class test;

template <> 
class test<int> {
    int y; 
public:     
    test(int k) : y(k) {}     
    friend std::ostream& operator<<(std::ostream& os, const test& t); 
};  

std::ostream& operator<< (std::ostream& os, const test<int>& t) 
{
    return os << t.y;
}  

int main()
{
	test<int> a(42);
	std::cout << a << std::endl;
}

// ------------------------------------------------
#if 0 // stdin

#endif
#if 0 // stdout
42

#endif
#if 0 // stderr

#endif
#if 0 // cmpinfo

#endif
