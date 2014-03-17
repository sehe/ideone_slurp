// error:	OK
// langId:	34
// langName:	C99 strict
// langVersion:	gcc-4.8.1
// time:	0.02
// date:	2012-04-06 01:52:10
// status:	0
// result:	12
// memory:	1720
// signal:	4
// public:	true
// ------------------------------------------------
#include <stdio.h>

void swap(int *left, int *right)
{
    int temp = *left;
    *left = *right;
    *right = temp;
}

void sort_bubble(int *data, int size)
{
    for(int i = size - 1; i >= 0; i--)
        for(int j = 0; j < i; j++)
            if(data[j + 1] < data[j])
                swap(&data[j], &data[j + 1]);
}

void internal_sort_quick(int *data, int low, int high)
{
    int first  = low,
        second = high,
        middle = data[(low + high) / 2];

    do
    {
        while(data[first]  < middle) first++;
        while(data[second] > middle) second--;

        if(first <= second)
            swap(&data[first++], &data[second--]);
    }
    while(first <= second);

    if(first < high)
    {
        internal_sort_quick(data, first, high);
    }
    if(low < second)
    {
        internal_sort_quick(data, low, second);
    }
}

void sort_quick(int *data, int size)
{
    internal_sort_quick(data, 0, size-1);
}

void sort_gnome(int *data, int size)
{
    int i = 1,
        j = 2;

    while(i < size)
    {
        if(data[i - 1] <= data[i])
        {
            i = j;
            j = j + 1;
        }
        else
        {
            swap(&data[i - 1], &data[i]);

            i = i - 1;

            if(i == 0)
            {
                i = j;
                j = j + 1;
            }
        }
    }
}

void print_array(const char* algoname, int *data, int size)
{
    printf("\r\nResult of %s Sort:\r\n", algoname);
    for(int i = 0; i < size; i++)
    {
        printf("%i\r\n", data[i]);
    }
}

typedef void(*fptr)(int*, int);
static fptr        algo [] = { sort_bubble, sort_quick, sort_gnome };
static const char* names[] = { "Bubble",    "Quick",    "Gnome"    };

int main(void)
{
    for (int i=0; i<4; ++i)
    {
        int data[] = { 100, 10, 2, 1, 4, 5, 7, 1000 };
        int length = sizeof(data)/sizeof(int);
        algo[i](data, length);
        print_array(names[i], data, length);
    }

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
