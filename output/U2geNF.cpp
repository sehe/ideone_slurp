// error:	OK
// langId:	44
// langName:	C++11
// langVersion:	gcc-4.8.1
// time:	0
// date:	2013-06-17 12:12:16
// status:	0
// result:	15
// memory:	2892
// signal:	0
// public:	false
// ------------------------------------------------
#include <type_traits>

template <int...> struct indexes {};

namespace {
    template<int a, int... other>
        constexpr indexes<a, other...> combine(indexes<other...> deduce);

    template<int a, int b, typename Enable = void> struct expand_span_; // primary

    template<int a, int b>
    struct expand_span_<a, b, typename std::enable_if< (a==b), void >::type> {
        static constexpr indexes<a> dispatch();
    };

    template<int a, int b>
    struct expand_span_<a, b, typename std::enable_if< (a<b), void >::type> {
        static constexpr decltype(combine<a>(expand_span_<a+1, b>::dispatch())) 
            dispatch();
    };

    template<int a, int b>
    constexpr auto expand_span() -> decltype(expand_span_<a,b>::dispatch());
}

template <int a, int b> using span = decltype(expand_span<a,b>());

////////////////////////////////////////////////////////////////
// using indirect template arguments
template<typename> struct indirect_work { };

void test_indirect()
{
    indirect_work<indexes<1,2,3,4>> x;
    indirect_work<span<1,4>>        y;

    x = y; // x and y are of identical types
    static_assert(std::is_same<indexes<1,2,3,4>, span<1,4>>::value, "fact check");
}

////////////////////////////////////////////////////////////////
// using direct template arguments
template<int...> struct direct_work { };

// deduction alias:
template<int... direct> constexpr direct_work<direct...> deduction_helper(indexes<direct...>);
template <typename Idx> using deduce = decltype(deduction_helper(Idx{}));

void test_direct()
{
    direct_work<1,2,3,4> x;
    deduce<indexes<1,2,3,4>> y;
    deduce<span<1,4>> z;

    static_assert(std::is_same<decltype(x), decltype(y)>::value, "fact check");
    static_assert(std::is_same<decltype(x), decltype(z)>::value, "fact check");
}

int main()
{
    test_indirect();
    test_direct();
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
