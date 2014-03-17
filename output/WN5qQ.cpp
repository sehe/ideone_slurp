// error:	OK
// langId:	44
// langName:	C++11
// langVersion:	gcc-4.8.1
// time:	0
// date:	2012-02-06 00:51:13
// status:	0
// result:	12
// memory:	2956
// signal:	-1
// public:	false
// ------------------------------------------------
#include <functional>

int main(){
  std::function<int(int)> f = [&f](int i){
    return i == 0? 0 :
           i == 1? 1 :
           f(i-1) + f(i-2);
  };
  return f(5);
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
