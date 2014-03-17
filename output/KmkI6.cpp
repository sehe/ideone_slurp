// error:	OK
// langId:	1
// langName:	C++ 4.8.1
// langVersion:	gcc-4.8.1
// time:	0.02
// date:	2012-08-29 00:24:14
// status:	0
// result:	15
// memory:	2720
// signal:	0
// public:	false
// ------------------------------------------------
    #define _XOPEN_SOURCE 500
    #include <ftw.h>
    #include <stdio.h>
    
    static int display_info(const char *fpath, const struct stat *sb, int tflag, struct FTW *ftwbuf)
    {
        switch(tflag)
        {
            case FTW_D: case FTW_DP: puts(fpath); break;
        }
        return 0; /* To tell nftw() to continue */
    }
    
    int main(int argc, char *argv[])
    {
        int flags = FTW_DEPTH | FTW_MOUNT | FTW_PHYS;
    
        if (argc>1 && nftw(argv[1], display_info, 20, flags) == -1)
            perror("nftw");
    }
    
// ------------------------------------------------
#if 0 // stdin

#endif
#if 0 // stdout

#endif
#if 0 // stderr

#endif
#if 0 // cmpinfo

#endif
