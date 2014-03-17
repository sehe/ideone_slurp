// error:	OK
// langId:	44
// langName:	C++11
// langVersion:	gcc-4.8.1
// time:	0
// date:	2011-09-13 22:32:11
// status:	0
// result:	15
// memory:	2956
// signal:	0
// public:	true
// ------------------------------------------------
#include <list>
#include <string>

int main()
{
	std::list<std::string> mylist;
	mylist.push_back("random stuff");
	std::list<std::string>::iterator it;
	it=mylist.begin();
	std::string mystr;
	//and this <strike>doesn't</strike> work:
	mystr=*it;

	return 0;
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
