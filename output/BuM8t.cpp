// error:	OK
// langId:	1
// langName:	C++ 4.8.1
// langVersion:	gcc-4.8.1
// time:	0.01
// date:	2012-08-22 14:23:32
// status:	0
// result:	15
// memory:	2860
// signal:	0
// public:	false
// ------------------------------------------------
#include <vector>
#include <iostream>

int main() 
{ 
    std::cout << "Your number:"<< std::endl; 

    int num; 
    std::cin >> num; 

    std::vector<int> dizi(num); 

    std::cout << "Size: " << dizi.size() << "\n";
    int element = dizi[0]; // e.g.
}

// ------------------------------------------------
#if 0 // stdin
45
#endif
#if 0 // stdout
Your number:
Size: 45

#endif
#if 0 // stderr

#endif
#if 0 // cmpinfo

#endif
