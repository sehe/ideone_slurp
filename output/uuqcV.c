// error:	OK
// langId:	11
// langName:	C
// langVersion:	gcc-4.8.1
// time:	0.02
// date:	2012-01-10 21:54:46
// status:	0
// result:	15
// memory:	1720
// signal:	0
// public:	true
// ------------------------------------------------
typedef long int __quad_t;

typedef long int __off64_t;
typedef struct { int __val[2]; } __fsid_t;

typedef unsigned long int __fsblkcnt_t;
typedef unsigned long int __fsblkcnt64_t;

typedef unsigned long int __fsfilcnt_t;
typedef unsigned long int __fsfilcnt64_t;

struct statfs
{
    long int f_type;
    long int f_bsize;

    __fsblkcnt_t f_blocks;
    __fsblkcnt_t f_bfree;
    __fsblkcnt_t f_bavail;
    __fsfilcnt_t f_files;
    __fsfilcnt_t f_ffree;

    __fsid_t f_fsid;
    long int f_namelen;
    long int f_frsize;
    long int f_flags;
    long int f_spare[4];
};

struct statfs64
{
    long int f_type;
    long int f_bsize;
    __fsblkcnt64_t f_blocks;
    __fsblkcnt64_t f_bfree;
    __fsblkcnt64_t f_bavail;
    __fsfilcnt64_t f_files;
    __fsfilcnt64_t f_ffree;
    __fsid_t f_fsid;
    long int f_namelen;
    long int f_frsize;
    long int f_flags;
    long int f_spare[4];
};

extern int statfs (__const char *__file, struct statfs *__buf) __attribute__ ((__nonnull__ (1, 2)));
extern int printf(const char *, ...);

int main()
{
    struct statfs buf;
    if (0!= statfs("/", &buf))
        printf("oops\n");
    else
        printf("f_bsize: %ld\n", buf.f_bsize);
    return 0;
}

// ------------------------------------------------
#if 0 // stdin

#endif
#if 0 // stdout
f_bsize: 4096

#endif
#if 0 // stderr

#endif
#if 0 // cmpinfo

#endif
