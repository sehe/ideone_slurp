// error:	OK
// langId:	44
// langName:	C++11
// langVersion:	gcc-4.8.1
// time:	0
// date:	2012-04-06 16:12:27
// status:	0
// result:	15
// memory:	2828
// signal:	0
// public:	false
// ------------------------------------------------
#include <random>
#include <iostream>

struct mygen
{
    mygen(double low, double high) : dist(low, high) {}
    double operator()()
    {
        return dist(engine);
    }
private:
    std::mt19937 engine;
    std::uniform_real_distribution<> dist;
};

int main()
{
    static mygen instance(18.3, 18.34);
    for(int i=0; i < 10; i++)
    {
        std::cout << " " << instance();
    }
}


// ------------------------------------------------
#if 0 // stdin

#endif
#if 0 // stdout
 18.3054 18.3334 18.3388 18.3088 18.3123 18.3219 18.3075 18.3397 18.3399 18.3387
#endif
#if 0 // stderr

#endif
#if 0 // cmpinfo

#endif
