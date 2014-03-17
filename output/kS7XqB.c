// error:	OK
// langId:	11
// langName:	C
// langVersion:	gcc-4.8.1
// time:	0
// date:	2013-06-21 22:00:35
// status:	0
// result:	15
// memory:	1788
// signal:	0
// public:	false
// ------------------------------------------------
#include <string.h>
#include <stdio.h>
#include <assert.h>

char* expand_cell_references(const char* f, const char* const l, char* o); /*the magic engine*/
const char* get_cell_value(const char* coordinate_b, const char* coordinate_e);

const char* cells[][4] = {
    /* A       B           C        D                 */
    { "the"  , "lazy"    , "cow"  , "jumped"  }, /* 1 */
    { "over" , "the"     , "quick", "brown"   }, /* 2 */
    { "paper", "packages", "tied" , "up"      }, /* 3 */
    { "with" , "silver"  , "white", "winters" }, /* 4 */
    { "that" , "melt"    , "fox" ,  "springs" }, /* 5 */
};

const char* get_cell_value(const char* coordinate_b, const char* coordinate_e)
{
#ifdef DEBUG
    static const int maxrows = (sizeof(cells)/sizeof(*cells));
    static const int maxcols = (sizeof(cells[0])/sizeof(*cells[0]));
#endif
    size_t col = 0, row = 0;
    const char* it;
    for (it=coordinate_b; it != coordinate_e; ++it)
    {
        if (*it >= 'A' && *it <= 'Z')
            col = 26*col + (*it - 'A');
        if (*it >= '0' && *it <= '9')
            row = 10*row + (*it - '0'); /* or use atoi and friends */
    }
    row--; /* 1-based row nums in Excel */

#ifdef DEBUG
    assert(col>=0 && col < maxcols);
    assert(row>=0 && row < maxrows);
#endif

    return cells[row][col]; /* 1-based indexes in Excel */
}

int main()
{
    const char in[] = "The C2 D2 C5 D1 A2 B2 B1 dog!";

    char out[1024] = {0};
    expand_cell_references(in, in+strlen(in), out);
    puts(out); /* "The quick brown fox jumped over the lazy dog!" */

    return 0;
}

char* expand_cell_references(const char* f, const char* const l, char* o)
{
    enum parser_state {
        other,
        in_coord_col,
        in_coord_row
    } state = other;

    /*temporary storage for coordinates being parsed:*/
    char accum[16] = {0};
    char* accit = accum;
    while (f!=l)
    {
        switch(state) /*dummy, the transitions flow in fallthrough order for now*/
        {
            case other:
                *(accit = accum) = 0; /*reset the accumulator*/
                while (f!=l && !(*f>='A' && *f<='Z'))
                    *o++ = *f++;
                /*fallthrough*/
            case in_coord_col:
                while (f!=l && *f>='A' && *f<='Z')
                    *accit++ = *f++;
                /*fallthrough*/
            case in_coord_row:
                {
                    const char* expanded = accum;
                    if (f!=l && *f>='0' && *f<='9')
                    {
                        while (f!=l && *f>='0' && *f<='9')
                            *accit++ = *f++;
                        expanded = get_cell_value(accum, accit);
                    }
                    else
                    {
                        *accit = 0;
                    }
                    while (*expanded)
                        *o++ = *expanded++;
                    continue; /*state = other;*/
                }
        }
    }
    return o;
}

// ------------------------------------------------
#if 0 // stdin

#endif
#if 0 // stdout
The quick brown fox jumped over the lazy dog!

#endif
#if 0 // stderr

#endif
#if 0 // cmpinfo

#endif
