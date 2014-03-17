// error:	OK
// langId:	1
// langName:	C++ 4.8.1
// langVersion:	gcc-4.8.1
// time:	0
// date:	2012-02-13 12:34:53
// status:	0
// result:	11
// memory:	0
// signal:	0
// public:	false
// ------------------------------------------------
#include <boost/bind.hpp>
#include <boost/algorithm/string.hpp>
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main(int , char** )
{
    vector<string> test;

    test.push_back("xtest2");
    test.push_back("test3");

    ostream_iterator<string> out_it(cout, "\n");

    remove_copy_if(test.begin(), test.end(), out_it,     
                   boost::bind(boost::algorithm::starts_with<std::string, std::string>, _1, "x"));
}


// ------------------------------------------------
#if 0 // stdin

#endif
#if 0 // stdout

#endif
#if 0 // stderr

#endif
#if 0 // cmpinfo
prog.cpp: In function ‘int main(int, char**)’:
prog.cpp:19: error: no matching function for call to ‘bind(<unresolved overloaded function type>, boost::arg<1>&, const char [2])’

#endif
