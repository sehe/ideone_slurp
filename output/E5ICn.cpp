// error:	OK
// langId:	1
// langName:	C++ 4.8.1
// langVersion:	gcc-4.8.1
// time:	0.01
// date:	2012-05-11 23:26:22
// status:	0
// result:	15
// memory:	2856
// signal:	0
// public:	false
// ------------------------------------------------
#include <algorithm>
#include <string>

struct sort_algo {
    template <typename It>
    void operator()(It f, It l) const { std::sort(f,l); }
};

struct makeheap_algo {
    template <typename It>
    void operator()(It f, It l) const { std::make_heap(f,l); }
};

struct reverse_algo {
    template <typename It>
    void operator()(It f, It l) const { std::reverse(f,l); }
};

template <typename It, typename Algo>
    void benchmark(It begin, It end, Algo algorithm)
{
    for (unsigned long i=0; i < (1ul<<10); ++i)
        algorithm(begin, end); // TODO add timing
}

int main()
{
    std::string hello = "hello world";
    int data[] = { 1, 3, 7, -9, 0 };

    benchmark(hello.begin(), hello.end(), sort_algo());
    benchmark(hello.begin(), hello.end(), makeheap_algo());
    benchmark(hello.begin(), hello.end(), reverse_algo());

    benchmark(data, data+5, sort_algo());
    benchmark(data, data+5, makeheap_algo());
    benchmark(data, data+5, reverse_algo());
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
