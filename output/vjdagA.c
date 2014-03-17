// error:	OK
// langId:	11
// langName:	C
// langVersion:	gcc-4.8.1
// time:	0.02
// date:	2012-11-20 11:45:39
// status:	0
// result:	15
// memory:	1720
// signal:	0
// public:	false
// ------------------------------------------------
#include <stdio.h>
#include <ctype.h>

void remove_non_alpha(char* sz)
{
    char *in, *out;
    for (in=out=sz; in && *in; ++in)
        if (isalpha(*in)) *out++ = *in;
    *out++ = 0;
} 

int main(void)
{
    char w[20]  = "name1234";
    remove_non_alpha(w);
    printf("This is the new one: %s\n", w);
    return 0;
}

// ------------------------------------------------
#if 0 // stdin

#endif
#if 0 // stdout
This is the new one: name

#endif
#if 0 // stderr

#endif
#if 0 // cmpinfo

#endif
