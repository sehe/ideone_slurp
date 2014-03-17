// error:	OK
// langId:	1
// langName:	C++ 4.8.1
// langVersion:	gcc-4.8.1
// time:	5
// date:	2012-01-03 15:05:07
// status:	0
// result:	13
// memory:	7844
// signal:	24
// public:	false
// ------------------------------------------------
#include <iostream>
#include <vector>

int main(int argc, const char *argv[])
{
    typedef bool element;
    std::vector<element> data(40<<20);

    volatile element cumul = data[0];

    for (int j=0; j<1<<9; j++)
    {
#pragma omp parallel for reduction (^: cumul)
        for (int i=0; i<data.size(); i++)
            cumul ^= data[i];
    }

    std::cout << cumul << std::endl;

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

#endif
