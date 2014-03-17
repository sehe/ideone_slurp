// error:	OK
// langId:	11
// langName:	C
// langVersion:	gcc-4.8.1
// time:	0
// date:	2012-05-04 14:45:02
// status:	0
// result:	11
// memory:	0
// signal:	0
// public:	true
// ------------------------------------------------
#define _LARGEFILE64_SOURCE
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
 
#define BLOCK_SIZE 1<<20ul
#define ITERATIONS 1000
 
int main()
{
        char* p;
        FILE* f;
        struct timeval start, end;
        double delta;
        int fd, i, j;
 
        p = malloc(BLOCK_SIZE);
        gettimeofday(&start, NULL);

        // f = fopen("dummy.bin", "w");
        fd = open("dummy.bin", O_BINARY | O_DIRECT | O_CREAT | O_WRONLY);
        f = fdopen(fd, "w");
 
        sync();

        for (i = 0; i < ITERATIONS; ++i)
        {
            for (j = 0; j < BLOCK_SIZE; ++j)
                p[j] = ((char)i)^((char)j);
            fwrite(p, BLOCK_SIZE, 1, f);
        }
        fflush(f);
        fclose(f);
        free(p);

 
        sync();
 
        gettimeofday(&end, NULL);
        delta = ((end.tv_sec * (unsigned int)1e6 +   end.tv_usec) - 
                         (start.tv_sec * (unsigned int)1e6 + start.tv_usec)) / 1.e6;
       
        printf("%.3f MB/s (%i Mb in %.2fs)\n", ITERATIONS / delta, ITERATIONS, delta);
 
        return 0;
}


// ------------------------------------------------
#if 0 // stdin

#endif
#if 0 // stdout

#endif
#if 0 // stderr

#endif
#if 0 // cmpinfo
prog.c: In function ‘main’:
prog.c:22: warning: implicit declaration of function ‘gettimeofday’
prog.c:25: error: ‘O_BINARY’ undeclared (first use in this function)
prog.c:25: error: (Each undeclared identifier is reported only once
prog.c:25: error: for each function it appears in.)
prog.c:25: error: ‘O_DIRECT’ undeclared (first use in this function)
prog.c:34: warning: ignoring return value of ‘fwrite’, declared with attribute warn_unused_result

#endif
