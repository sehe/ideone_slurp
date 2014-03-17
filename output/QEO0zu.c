// error:	OK
// langId:	11
// langName:	C
// langVersion:	gcc-4.8.1
// time:	0.01
// date:	2012-11-19 03:39:37
// status:	0
// result:	15
// memory:	1676
// signal:	0
// public:	false
// ------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 15

const char* accounts [MAX] = { "John Mayor", "Paula Bean", "Gary S.", "John Mayor" }; 
double amount        [MAX] = { 100.00      , 200.00      , 300.00   , 400.00       }; 
char debitorcredit   [MAX] = { 'd'         , 'd'         , 'c'      , 'c'          }; 

double get_balance_arrays(const char* name)
{
    double total = 0;
    int i;
    for(i=0; i<MAX && accounts[i]; ++i)
    {
        if(0 == strcmp(accounts[i], name))
            switch(debitorcredit[i])
            {
                case 'c': total += amount[i]; break;
                case 'd': total -= amount[i]; break;
                default:
                    puts("Invalid transaction");
                    exit(255);
            }
    }
    return total;
}

typedef struct record
{
    const char* name;
    double amount;    /* fixed point, 3 decimals? */
    char deb_cred;    /* 'd' or 'c' (prefer to use `signed char` for a direct sign? */
} record_t;

record_t transactions[MAX] =
{
    { "John Mayor", 100.00, 'd' },
    { "Paula Bean", 200.00, 'd' },
    { "Gary S."   , 300.00, 'c' },
    { "John Mayor", 400.00, 'c' },
    { 0 } /* sentinel */
};

double get_balance_struct(const char* name)
{
    double total = 0;
    record_t* tx;
    for(tx = transactions; tx->name; ++tx)
    {
        if(0 == strcmp(tx->name, name))
            switch(tx->deb_cred)
            {
                case 'c': total += tx->amount; break;
                case 'd': total -= tx->amount; break;
                default:
                    puts("Invalid transaction");
                    exit(255);
            }
    }
    return total;
}

int main(int argc, const char *argv[])
{
    printf("Balance: %0.02f\n", get_balance_struct("John Mayor"));
    printf("Balance: %0.02f\n", get_balance_arrays("John Mayor"));
    return 0;
}

// ------------------------------------------------
#if 0 // stdin

#endif
#if 0 // stdout
Balance: 300.00
Balance: 300.00

#endif
#if 0 // stderr

#endif
#if 0 // cmpinfo

#endif
