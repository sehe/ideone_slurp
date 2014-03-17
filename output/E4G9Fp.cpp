// error:	OK
// langId:	44
// langName:	C++11
// langVersion:	gcc-4.8.1
// time:	0
// date:	2013-06-25 00:16:54
// status:	0
// result:	15
// memory:	2988
// signal:	0
// public:	false
// ------------------------------------------------
#include <iostream>
#include <vector>

namespace manips
{
    template <typename Cont, typename Delim=const char*>
    struct PrintManip { 
        PrintManip(Cont const& v, Delim d = ", ") : _v(v), _d(std::move(d)) { }

        Cont const& _v;
        Delim _d;

        friend std::ostream& operator<<(std::ostream& os, PrintManip const& manip) {
            using namespace std;
            auto f = begin(manip._v), l(end(manip._v)); 

            os << "{ ";
            while (f != l)
                if ((os << *f) && (++f != l))
                    os << manip._d;
            return os << " }";
        }
    };

    template <typename T, typename Delim=const char*> 
    manips::PrintManip<T, Delim> print(T const& deduce, Delim delim = ", ") { 
        return { deduce, std::move(delim) }; 
    }
}

using manips::print;

int main()
{
    const char* arr[] = { "hello", "bye" };
    std::cout 
        << "Woot, I can has " << print(arr)
        << " and even: " << print(std::vector<int> { 1,2,3,42 }, ':') << "!\n"
        << "or bizarrely: " << print(arr, print(arr)) << "\n";
}

// ------------------------------------------------
#if 0 // stdin

#endif
#if 0 // stdout
Woot, I can has { hello, bye } and even: { 1:2:3:42 }!
or bizarrely: { hello{ hello, bye }bye }

#endif
#if 0 // stderr

#endif
#if 0 // cmpinfo

#endif
