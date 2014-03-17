// error:	OK
// langId:	1
// langName:	C++ 4.8.1
// langVersion:	gcc-4.8.1
// time:	0
// date:	2012-11-27 13:43:17
// status:	0
// result:	11
// memory:	0
// signal:	0
// public:	false
// ------------------------------------------------
#include <ratio>

using std::ratio;

template< int n > class Log2;
template<> class Log2< 0> { typedef ratio<0, 1> R; };
template<> class Log2< 1> { typedef ratio<0, 1> R; };

/* To regenerate:
       +4,+39d
	   +2r!python -c 'import math; print "\n".join(["template<> class Log2<\%2d> { typedef ratio<\%13dull, \%13dull> R; };" \% (x, 1.e12*math.log(2,x), 1.e12) for x in range(2,37)])'
*/

template<> class Log2< 2> { typedef ratio<1000000000000ull, 1000000000000ull> R; };
template<> class Log2< 3> { typedef ratio< 630929753571ull, 1000000000000ull> R; };
template<> class Log2< 4> { typedef ratio< 500000000000ull, 1000000000000ull> R; };
template<> class Log2< 5> { typedef ratio< 430676558073ull, 1000000000000ull> R; };
template<> class Log2< 6> { typedef ratio< 386852807234ull, 1000000000000ull> R; };
template<> class Log2< 7> { typedef ratio< 356207187108ull, 1000000000000ull> R; };
template<> class Log2< 8> { typedef ratio< 333333333333ull, 1000000000000ull> R; };
template<> class Log2< 9> { typedef ratio< 315464876785ull, 1000000000000ull> R; };
template<> class Log2<10> { typedef ratio< 301029995663ull, 1000000000000ull> R; };
template<> class Log2<11> { typedef ratio< 289064826317ull, 1000000000000ull> R; };
template<> class Log2<12> { typedef ratio< 278942945651ull, 1000000000000ull> R; };
template<> class Log2<13> { typedef ratio< 270238154427ull, 1000000000000ull> R; };
template<> class Log2<14> { typedef ratio< 262649535037ull, 1000000000000ull> R; };
template<> class Log2<15> { typedef ratio< 255958024809ull, 1000000000000ull> R; };
template<> class Log2<16> { typedef ratio< 250000000000ull, 1000000000000ull> R; };
template<> class Log2<17> { typedef ratio< 244650542118ull, 1000000000000ull> R; };
template<> class Log2<18> { typedef ratio< 239812466568ull, 1000000000000ull> R; };
template<> class Log2<19> { typedef ratio< 235408913366ull, 1000000000000ull> R; };
template<> class Log2<20> { typedef ratio< 231378213159ull, 1000000000000ull> R; };
template<> class Log2<21> { typedef ratio< 227670248696ull, 1000000000000ull> R; };
template<> class Log2<22> { typedef ratio< 224243824217ull, 1000000000000ull> R; };
template<> class Log2<23> { typedef ratio< 221064729457ull, 1000000000000ull> R; };
template<> class Log2<24> { typedef ratio< 218104291985ull, 1000000000000ull> R; };
template<> class Log2<25> { typedef ratio< 215338279036ull, 1000000000000ull> R; };
template<> class Log2<26> { typedef ratio< 212746053553ull, 1000000000000ull> R; };
template<> class Log2<27> { typedef ratio< 210309917857ull, 1000000000000ull> R; };
template<> class Log2<28> { typedef ratio< 208014597676ull, 1000000000000ull> R; };
template<> class Log2<29> { typedef ratio< 205846832460ull, 1000000000000ull> R; };
template<> class Log2<30> { typedef ratio< 203795047090ull, 1000000000000ull> R; };
template<> class Log2<31> { typedef ratio< 201849086582ull, 1000000000000ull> R; };
template<> class Log2<32> { typedef ratio< 199999999999ull, 1000000000000ull> R; };
template<> class Log2<33> { typedef ratio< 198239863170ull, 1000000000000ull> R; };
template<> class Log2<34> { typedef ratio< 196561632232ull, 1000000000000ull> R; };
template<> class Log2<35> { typedef ratio< 194959021893ull, 1000000000000ull> R; };
template<> class Log2<36> { typedef ratio< 193426403617ull, 1000000000000ull> R; };

int main()
{
}


// ------------------------------------------------
#if 0 // stdin

#endif
#if 0 // stdout

#endif
#if 0 // stderr

#endif
#if 0 // cmpinfo
prog.cpp:1:17: error: ratio: No such file or directory
prog.cpp:3: error: ‘std::ratio’ has not been declared
prog.cpp:6: error: ISO C++ forbids declaration of ‘ratio’ with no type
prog.cpp:6: error: expected ‘;’ before ‘<’ token
prog.cpp:7: error: ISO C++ forbids declaration of ‘ratio’ with no type
prog.cpp:7: error: expected ‘;’ before ‘<’ token
prog.cpp:14: error: ISO C++ forbids declaration of ‘ratio’ with no type
prog.cpp:14: error: expected ‘;’ before ‘<’ token
prog.cpp:15: error: ISO C++ forbids declaration of ‘ratio’ with no type
prog.cpp:15: error: expected ‘;’ before ‘<’ token
prog.cpp:16: error: ISO C++ forbids declaration of ‘ratio’ with no type
prog.cpp:16: error: expected ‘;’ before ‘<’ token
prog.cpp:17: error: ISO C++ forbids declaration of ‘ratio’ with no type
prog.cpp:17: error: expected ‘;’ before ‘<’ token
prog.cpp:18: error: ISO C++ forbids declaration of ‘ratio’ with no type
prog.cpp:18: error: expected ‘;’ before ‘<’ token
prog.cpp:19: error: ISO C++ forbids declaration of ‘ratio’ with no type
prog.cpp:19: error: expected ‘;’ before ‘<’ token
prog.cpp:20: error: ISO C++ forbids declaration of ‘ratio’ with no type
prog.cpp:20: error: expected ‘;’ before ‘<’ token
prog.cpp:21: error: ISO C++ forbids declaration of ‘ratio’ with no type
prog.cpp:21: error: expected ‘;’ before ‘<’ token
prog.cpp:22: error: ISO C++ forbids declaration of ‘ratio’ with no type
prog.cpp:22: error: expected ‘;’ before ‘<’ token
prog.cpp:23: error: ISO C++ forbids declaration of ‘ratio’ with no type
prog.cpp:23: error: expected ‘;’ before ‘<’ token
prog.cpp:24: error: ISO C++ forbids declaration of ‘ratio’ with no type
prog.cpp:24: error: expected ‘;’ before ‘<’ token
prog.cpp:25: error: ISO C++ forbids declaration of ‘ratio’ with no type
prog.cpp:25: error: expected ‘;’ before ‘<’ token
prog.cpp:26: error: ISO C++ forbids declaration of ‘ratio’ with no type
prog.cpp:26: error: expected ‘;’ before ‘<’ token
prog.cpp:27: error: ISO C++ forbids declaration of ‘ratio’ with no type
prog.cpp:27: error: expected ‘;’ before ‘<’ token
prog.cpp:28: error: ISO C++ forbids declaration of ‘ratio’ with no type
prog.cpp:28: error: expected ‘;’ before ‘<’ token
prog.cpp:29: error: ISO C++ forbids declaration of ‘ratio’ with no type
prog.cpp:29: error: expected ‘;’ before ‘<’ token
prog.cpp:30: error: ISO C++ forbids declaration of ‘ratio’ with no type
prog.cpp:30: error: expected ‘;’ before ‘<’ token
prog.cpp:31: error: ISO C++ forbids declaration of ‘ratio’ with no type
prog.cpp:31: error: expected ‘;’ before ‘<’ token
prog.cpp:32: error: ISO C++ forbids declaration of ‘ratio’ with no type
prog.cpp:32: error: expected ‘;’ before ‘<’ token
prog.cpp:33: error: ISO C++ forbids declaration of ‘ratio’ with no type
prog.cpp:33: error: expected ‘;’ before ‘<’ token
prog.cpp:34: error: ISO C++ forbids declaration of ‘ratio’ with no type
prog.cpp:34: error: expected ‘;’ before ‘<’ token
prog.cpp:35: error: ISO C++ forbids declaration of ‘ratio’ with no type
prog.cpp:35: error: expected ‘;’ before ‘<’ token
prog.cpp:36: error: ISO C++ forbids declaration of ‘ratio’ with no type
prog.cpp:36: error: expected ‘;’ before ‘<’ token
prog.cpp:37: error: ISO C++ forbids declaration of ‘ratio’ with no type
prog.cpp:37: error: expected ‘;’ before ‘<’ token
prog.cpp:38: error: ISO C++ forbids declaration of ‘ratio’ with no type
prog.cpp:38: error: expected ‘;’ before ‘<’ token
prog.cpp:39: error: ISO C++ forbids declaration of ‘ratio’ with no type
prog.cpp:39: error: expected ‘;’ before ‘<’ token
prog.cpp:40: error: ISO C++ forbids declaration of ‘ratio’ with no type
prog.cpp:40: error: expected ‘;’ before ‘<’ token
prog.cpp:41: error: ISO C++ forbids declaration of ‘ratio’ with no type
prog.cpp:41: error: expected ‘;’ before ‘<’ token
prog.cpp:42: error: ISO C++ forbids declaration of ‘ratio’ with no type
prog.cpp:42: error: expected ‘;’ before ‘<’ token
prog.cpp:43: error: ISO C++ forbids declaration of ‘ratio’ with no type
prog.cpp:43: error: expected ‘;’ before ‘<’ token
prog.cpp:44: error: ISO C++ forbids declaration of ‘ratio’ with no type
prog.cpp:44: error: expected ‘;’ before ‘<’ token
prog.cpp:45: error: ISO C++ forbids declaration of ‘ratio’ with no type
prog.cpp:45: error: expected ‘;’ before ‘<’ token
prog.cpp:46: error: ISO C++ forbids declaration of ‘ratio’ with no type
prog.cpp:46: error: expected ‘;’ before ‘<’ token
prog.cpp:47: error: ISO C++ forbids declaration of ‘ratio’ with no type
prog.cpp:47: error: expected ‘;’ before ‘<’ token
prog.cpp:48: error: ISO C++ forbids declaration of ‘ratio’ with no type
prog.cpp:48: error: expected ‘;’ before ‘<’ token

#endif
