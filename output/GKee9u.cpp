// error:	OK
// langId:	44
// langName:	C++11
// langVersion:	gcc-4.8.1
// time:	0
// date:	2013-04-23 00:53:43
// status:	0
// result:	15
// memory:	2892
// signal:	0
// public:	true
// ------------------------------------------------
#include <string>

struct LambdaType
{
    bool operator()() const { return false; }
};

int main()
{
    decltype(&LambdaType::operator()) x = nullptr;
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
