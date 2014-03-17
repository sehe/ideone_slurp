// error:	OK
// langId:	44
// langName:	C++11
// langVersion:	gcc-4.8.1
// time:	0
// date:	2011-09-29 16:35:32
// status:	0
// result:	15
// memory:	2960
// signal:	0
// public:	true
// ------------------------------------------------
#include <map>
#include <list>
#include <algorithm>
#include <iterator>


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
