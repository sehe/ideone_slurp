// error:	OK
// langId:	44
// langName:	C++11
// langVersion:	gcc-4.8.1
// time:	0
// date:	2012-03-30 00:02:12
// status:	0
// result:	11
// memory:	0
// signal:	0
// public:	false
// ------------------------------------------------
#include <boost/range/algorithm.hpp>
#include <boost/range/adaptors.hpp>
#include <boost/phoenix.hpp>
#include <vector>

using namespace boost::adaptors;
using boost::phoenix::placeholders::arg1;

int main(int argc, const char *argv[])
{
    using namespace std;
    auto out = ostream_iterator<int>(cout, "\n");

    vector<int> stuff { 1,2,3 };
    boost::copy(stuff | transformed(arg1 * 3), out);
}

// ------------------------------------------------
#if 0 // stdin

#endif
#if 0 // stdout

#endif
#if 0 // stderr

#endif
#if 0 // cmpinfo
prog.cpp:1:37: fatal error: boost/range/algorithm.hpp: No such file or directory
compilation terminated.

#endif
