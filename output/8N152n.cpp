// error:	OK
// langId:	44
// langName:	C++11
// langVersion:	gcc-4.8.1
// time:	0
// date:	2013-09-01 14:21:56
// status:	0
// result:	12
// memory:	3432
// signal:	6
// public:	false
// ------------------------------------------------
#ifndef FOO_H
#define FOO_H

#include <cassert>
#include <vector>
#include <algorithm>

template<typename T>
class Foo {
    std::vector<T> elements;
public:
    Foo(unsigned capacity) : elements() {
        elements.reserve(capacity);
    }

    void Resize() {
        elements.reserve(2*elements.capacity());
    }

    T& Add() {
        if (IsFull())
            Resize();

        assert(Capacity() > Count());

        elements.emplace_back();
        return elements.back();
    }

    ///======   Removes an object from the container.
    void Remove(T const& value) {
        auto match = std::find(begin(elements), end(elements), value);

        if (match != end(elements))
        {
            const auto new_capacity = Capacity()-1;
            elements.erase(match);
            elements.shrink_to_fit();
            elements.reserve(new_capacity);
        }
    }

    unsigned Count() const {
        return elements.size();
    }

    unsigned Capacity() const {
        return elements.capacity();
    }

    bool IsEmpty() const {
        return elements.empty();
    }
    bool IsFull() const {
        return Count() == Capacity();
    }

    T const &operator [](unsigned nIndex) const {
        assert(nIndex < Capacity());
        return elements[nIndex];
    }

    T &operator [](unsigned nIndex) {
        assert(nIndex < Capacity());
        return elements[nIndex];
    }
};

#endif

#include <iostream>

int main()
{
    Foo<int> foo(3);
    assert(foo.IsEmpty());

    foo.Add() = 1;
    foo.Add() = 2;

    assert(3==foo.Capacity());
    assert(!foo.IsEmpty());
    assert(!foo.IsFull());

    foo.Add() = 3;
    assert(3==foo.Capacity());
    assert(foo.IsFull());

    foo.Add() = 4;
    assert(6==foo.Capacity());
    assert(!foo.IsFull());

    foo.Remove(2);
    assert(5==foo.Capacity());
    assert(3==foo.Count());
    assert(!foo.IsFull());

    foo.Add() = 42;
    foo.Add() = -99;
    assert(5==foo.Capacity());
    assert(foo.IsFull());

    foo.Remove(100);
    assert(5==foo.Capacity());
    assert(foo.IsFull());

    foo.Remove(-99);
    assert(4==foo.Capacity());
    assert(foo.IsFull());

    foo.Remove(1);
    assert(3==foo.Capacity());
    assert(foo.IsFull());

    foo.Remove(3);
    assert(2==foo.Capacity());
    assert(foo.IsFull());

    foo.Remove(42);
    assert(1==foo.Capacity());
    assert(foo.IsFull());

    foo.Remove(4);
    assert(0==foo.Capacity());
    assert(foo.IsFull());

    // WHOOPS, 2*Capacity() == 0
    foo.Add() = 31415926;

    for(unsigned i=0; i < foo.Capacity(); i++)
        std::cout << "i:" << i << "\t" << foo[i] << "\n";
}

// ------------------------------------------------
#if 0 // stdin

#endif
#if 0 // stdout

#endif
#if 0 // stderr
prog: prog.cpp:24: T& Foo<T>::Add() [with T = int]: Assertion `Capacity() > Count()' failed.

#endif
#if 0 // cmpinfo

#endif
