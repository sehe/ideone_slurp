// error:	OK
// langId:	1
// langName:	C++ 4.8.1
// langVersion:	gcc-4.8.1
// time:	0
// date:	2011-09-25 20:59:44
// status:	0
// result:	15
// memory:	2732
// signal:	0
// public:	true
// ------------------------------------------------
#include <vector>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <iterator>

static void display(const std::vector<int>& v)
{
    std::copy(v.begin(), v.end(), std::ostream_iterator<int>(std::cout, ",\t"));
    std::cout << std::endl;
}

int main()
{
    std::vector<std::vector<int> > vectors;

    std::string s;
    while (std::getline(std::cin, s))
    {
        std::istringstream iss(s);
        vectors.push_back(std::vector<int>());
        std::copy(std::istream_iterator<int>(iss), std::istream_iterator<int>(), std::back_inserter(vectors.back()));
    }

    std::for_each(vectors.begin(), vectors.end(), display);
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
