// error:	OK
// langId:	1
// langName:	C++ 4.8.1
// langVersion:	gcc-4.8.1
// time:	0
// date:	2011-10-21 01:01:18
// status:	0
// result:	15
// memory:	2724
// signal:	0
// public:	true
// ------------------------------------------------
#include <cmath>
#include <iostream>

const double pheta = 0.5*(std::sqrt(5)+1);

double fib(unsigned int n)
{
    return (std::pow(pheta, n) - std::pow(1 - pheta, n)) / std::sqrt(5);
}

unsigned int fibo_lowerbound(double N, unsigned min=0, unsigned max=1000)
{
    unsigned newpivot = (min+max)/2;
    if (min==newpivot)
        return newpivot;

    if (fib(newpivot) <= N)
        return fibo_lowerbound(N, newpivot, max);
    else
        return fibo_lowerbound(N, min, newpivot);
}

std::pair<double, double> fibo_range(unsigned int n)
{
    unsigned int lbound = fibo_lowerbound(n);
    return std::make_pair(fib(lbound), fib(lbound+1));
}

void display(unsigned int n)
{
    std::pair<double, double> range = fibo_range(n);
    std::cout << "Fibonacci range wrapping " << n << " is "
              << "[" << (unsigned long long) range.first << ", " << (unsigned long long) range.second << "]"
              << std::endl;
}

int main()
{
    display(1044);
    display(8999913);
    display(7);
    display(67);
}

// ------------------------------------------------
#if 0 // stdin

#endif
#if 0 // stdout
Fibonacci range wrapping 1044 is [987, 1597]
Fibonacci range wrapping 8999913 is [5702887, 9227465]
Fibonacci range wrapping 7 is [5, 8]
Fibonacci range wrapping 67 is [55, 89]

#endif
#if 0 // stderr

#endif
#if 0 // cmpinfo

#endif
