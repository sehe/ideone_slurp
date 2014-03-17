// error:	OK
// langId:	11
// langName:	C
// langVersion:	gcc-4.8.1
// time:	0.02
// date:	2012-11-20 11:58:20
// status:	0
// result:	15
// memory:	1808
// signal:	0
// public:	false
// ------------------------------------------------
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <malloc.h>

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
    char x[20];
    char *y;

    strncpy(x, w, 20);
    y = strdup(w);

    printf("This is the old w: %s\n", w);
    printf("This is the old x: %s\n", x);
    printf("This is the old y: %s\n", y);

    remove_non_alpha(w);
    remove_non_alpha(x);
    remove_non_alpha(y);

    printf("This is the new w: %s\n", w);
    printf("This is the new x: %s\n", x);
    printf("This is the new y: %s\n", y);

    free(y);
    return 0;
}

// ------------------------------------------------
#if 0 // stdin

#endif
#if 0 // stdout
This is the old w: name1234
This is the old x: name1234
This is the old y: name1234
This is the new w: name
This is the new x: name
This is the new y: name

#endif
#if 0 // stderr

#endif
#if 0 // cmpinfo

#endif
