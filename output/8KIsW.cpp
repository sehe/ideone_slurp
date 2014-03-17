// error:	OK
// langId:	44
// langName:	C++11
// langVersion:	gcc-4.8.1
// time:	0
// date:	2011-12-18 14:11:43
// status:	0
// result:	15
// memory:	2964
// signal:	0
// public:	false
// ------------------------------------------------
#include <iostream>
#include <functional>

int foo(int i)
{
    return i*2;
}

template <typename Ax, typename R, typename... A>
struct Wrap
{
    typedef R (*F)(A...);
    typedef std::function<R(A...)> Ftor;

    Wrap(F f) : _f(f) { }
    Wrap(const Ftor& f) : _f(f) { }

    R operator()(Ax extra, A... a) const
    { return _f(a...); /*just forward*/ }

    Ftor _f;
};

template <typename Ax=int, typename R, typename... A>
std::function<R(Ax, A...)> wrap(R (f)(A...))
{
    return Wrap<Ax,R,A...>(f);
}

template <typename Ax=int, typename R, typename... A>
std::function<R(Ax, A...)> wrap(std::function<R(A...)> functor)
{
    return Wrap<Ax,R,A...>(functor);
}

int main(int argc, const char *argv[])
{
    auto bar = wrap(foo);
    std::function<int(int, int)> barfunc = wrap(foo);

    std::cout << barfunc(-999, 21) << std::endl;

    // wrap the barfunc?
    auto rewrap = wrap(barfunc);
    std::cout << rewrap(-999, -999, 21) << std::endl;

    return 0;
}

// ------------------------------------------------
#if 0 // stdin

#endif
#if 0 // stdout
42
42

#endif
#if 0 // stderr

#endif
#if 0 // cmpinfo

#endif
