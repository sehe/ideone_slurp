// error:	OK
// langId:	44
// langName:	C++11
// langVersion:	gcc-4.8.1
// time:	0
// date:	2013-09-01 14:12:47
// status:	0
// result:	0
// memory:	0
// signal:	0
// public:	false
// ------------------------------------------------
#ifndef FOO_H
#define FOO_H

#include <cassert>

template<typename T>
class Foo
{
    T *elements;
    unsigned capacity, items;

    Foo(Foo const&) = delete;
    Foo& operator=(Foo const&) = delete;

public:
    ///======   Constructs the    container from a pre-defined buffer.
    Foo(unsigned nBufferSize) :
        elements(new T[nBufferSize]),
        capacity(nBufferSize),
        items()
    {
    }
    ~Foo()
    {
        delete[] elements;
    }

    unsigned Size() const { return items; }

    // Resizes Container
    void Resize()
    {
        const auto new_capacity = Capacity()*2;
        T *elements2 = new T[new_capacity];

        for(unsigned i=0; i < Capacity(); i++)
        {
            elements2[i] = elements[i];
        }

        Reassign(elements2, new_capacity);
    }

private:
    void Reassign(T* elements2, unsigned new_capacity) noexcept
    {
        { 
            // std::swap() ...
            auto tmp = elements;
            elements = elements2;
            elements2 = tmp;
        }
        delete[] elements2;
        capacity = new_capacity;
    }

public:

    ///======   Adds an element to the container, constructs it and returns
    //it to the caller. ====== Note that the return address needs to be
    //persistent during the lifetime of the object.
    T& Add()
    {
        if(IsFull())
            Resize();

        assert(Capacity() > Size());

        return elements[items++] = T{};
    }

    ///======   Removes an object from the container.
    void Remove(T const& value)
    {
        T* match;
        for(match=elements; match!=elements+items; ++match)
        {
            if (*match==value)
                break;
        }

        if (match == (elements+items))
            return;

        auto new_items = items;
        const auto new_capacity = Capacity()-1;

        T *elements2 = new T[new_capacity];
        T* out = elements2;

        for(T* it=elements; it!=elements+items; ++it)
        {
            if (it==match) new_items--;
            else           *out++ = *it;
        }

        Reassign(elements2, new_capacity);
        items = new_items;
    }

    ///======   Number of elements currently in the container.
    unsigned Count() const
    {
        return items;
    }
    ///======   Max number of elements the container can contain. You can
    //limit the capacity to 65536 elements if this makes your
    //implementation easier.
    unsigned Capacity() const
    {
        return capacity;
    }

    ///======   Is container empty?
    bool IsEmpty() const
    {
        if(items >= 1)
        {
            return false;
        }
        return true;
    }
    ///======   Is container full?
    bool IsFull() const
    {
        return items == Capacity();
    }

    ///======   Returns the n th element of the container [0..Count -1].
    T const &operator [](unsigned nIndex) const
    {
        assert(nIndex < Capacity());
        return elements[nIndex];
    }
    ///======   Returns the n th element of the container [0..Count -1].
    T &operator [](unsigned nIndex)
    {
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
    assert(3==foo.Size());
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

#endif
#if 0 // cmpinfo

#endif
