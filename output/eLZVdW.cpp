// error:	OK
// langId:	44
// langName:	C++11
// langVersion:	gcc-4.8.1
// time:	0
// date:	2013-03-11 02:56:35
// status:	0
// result:	11
// memory:	0
// signal:	0
// public:	true
// ------------------------------------------------
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <thread>
#include <future>
#include <boost/functional/hash.hpp>
#include <iostream>

int main()
{
    std::vector<int> v(1ul<<27);

    auto const chunk = v.size()/4;

    auto f(begin(v)), l(end(v));
    std::generate(f, l, rand);

#if 1
    std::sort(f,l);
#elif 0
    auto t1 = std::thread([&] () mutable { std::sort(f+chunk*0,f+chunk*1); } );
    auto t2 = std::thread([&] () mutable { std::sort(f+chunk*1,f+chunk*2); } );
    auto t3 = std::thread([&] () mutable { std::sort(f+chunk*2,f+chunk*3); } );
    auto t4 = std::thread([&] () mutable { std::sort(f+chunk*3,l        ); } );
    t1.join();
    t2.join();
    t3.join();
    t4.join();
#else
    auto f1 = std::async(std::launch::async, [&] () mutable { std::sort(f+chunk*0,f+chunk*1); } );
    auto f2 = std::async(std::launch::async, [&] () mutable { std::sort(f+chunk*1,f+chunk*2); } );
    auto f3 = std::async(std::launch::async, [&] () mutable { std::sort(f+chunk*2,f+chunk*3); } );
    auto f4 = std::async(std::launch::async, [&] () mutable { std::sort(f+chunk*3,l        ); } );
    f1.get();
    f2.get();
    f3.get();
    f4.get();
#endif

    std::inplace_merge(f,f+chunk*1,f+chunk*2);
    std::inplace_merge(f+chunk*2,f+chunk*3,l);
    std::inplace_merge(f,f+chunk*2,l);

    auto h = boost::hash_range(f,l);
    std::cout << h;
}

// ------------------------------------------------
#if 0 // stdin

#endif
#if 0 // stdout

#endif
#if 0 // stderr

#endif
#if 0 // cmpinfo
prog.cpp:6:37: fatal error: boost/functional/hash.hpp: No such file or directory
compilation terminated.

#endif
