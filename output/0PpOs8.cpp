// error:	OK
// langId:	44
// langName:	C++11
// langVersion:	gcc-4.8.1
// time:	0
// date:	2013-09-11 00:05:54
// status:	0
// result:	15
// memory:	3340
// signal:	0
// public:	false
// ------------------------------------------------
#include <stdio.h>
#include <math.h>

/* A palindromic number reads the same both ways. The largest palindrome made
 * from the product of two 2-digit numbers is 9009 = 91 × 99.
 *
 * Find the largest palindrome made from the product of two 3-digit numbers.
*/

unsigned reverse(unsigned i)
{
    unsigned r = 0;
    while (i)
    {
        r *= 10;
        r += i % 10;
        i /= 10;
    }

    return r;
}

int main()
{
    unsigned largest = 0;
    for (unsigned j = 999; j>99; --j)
    {
        for (unsigned k = j; k>99; --k) 
        {
            const unsigned prod = j*k;

            //printf("%d x %d = %d\n", j, k, prod);
            
            const unsigned lhs = prod / 1000;
            const unsigned rhs = prod % 1000;

            if (lhs==reverse(rhs) && prod>largest)
                largest = prod;
        }
    }

    printf("%d\n", largest);
    return 0;
}

// ------------------------------------------------
#if 0 // stdin

#endif
#if 0 // stdout
906609

#endif
#if 0 // stderr

#endif
#if 0 // cmpinfo

#endif
