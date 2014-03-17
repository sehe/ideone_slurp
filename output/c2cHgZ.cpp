// error:	OK
// langId:	44
// langName:	C++11
// langVersion:	gcc-4.8.1
// time:	0
// date:	2012-11-28 23:26:08
// status:	0
// result:	15
// memory:	2880
// signal:	0
// public:	false
// ------------------------------------------------
#include <vector>

template <std::size_t... Is>                struct indices {};
template <std::size_t N, std::size_t... Is> struct build_indices            :  build_indices<N-1, N-1, Is...> {};
template <std::size_t... Is>                struct build_indices<0, Is...>  :  indices<Is...> {};

template <typename... T> void foo(T...)
{
    build_indices<sizeof...(T)> x;
}

int main()
{
    foo(1,2,3,4,5);
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
