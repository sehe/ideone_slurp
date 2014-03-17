// error:	OK
// langId:	1
// langName:	C++ 4.8.1
// langVersion:	gcc-4.8.1
// time:	0
// date:	2011-08-22 18:01:50
// status:	0
// result:	15
// memory:	2860
// signal:	0
// public:	false
// ------------------------------------------------
#include <map>
#include <string>
#include <iostream>
using namespace std;

typedef map<int, string> mymap_t;

void somefunction(mymap_t::const_iterator first, mymap_t::const_iterator last)
{
	mymap_t subclone(first, last);

	// use subclone -- it is a mymap_t now :)
	for (mymap_t::iterator it = subclone.begin(); it!=subclone.end(); ++it)
	{
		it->second += '!';
		std::cout << "first = " << it->first << ", second = " << it->second << std::endl;
	}
} 

int main()
{
	mymap_t mymap;
	mymap[1] = "One";
	mymap[2] = "Two";
	mymap[3] = "Three";


	somefunction(mymap.begin(), mymap.end());

	return 0;

}

// ------------------------------------------------
#if 0 // stdin

#endif
#if 0 // stdout
first = 1, second = One!
first = 2, second = Two!
first = 3, second = Three!

#endif
#if 0 // stderr

#endif
#if 0 // cmpinfo

#endif
