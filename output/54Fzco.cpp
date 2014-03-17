// error:	OK
// langId:	44
// langName:	C++11
// langVersion:	gcc-4.8.1
// time:	0
// date:	2013-04-27 14:03:56
// status:	0
// result:	11
// memory:	0
// signal:	0
// public:	true
// ------------------------------------------------
#include <list>
#include <boost/variant/recursive_wrapper.hpp>
#include <boost/spirit/include/qi.hpp>
#include <boost/spirit/include/support_extended_variant.hpp>

struct nil{};

template< typename F > struct expression;
template< typename F >
using expression_list = std::list< expression< F > >;

template< typename F >
using expression_base = boost::spirit::extended_variant<
           nil, 
           F, 
           boost::recursive_wrapper< expression_list< F > 
         > >;

template< typename F > 
struct expression : expression_base<F>
   {
       template <typename I>
           expression(I&& i) 
           : expression_base<F>(std::forward<I>(i)) 
       {}

       expression(std::initializer_list<F> l) 
           : expression_base<F>(expression_list<F>{l}) {}
   };


int main()
{
    auto v = expression<int> (42);
    v = expression<int> { 1, 2, 3, 42 };

    v = 43;
    v = { 2, 3, 4, 43 };
}

// ------------------------------------------------
#if 0 // stdin

#endif
#if 0 // stdout

#endif
#if 0 // stderr

#endif
#if 0 // cmpinfo
prog.cpp:2:47: fatal error: boost/variant/recursive_wrapper.hpp: No such file or directory
compilation terminated.

#endif
