// error:	OK
// langId:	44
// langName:	C++11
// langVersion:	gcc-4.8.1
// time:	2.73
// date:	2011-11-14 13:05:47
// status:	0
// result:	15
// memory:	2828
// signal:	0
// public:	true
// ------------------------------------------------
#include<iostream>
#include<cstdlib>
#include<cstdint>
#include<time.h>

using namespace std;
typedef uint64_t uint64;
const uint64 m1=0x5555555555555555;
const uint64 m2=0x3333333333333333;
const uint64 m4=0x0f0f0f0f0f0f0f0f;
const uint64 m8=0x00ff00ff00ff00ff;
const uint64 m16=0x0000ffff0000ffff;
const uint64 m32=0x00000000ffffffff;
const uint64 hff=0xffffffffffffffff;
const uint64 h01=0x0101010101010101;

uint64 popcount_1(uint64 x)
{
    x=(x&m1)+((x>>1)&m1);
    x=(x&m2)+((x>>2)&m2);
    x=(x&m4)+((x>>4)&m4);
    x=(x&m8)+((x>>8)&m8);
    x=(x&m16)+((x>>16)&m16);
    x=(x&m32)+((x>>32)&m32);
    return (uint64)x;
}

//This uses fewer arithmetic operations than any other known
//implementation on machines with slow multiplication.
//It uses 17 arithmetic operations.
uint64 popcount_2(uint64 x)
{
    x-=(x>>1)&m1;//put count of each 2 bits into those 2 bits
    x=(x&m2)+((x>>2)&m2);//put count of each 4 bits into those 4 bits
    x=(x+(x>>4))&m4; //put count of each 8 bits into those 8 bits
    x+=x>>8;//put count of each 16 bits into their lowest 8 bits
    x+=x>>16;
    x+=x>>32;
    return x&0x7f;
}
////This uses fewer arithmetic operations than any other known
//implementation on machines with fast multiplication.
//It uses 12 arithmetic operations, one of which is a multiply.
uint64 popcount_3(uint64 x)
{
    x-=(x>>1)&m1;
    x=(x&m2)+((x>>2)&m2);
    x=(x+(x>>4))&m4;
    return (x*h01)>>56;
}
uint64 popcount_4(uint64 x)
{
    uint64  count;
    for(count=0; x; count++)
    {
        x&=x-1;
    }
    return count;
}
uint64 random64()
{
    uint64 r30=RAND_MAX*rand()+rand();
    uint64 s30=RAND_MAX*rand()+rand();
    uint64  t4=rand()&0xf;
    uint64 res=(r30<<34 )+(s30<<4)+t4;
    return res;
}

typedef uint64 (impl)(uint64);

void bench(impl popcount, uint64 x)
{
    clock_t start=clock();
    for(unsigned long it=0; it<=(1ul<<24); ++it) // scaled down for IDEONE
        popcount(x);
    clock_t end=clock();
    cout << (end-start) << endl;
}

int main()
{
    int testnum;

    impl* implementations[] = { popcount_1, popcount_2, popcount_3, popcount_4, 0 };

    uint64 x= random64();
    cout << "Method #1 took "; bench(popcount_1, x);
    cout << "Method #2 took "; bench(popcount_2, x);
    cout << "Method #3 took "; bench(popcount_3, x);
    cout << "Method #4 took "; bench(popcount_4, x);
    return 0;
}


// ------------------------------------------------
#if 0 // stdin

#endif
#if 0 // stdout
Method #1 took 330000
Method #2 took 310000
Method #3 took 250000
Method #4 took 1830000

#endif
#if 0 // stderr

#endif
#if 0 // cmpinfo

#endif
