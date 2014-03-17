// error:	OK
// langId:	44
// langName:	C++11
// langVersion:	gcc-4.8.1
// time:	0
// date:	2013-07-08 09:38:46
// status:	0
// result:	15
// memory:	2896
// signal:	0
// public:	false
// ------------------------------------------------
#include <iostream>
 
template <typename F>
struct Foo {
    Foo(F&& f) : f(std::forward<F>(f)) {}

    template<typename... Arguments>
    void execute(Arguments... args) {
        f(args ...);
    }

  protected:
    F f;
};

template <typename F>
  Foo<F> make_foo(F&& f = F()) { return {f}; }
 
void padd(int a, int b) { std::cout << a + b << std::endl; }
void psub(int a, int b) { std::cout << a - b << std::endl; }
 
int main() {
    auto f = make_foo(padd);
    f.execute(5, 6);

    make_foo(psub).execute(5, 6);
 
    return 0;
}

// ------------------------------------------------
#if 0 // stdin

#endif
#if 0 // stdout
11
-1

#endif
#if 0 // stderr

#endif
#if 0 // cmpinfo

#endif
