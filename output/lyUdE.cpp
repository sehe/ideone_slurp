// error:	OK
// langId:	1
// langName:	C++ 4.8.1
// langVersion:	gcc-4.8.1
// time:	0.01
// date:	2012-10-15 09:54:07
// status:	0
// result:	15
// memory:	2680
// signal:	0
// public:	false
// ------------------------------------------------
#include <string.h>
#include <stdio.h>
#include <math.h>

void print_helper(int cur, int max, char* buf)
{
    sprintf(buf+strlen(buf), "%d", cur);
    puts(buf);
    if (cur<max) 
        print_helper(cur+1, max, buf);
}

void printem(int max)
{
    char buf[(int) (log(max)/log(10)*max+1)];
    buf[0] = 0;

    print_helper(1, max, buf);
}

int main()
{
    printem(14);
    return 0;
}

// ------------------------------------------------
#if 0 // stdin

#endif
#if 0 // stdout
1
12
123
1234
12345
123456
1234567
12345678
123456789
12345678910
1234567891011
123456789101112
12345678910111213
1234567891011121314

#endif
#if 0 // stderr

#endif
#if 0 // cmpinfo

#endif
