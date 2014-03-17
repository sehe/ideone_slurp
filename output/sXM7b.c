// error:	OK
// langId:	11
// langName:	C
// langVersion:	gcc-4.8.1
// time:	0
// date:	2011-11-03 02:01:07
// status:	0
// result:	15
// memory:	1852
// signal:	0
// public:	true
// ------------------------------------------------
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// int alpha_range(char c) { return 0 != strchr("abcdefghijklmnopqrstuvwxyz", c); }
// int digit_range(char c) { return 0 != strchr("0123456789", c); }

int alpha_range(char c) { return (c>='a') && (c<='z'); }
int digit_range(char c) { return (c>='0') && (c<='9'); }

char* expand(const char* s)
{
    char buf[2048];

    const char* in  = s;
          char* out = buf;

    // parser state
    int (*predicate)(char) = 0; // either: NULL (free state), alpha_range (in alphabetic range), digit_range (in digit range)
    char lower=0,upper=0;       // tracks lower and upper bound of character ranges in the range parsing states

    // init
    *out = 0;

    while (*in)
    {
        if (!predicate)
        {
            // free parsing state
            if (alpha_range(*in) && (in[1] == '-') && alpha_range(in[2]))
            {
                lower = upper = *in++;
                predicate = &alpha_range;
            }
            else if (digit_range(*in) && (in[1] == '-') && digit_range(in[2]))
            {
                lower = upper = *in++;
                predicate = &digit_range;
            } 
            else *out++ = *in;
        } else
        { 
            // in a range
            if (*in < lower) lower = *in;
            if (*in > upper) upper = *in;

            if (in[1] == '-' && predicate(in[2])) 
                in++; // more coming
            else
            {
                // end of range mode, dump expansion
                char c;
                for (c=lower; c<=upper; *out++ = c++);
                predicate = 0;
            }
        }
        in++;
    }

    *out = 0; // null-terminate buf
    return strdup(buf);
}

void dotest(const char* const input)
{
    char* ex = expand(input);
    printf("input : '%s'\noutput: '%s'\n\n", input, ex);

    if (ex)
        free(ex);
}

int main (int argc, char *argv[])
{
    dotest("a-z or 0-9 or a-b-c or a-z0-9"); // from the original post
    dotest("This is some e-z test in 5-7 steps; this works: a-b-c. This works too: b-k-c-e. Likewise 8-4-6"); // from my C++ answer
    dotest("-x-s a-9 9- a-k-9 9-a-c-7-3"); // assorted torture tests

    return 0;
}

// ------------------------------------------------
#if 0 // stdin

#endif
#if 0 // stdout
input : 'a-z or 0-9 or a-b-c or a-z0-9'
output: 'abcdefghijklmnopqrstuvwxyz or 0123456789 or abc or abcdefghijklmnopqrstuvwxyz0123456789'

input : 'This is some e-z test in 5-7 steps; this works: a-b-c. This works too: b-k-c-e. Likewise 8-4-6'
output: 'This is some efghijklmnopqrstuvwxyz test in 567 steps; this works: abc. This works too: bcdefghijk. Likewise 45678'

input : '-x-s a-9 9- a-k-9 9-a-c-7-3'
output: '-stuvwx a-9 9- abcdefghijk-9 9-abc-34567'


#endif
#if 0 // stderr

#endif
#if 0 // cmpinfo

#endif
