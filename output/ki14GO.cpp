// error:	OK
// langId:	44
// langName:	C++11
// langVersion:	gcc-4.8.1
// time:	0
// date:	2013-05-10 20:51:54
// status:	0
// result:	15
// memory:	2892
// signal:	0
// public:	false
// ------------------------------------------------
#include <iostream>

class X { };

template <class T>
class Mistake {
    public:
        T x;

        Mistake(const T& k) : x(k) { }
        Mistake(const X&) : x(1) { }

        void print() { std::cout << x << std::endl; }
};

template <class T>
Mistake<T> operator+(const Mistake<T>& a, const Mistake<T>& b) {
    return Mistake<T>(a.x + b.x);
}

template <class T, class U>
Mistake<T> operator+(const Mistake<T>& a, U const& b) {
    return a + static_cast<Mistake<T>>(b);
}

template <class T, class U>
Mistake<T> operator+(const U& a, Mistake<T> const& b) {
    return static_cast<Mistake<T>>(a) + b;
}

int main()
{
    X a, b;
    Mistake<int> foo = static_cast<Mistake<int>>(a) + static_cast<Mistake<int>>(b);
    foo = Mistake<int>(a) + b;
    foo = a + Mistake<int>(b);
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
