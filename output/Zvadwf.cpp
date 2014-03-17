// error:	OK
// langId:	44
// langName:	C++11
// langVersion:	gcc-4.8.1
// time:	0
// date:	2013-05-14 23:53:27
// status:	0
// result:	15
// memory:	2984
// signal:	0
// public:	false
// ------------------------------------------------
#include <iterator>
#include <iostream>

template <typename In, typename Out>
   Out t9(In f, In l, Out out)
{
    static auto magic = [](decltype(*f) i) { return '2' + std::min(7, (i - (i >> 4)) / 3); };
    decltype(0+*f) last = ' ';

    for(;f!=l;++f) {
        if (*f>='a' && *f<='z') {
            auto idx = *f - 'a';

            auto val = magic(idx);
            if (val == last) *out++ = ' ';
            last = val;

            static_assert(std::is_signed<decltype(idx)>::value, "difference type is required to be signed here");
            for (auto rep = idx; idx>=0 && val == magic(idx); --idx)
                *out++ = val;
        } else
            *out++ = '0';
    }

    return out;
}

int main()
{
    const std::string input = "abcdefghijklmnopqrstuvwxyz";
    t9(begin(input), end(input), std::ostream_iterator<char>(std::cout));
}

// ------------------------------------------------
#if 0 // stdin

#endif
#if 0 // stdout
2 22 2223 33 3334 44 4445 55 5556 66 6667 77 777 77778 88 8889 99 999 9999
#endif
#if 0 // stderr

#endif
#if 0 // cmpinfo

#endif
