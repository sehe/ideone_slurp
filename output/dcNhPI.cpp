// error:	OK
// langId:	44
// langName:	C++11
// langVersion:	gcc-4.8.1
// time:	3.68
// date:	2013-03-11 02:42:34
// status:	0
// result:	12
// memory:	527360
// signal:	6
// public:	true
// ------------------------------------------------
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <thread>
#include <future>

int main()
{
    std::vector<int> v(1ul<<27);

    auto f(begin(v)), m(f+v.size()/2), l(end(v));
    std::generate(f, l, rand);

#if 0
    auto t1 = std::thread([&] () mutable { std::sort(f,m); } );
    auto t2 = std::thread([&] () mutable { std::sort(m,l); } );
    t1.join();
    t2.join();
#else
    auto f1 = std::async(std::launch::async, [&] () mutable { std::sort(f,m); } );
    auto f2 = std::async(std::launch::async, [&] () mutable { std::sort(m,l); } );
    f1.get();
    f2.get();
#endif

    std::inplace_merge(f,m,l);
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
