// error:	OK
// langId:	44
// langName:	C++11
// langVersion:	gcc-4.8.1
// time:	0
// date:	2012-11-24 13:11:06
// status:	0
// result:	12
// memory:	3080
// signal:	-1
// public:	true
// ------------------------------------------------
#include <thread>
#include <future>
#include <string>

struct arg_t {
    std::string fName;
    std::string str; 
};

int startOver(int i, arg_t args)
{
    return args.fName.size() + args.str.size() + 42;
}

int main()
{
    const std::string arg = "yes";
    arg_t args = { "comBomber", arg };
    auto worker = std::async(startOver, 0, args);
    return worker.get();
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
