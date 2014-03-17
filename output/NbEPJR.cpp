// error:	OK
// langId:	44
// langName:	C++11
// langVersion:	gcc-4.8.1
// time:	0
// date:	2013-04-23 12:19:07
// status:	0
// result:	11
// memory:	0
// signal:	0
// public:	true
// ------------------------------------------------
#include <iostream>
#include <vector>
#include <list>
#include <boost/range.hpp>

using namespace std;

template<typename...> struct void_ { using type = void; };
template<typename... T> using Void = typename void_<T...>::type;

template<typename... T> using BoostRangeValue = typename boost::range_value<T...>::type;

//////////////////
template<typename T, typename Sfinae = void>
struct range_value {};

template<typename T>
struct range_value<T, Void<BoostRangeValue<T>>>: BoostRangeValue<T> {};

template<typename... T> using RangeValue = typename range_value<T...>::type;
//////////////////

template <typename T, typename C>
    typename enable_if<std::is_same<T, RangeValue<C>>::value, C>::type 
    concat(C c, T v)
{
    c.insert(end(c), v);
    return c;
}

template <typename R, typename C>
    typename enable_if<
        std::is_same< RangeValue<R>, RangeValue<C>
        >::value, C>::type 
    concat(C c, R const& r)
{
    c.insert(end(c), begin(r), end(r));
    return c;
}

//////////////////
// THIS IS CHEATING...
// template<> struct range_value<int, void> {};

//////////////////
int main()
{
    auto v = concat(vector<int> { 1,2,3 }, list<int> { 4,5,6 });
    for(auto i : v)
        std::cout << i << " ";

    // does not SFINAE?
    v = concat(vector<int> { 1,2,3 }, 42);
}


// ------------------------------------------------
#if 0 // stdin

#endif
#if 0 // stdout

#endif
#if 0 // stderr

#endif
#if 0 // cmpinfo
prog.cpp:4:27: fatal error: boost/range.hpp: No such file or directory
compilation terminated.

#endif
