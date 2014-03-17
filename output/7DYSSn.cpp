// error:	OK
// langId:	44
// langName:	C++11
// langVersion:	gcc-4.8.1
// time:	0
// date:	2013-06-20 17:16:26
// status:	0
// result:	15
// memory:	2980
// signal:	0
// public:	false
// ------------------------------------------------
#include <list>
#include <cassert>

template <typename It>
   It safe_next(It it, std::size_t steps, It end)
{
    while (it!=end && steps--)
        it++;

    return it;
}

int main()
{
    std::list<int> l { 1,2,3,4,5,6,7,8 };
    auto it = begin(l);

    assert(safe_next(it, 3, end(l)) == std::next(it, 3));
    assert(safe_next(it, 30, end(l)) == end(l));
    assert(next(it, std::min(30, std::distance(it, end(l)))) == end(l));
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
