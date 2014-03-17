// error:	OK
// langId:	44
// langName:	C++11
// langVersion:	gcc-4.8.1
// time:	0
// date:	2012-01-07 03:24:34
// status:	0
// result:	11
// memory:	0
// signal:	0
// public:	true
// ------------------------------------------------
#include <cstdint>

template<uint64_t Cur, uint64_t Goal>
struct adder{
  static uint64_t const sub_goal = (Cur + Goal) / 2;
  static uint64_t const tmp = adder<Cur, sub_goal>::value;
  static uint64_t const value = tmp + adder<sub_goal+1, Goal>::value;
};
 
template<uint64_t Goal>
struct adder<Goal, Goal>{
  static uint64_t const value = Goal;
};
 
template<uint64_t Start>
struct sum_from{
  template<uint64_t Goal>
  struct to{
    template<uint64_t N>
    struct equals;
 
    typedef equals<adder<Start, Goal>::value> result;
  };
};
 
int main(){
  sum_from<1>::to<250000>::result();
}

// ------------------------------------------------
#if 0 // stdin

#endif
#if 0 // stdout

#endif
#if 0 // stderr

#endif
#if 0 // cmpinfo
prog.cpp: In function 'int main()':
prog.cpp:27:35: error: invalid use of incomplete type 'struct sum_from<1ull>::to<250000ull>::result'
prog.cpp:20:12: error: declaration of 'struct sum_from<1ull>::to<250000ull>::result'
g++: Internal error: Segmentation fault (program cc1plus)
Please submit a full bug report.
See <http://gcc.gnu.org/bugs.html> for instructions.

#endif
