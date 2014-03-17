// error:	OK
// langId:	44
// langName:	C++11
// langVersion:	gcc-4.8.1
// time:	0
// date:	2013-09-27 00:52:05
// status:	0
// result:	15
// memory:	3296
// signal:	0
// public:	false
// ------------------------------------------------
#include <iostream>
#include <vector>

template <class T>
void shellSort(T list [], int size)
{
    using std::swap;

    unsigned gap = size / 2;
    while (gap > 0)
    {
        for (size_t i = 0; i < size - gap; i++)
        {
            if (list[i] > list[i + gap])
            {
                swap(list[i], list[i + gap]);
            }
            for (int j = 0; j < size; j++)
            {
                std::cout << list[j] << " ";
            }
            std::cout << std::endl;
        }
        gap /= 2;
    }

    // bubbleSort(list, size);
}

int main()
{
    int data[] = {  5, 2, 7, 2, 3, 4, 1 };

    shellSort(data, sizeof(data)/sizeof(*data));
}

// ------------------------------------------------
#if 0 // stdin

#endif
#if 0 // stdout
2 2 7 5 3 4 1 
2 2 7 5 3 4 1 
2 2 4 5 3 7 1 
2 2 4 1 3 7 5 
2 2 4 1 3 7 5 
2 2 4 1 3 7 5 
2 2 1 4 3 7 5 
2 2 1 3 4 7 5 
2 2 1 3 4 7 5 
2 2 1 3 4 5 7 

#endif
#if 0 // stderr

#endif
#if 0 // cmpinfo

#endif
