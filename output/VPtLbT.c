// error:	OK
// langId:	11
// langName:	C
// langVersion:	gcc-4.8.1
// time:	0
// date:	2013-02-15 09:47:08
// status:	0
// result:	15
// memory:	1828
// signal:	0
// public:	false
// ------------------------------------------------
#include <stdint.h>

typedef struct IP_t
{
    uint8_t data[4];
} IP;

typedef struct IPPair_t
{
    IP source;
    IP destination;
} IPPair;


static const IPPair pair = {{{{ 1, 2, 3, 4 }}}, {{{ 1, 2, 3, 5 }}}};

int main() { return 0; }
// ------------------------------------------------
#if 0 // stdin

#endif
#if 0 // stdout

#endif
#if 0 // stderr

#endif
#if 0 // cmpinfo

#endif
