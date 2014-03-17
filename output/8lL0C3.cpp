// error:	OK
// langId:	44
// langName:	C++11
// langVersion:	gcc-4.8.1
// time:	0
// date:	2013-08-21 12:07:27
// status:	0
// result:	15
// memory:	3340
// signal:	0
// public:	false
// ------------------------------------------------
template <typename...> struct enum_list;
template <typename Enum, typename... Enums>
struct enum_list<Enum, Enums...> : enum_list<Enums...>
{
    using base_t = enum_list<Enums...>; 
    static constexpr int  base()                           { return 100 * sizeof...(Enums); }
    static constexpr int  unified(Enum value)              { return int(value) + base(); }
    static constexpr Enum separated(int value, Enum dummy) { return static_cast<Enum>(value - base()); }  // plus assertions?
    using base_t::unified;
    using base_t::separated;
};

template <typename Enum>
struct enum_list<Enum>
{
    static constexpr int  base()                 { return 0; }
    static constexpr int  unified(Enum value)              { return int(value); }
    static constexpr Enum separated(int value, Enum dummy) { return static_cast<Enum>(value); }
};

///// example
enum Foo { A, B, C };
enum Bar { D, E, F };

typedef enum_list<Foo, Bar> unifier;

template <typename Unifier = unifier, typename E>
int unify(E value) {
    return Unifier::unified(value);
}

template <typename E, typename Unifier = unifier>
E separate(int value) {
    return Unifier::separated(value, E());
}

#include <iostream>
int
main()
{
    std::cout << unify(B)                      << std::endl;
    std::cout << unify(F)                      << std::endl;
    std::cout << separate<Foo>(101)            << std::endl;
    std::cout << separate<Bar>(1)              << std::endl;
}
// ------------------------------------------------
#if 0 // stdin

#endif
#if 0 // stdout
101
2
1
1

#endif
#if 0 // stderr

#endif
#if 0 // cmpinfo

#endif
