// error:	OK
// langId:	11
// langName:	C
// langVersion:	gcc-4.8.1
// time:	0
// date:	2011-11-12 20:51:44
// status:	0
// result:	15
// memory:	1852
// signal:	0
// public:	true
// ------------------------------------------------
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char** using_strtok(const char* input)
{
    char* str = strdup(input);
    int count = 0;
    int capacity = 10;
    char** result = malloc(capacity*sizeof(*result));

    char* tok=strtok(str," "); 

    while(1)
    {
        if (count >= capacity)
            result = realloc(result, (capacity*=2)*sizeof(*result));

        result[count++] = tok? strdup(tok) : tok;

        if (!tok) break;

        tok=strtok(NULL," ");
    } 

    free(str);
    return result;
}

// not using strtok
char** tokenize(const char* str)
{
    int count = 0;
    int capacity = 10;
    char** result = malloc(capacity*sizeof(*result));

    const char* e=str;
    
    if (e) do 
    {
        const char* s=e;
        e=strpbrk(s," ");

        if (count >= capacity)
            result = realloc(result, (capacity*=2)*sizeof(*result));

        result[count++] = e? strndup(s, e-s) : strdup(s);
    } while (e && *(++e));

    if (count >= capacity)
        result = realloc(result, (capacity+=1)*sizeof(*result));
    result[count++] = 0;

    return result;
}

void test(const char* input, char**(tokenizer)(const char*))
{
    char** tokens = tokenizer(input);
    
    char** it;
    for(it=tokens; it && *it; ++it)
    {
        printf("%s\n", *it);
        free(*it);
    }

    free(tokens);
}

int main ()
{
    test("test string.", using_strtok);
    test("test string.", tokenize);
    return 0;
}

// ------------------------------------------------
#if 0 // stdin

#endif
#if 0 // stdout
test
string.
test
string.

#endif
#if 0 // stderr

#endif
#if 0 // cmpinfo
prog.c: In function ‘tokenize’:
prog.c:47: warning: implicit declaration of function ‘strndup’
prog.c:47: warning: incompatible implicit declaration of built-in function ‘strndup’

#endif
