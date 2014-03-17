// error:	OK
// langId:	1
// langName:	C++ 4.8.1
// langVersion:	gcc-4.8.1
// time:	0
// date:	2011-11-23 09:57:50
// status:	0
// result:	15
// memory:	2724
// signal:	0
// public:	false
// ------------------------------------------------
#include <stdio.h>

int main()
{
    char str[2][3]= { "12", "12"};
    int i;

    for(i=0; i<2; i++)
        printf("%d %s\n", i, str[i]);

    return 0;
}
// ------------------------------------------------
#if 0 // stdin

#endif
#if 0 // stdout
0 12
1 12

#endif
#if 0 // stderr

#endif
#if 0 // cmpinfo

#endif
