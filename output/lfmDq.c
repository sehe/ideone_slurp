// error:	OK
// langId:	11
// langName:	C
// langVersion:	gcc-4.8.1
// time:	0
// date:	2011-10-07 19:49:21
// status:	0
// result:	15
// memory:	1720
// signal:	0
// public:	false
// ------------------------------------------------
#include <stdio.h>
char *program = "#include <stdio.h>%cchar *program = %c%s%c;%cint main()%c{%cprintf(program, 10, 34, program, 34, 10, 10, 10, 10, 10, 10);%c    return 0;%c}%c";
//what is this line doing, what is the use of %c and %s and what properties of %c and %s are being used here?
int main()
{
        printf(program, 10, 34, program, 34, 10, 10, 10, 10, 10, 10);
        //what is this print function doing, and how?
        return 0;
}
// ------------------------------------------------
#if 0 // stdin

#endif
#if 0 // stdout
#include <stdio.h>
char *program = "#include <stdio.h>%cchar *program = %c%s%c;%cint main()%c{%cprintf(program, 10, 34, program, 34, 10, 10, 10, 10, 10, 10);%c    return 0;%c}%c";
int main()
{
printf(program, 10, 34, program, 34, 10, 10, 10, 10, 10, 10);
    return 0;
}

#endif
#if 0 // stderr

#endif
#if 0 // cmpinfo

#endif
