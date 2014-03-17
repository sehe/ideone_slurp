// error:	OK
// langId:	1
// langName:	C++ 4.8.1
// langVersion:	gcc-4.8.1
// time:	0
// date:	2011-11-11 09:12:04
// status:	0
// result:	15
// memory:	2724
// signal:	0
// public:	true
// ------------------------------------------------
#include <boost/type_traits.hpp> // or <type_traits> for TR1
#include <iostream>

struct edge {};
struct weighted_edge : edge          { virtual double get_weight() const { return 3.14; } };
struct derived_edge  : weighted_edge { virtual double get_weight() const { return 42; } };

template <typename E, bool is_weighted>
struct edge_weight_impl;

template <typename E>
struct edge_weight_impl<E, false>
{
    typedef int result_type;
    int operator()(const E& e) const { return 1; }
};

template <typename E>
struct edge_weight_impl<E, true>
{
    // typedef decltype(E().weight()) result_type; // c++0x
    typedef double result_type;

    result_type operator()(const E& e) const 
    { 
        return e.get_weight();
    }
};

template <typename E>
    typename edge_weight_impl<E, boost::is_base_of<weighted_edge, E>::value>::result_type 
        get_weight(const E& e)
{
    return edge_weight_impl<E, boost::is_base_of<weighted_edge, E>::value>()(e);
}

int main()
{
    edge e;
    weighted_edge we;
    derived_edge de;

    std::cout << "--- static polymorphism" << std::endl;
    std::cout << "edge:\t"          << get_weight(e) << std::endl;
    std::cout << "weighted_edge:\t" << get_weight(we) << std::endl;
    std::cout << "derived_edge:\t"  << get_weight(de) << std::endl;
    // use some additional enable_if to get rid of this:
    std::cout << "bogus:\t"         << get_weight("bogus") << std::endl;

    std::cout << "\n--- runtime polymorphism" << std::endl;

    edge* ep = &e;
    std::cout << "edge:\t"          << get_weight(*ep) << std::endl;
    weighted_edge* wep = &we;
    std::cout << "weighted_edge:\t" << get_weight(*wep) << std::endl;
    wep = &de;
    std::cout << "bogus:\t"         << get_weight(*wep) << std::endl;

}

// ------------------------------------------------
#if 0 // stdin

#endif
#if 0 // stdout
--- static polymorphism
edge:	1
weighted_edge:	3.14
derived_edge:	42
bogus:	1

--- runtime polymorphism
edge:	1
weighted_edge:	3.14
bogus:	42

#endif
#if 0 // stderr

#endif
#if 0 // cmpinfo

#endif
