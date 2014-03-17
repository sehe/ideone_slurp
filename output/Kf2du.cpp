// error:	OK
// langId:	1
// langName:	C++ 4.8.1
// langVersion:	gcc-4.8.1
// time:	0
// date:	2011-09-29 17:06:47
// status:	0
// result:	15
// memory:	2856
// signal:	0
// public:	true
// ------------------------------------------------
#include <map>
#include <list>
#include <algorithm>
#include <iterator>
#include <vector>

int getage(const std::pair<std::string, int>& pair)
{ 
    return pair.second; 
}

int main()
{
     std::map<std::string, int> agemap;
     agemap["jill"] = 13;
     agemap["jack"] = 31;

     std::list<int> agelist(agemap.size());
     std::transform(agemap.begin(), agemap.end(), agelist.begin(), getage);

     // or:
     std::vector<int> v;
     std::transform(agemap.begin(), agemap.end(), std::back_inserter(v), getage);

     // By popular demand, and just to spell it out:
     int age_array[10];
     std::transform(agemap.begin(), agemap.end(), age_array, getage);

     // or even
     int *dyn_array = new int[agemap.size()];
     std::transform(agemap.begin(), agemap.end(), dyn_array, getage);
     
     delete[] dyn_array;
	
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
