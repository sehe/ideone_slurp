// error:	OK
// langId:	44
// langName:	C++11
// langVersion:	gcc-4.8.1
// time:	0
// date:	2013-09-24 11:17:42
// status:	0
// result:	15
// memory:	3336
// signal:	0
// public:	false
// ------------------------------------------------
#include <string>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class foo{
  private:
    struct bar{
        double rng;
    };
    struct baz{
        bar abar;
    };
    void foobar();
    static bool cmp(baz a, baz b);
};
bool foo::cmp(baz a, baz b){
        return (a.abar.rng < b.abar.rng);
}

void foo::foobar(){
    std::vector<baz> aVec;
    // fill aVec
    std::sort(aVec.begin(), aVec.end(), cmp);
}

int main()
{
    foo o;
    //o.foobar();
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
