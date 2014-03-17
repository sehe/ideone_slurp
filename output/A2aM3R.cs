// error:	OK
// langId:	27
// langName:	C#
// langVersion:	mono-2.8
// time:	0
// date:	2013-03-11 02:42:17
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
prog.cs(2,0): error CS1024: Wrong preprocessor directive
prog.cs(3,0): error CS1024: Wrong preprocessor directive
prog.cs(4,0): error CS1024: Wrong preprocessor directive
prog.cs(5,0): error CS1024: Wrong preprocessor directive
prog.cs(6,0): error CS1024: Wrong preprocessor directive
prog.cs(7,0): error CS1525: Unexpected symbol `int'
prog.cs(15,0): error CS1517: Invalid preprocessor directive
prog.cs(15,0): error CS1025: Single-line comment or end-of-line expected
prog.cs(20,47): warning CS0658: `<operator>' is invalid attribute target. All attributes in this attribute section will be ignored
prog.cs(28,1): error CS8025: Parsing error
Compilation failed: 9 error(s), 1 warnings

#endif
