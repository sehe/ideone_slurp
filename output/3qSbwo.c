// error:	OK
// langId:	11
// langName:	C
// langVersion:	gcc-4.8.1
// time:	0
// date:	2013-06-26 10:48:31
// status:	0
// result:	0
// memory:	0
// signal:	0
// public:	false
// ------------------------------------------------
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>

char* expand_cell_references(const char* f, const char* const l, char* o); /*the magic engine*/
const char* get_cell_value(const char* coordinate_b, const char* coordinate_e);

static char matris[30][26][302] = {{{0}}};

int main() {
    char vetor[302];
    int lines_read=0;

    //inicia-se o loop
    for(lines_read=0; 
        fgets(vetor, 302, stdin) && strcmp(vetor, "\n") != 0;
        ++lines_read)
    {
        char *ponteiro;
        int column = 0;
        for(ponteiro = strtok(vetor, "\t"); ponteiro != NULL; ponteiro = strtok(NULL, "\t"))
            strcpy(matris[lines_read][column++], ponteiro);
    }

    for(int i = 0; i < lines_read; i++) {
        for(int c = 0; *matris[i][c]; c++) {
            char out[1024]   = {0};
            char value[1024] = {0};
            strncpy(value, matris[i][c], sizeof(value));

            int iterations_left = 10;
            while(iterations_left--)
            {
                expand_cell_references(value, value+strlen(value), out);

                if (!strcmp(value, out))
                    break; // stop when no more expansions occur

                strncpy(value, out, sizeof(value));
            }

            printf((c!=0)?"\t%s":"%s", out); /* Should be fine, really, as long as input fits inside matris */
        }
    }
    return 0;
}

const char* get_cell_value(const char* coordinate_b, const char* coordinate_e)
{
    static const size_t maxrows = (sizeof(matris)/sizeof(*matris));
    static const size_t maxcols = (sizeof(matris[0])/sizeof(*matris[0]));

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

    assert(col>=0 && col < maxcols);
    assert(row>=0 && row < maxrows);

    return matris[row][col]; /* 1-based indexes in Excel */
}

char* expand_cell_references(const char* f, const char* const l, char* o)
{
    enum parser_state {
        other,
        in_formula,
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
                while (f!=l && (*f != '='))
                    *o++ = *f++;
                // replace '=' by space:
                if (f!=l)
                    f++; // or: *o++ = (f++, ' '); // replace by space?
                /*fallthrough*/
            case in_formula:
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
                    state = in_formula; 
                    // once a `=` started a formula, the rest stays a formula,
                    // you could use another condition (e.g. ';') to _end_ a
                    // formula, or limit the allowable formula contents (e.g.
                    // whitespace, '+', '-', '/' etc.)
                }
        }
    }
    *o = '\0';
    return o;
}

// ------------------------------------------------
#if 0 // stdin
1	2	3	4	5	6
=A1	=A2+B1	=C1	=D1	=B2+C2	=E1
A1	A2+B1	C1	D1	B2+C2	E1

#endif
#if 0 // stdout

#endif
#if 0 // stderr

#endif
#if 0 // cmpinfo

#endif
