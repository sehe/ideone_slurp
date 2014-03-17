// error:	OK
// langId:	1
// langName:	C++ 4.8.1
// langVersion:	gcc-4.8.1
// time:	0.02
// date:	2012-05-05 15:32:49
// status:	0
// result:	15
// memory:	2720
// signal:	0
// public:	true
// ------------------------------------------------
#ifndef _popcorn_property_hpp_
#define _popcorn_property_hpp_

namespace popcorn
{
    enum property_flag
    {
        read  = 1 << 0,
        write = 1 << 1,
        readwrite = read | write,
    };

    template<typename T, int flags = 0>
        struct property;

    template<typename T>
        struct property<T, 0> { protected: T value; };

    template<typename T>
        struct property<T, read> : property<T, 0>
        {
            operator T&()             { return this->value; }
            operator const T&() const { return this->value; }
        };

    template<typename T>
        struct property<T, write> : property<T, 0>
        {
            property<T, write>& operator=(T val)     { this->value = val; return *this; }
        };

    template<typename T>
        struct property<T, readwrite> : property<T, read>
        {
            property<T, readwrite>& operator=(T val) { this->value = val; return *this; }
        };
}

#endif

int main()
{
    using namespace popcorn;
    property<int, read> read_only;
    property<int, write> write_only;
    property<int, read | write> read_write;
    property<int> no_access;

    static_cast<int>(read_only);
    write_only = 42;
    static_cast<int>(read_write);
    read_write = 42;
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
