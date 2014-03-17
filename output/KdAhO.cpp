// error:	OK
// langId:	1
// langName:	C++ 4.8.1
// langVersion:	gcc-4.8.1
// time:	0.01
// date:	2012-03-16 21:54:28
// status:	0
// result:	15
// memory:	2860
// signal:	0
// public:	false
// ------------------------------------------------
#include <vector>
#include <string>
#include <cstring>
#include <iostream>

#define MAX_A 40
#define MAX_B 3
#define MAX_C 40
#define MAX_D 4

struct Foo {
    char a[ MAX_A ];
    char b[ MAX_B ];
    char c[ MAX_C ];
    char d[ MAX_D ];
};

template <std::ptrdiff_t N>
const char* extractToken(const char* inIt, char (&buf)[N])
{
    if (!inIt || !*inIt)
        return NULL;

    const char* end = strchr(inIt, '@');
    if (end)
    {
        strncpy(buf, inIt, std::min(N, end-inIt));
        return end + 1;
    }
    strncpy(buf, inIt, N);
    return NULL;
}

template <std::ptrdiff_t N>
std::string display(const char (&buf)[N])
{
    std::string result;
    for(size_t i=0; i<N && buf[i]; ++i)
       result += buf[i];
    return result; 
}

int main(int argc, const char *argv[])
{
    std::string input = "abcd@efgh@ijkl@mnop";

    Foo foo = { 0 };

    const char* cursor = input.c_str();
    cursor = extractToken(cursor, foo.a);
    cursor = extractToken(cursor, foo.b);
    cursor = extractToken(cursor, foo.c);
    cursor = extractToken(cursor, foo.d);

    std::cout << "foo.a: '" << display(foo.a) << "'\n";
    std::cout << "foo.b: '" << display(foo.b) << "'\n";
    std::cout << "foo.c: '" << display(foo.c) << "'\n";
    std::cout << "foo.d: '" << display(foo.d) << "'\n";
}

// ------------------------------------------------
#if 0 // stdin

#endif
#if 0 // stdout
foo.a: 'abcd'
foo.b: 'efg'
foo.c: 'ijkl'
foo.d: 'mnop'

#endif
#if 0 // stderr

#endif
#if 0 // cmpinfo

#endif
