// error:	OK
// langId:	44
// langName:	C++11
// langVersion:	gcc-4.8.1
// time:	0
// date:	2013-05-15 00:15:41
// status:	0
// result:	15
// memory:	2992
// signal:	0
// public:	false
// ------------------------------------------------
#include <iterator>
#include <iostream>

template <typename In, typename Out>
   Out t9_transform(In f, In l, Out out)
{
    auto magic = [](decltype(*f) i) { return '2' + std::min(7, (i - (i >> 4)) / 3); };
    decltype(0+*f) previous = 0;

    for(;f!=l;++f) {
        if (*f>='a' && *f<='z') {
            auto idx = *f - 'a';

            auto digit = magic(idx);
            if (digit == previous) *out++ = ' ';
            previous = digit;

            static_assert(std::is_signed<decltype(idx)>::value, "difference type is required to be signed here");
            for (; idx>=0 && digit == magic(idx); --idx)
                *out++ = digit;
        } else
            *out++ = '0';
    }

    return out;
}

std::string t9(std::string const& input)
{
    std::string result;
    // result.reserve(2*input.size());
    t9_transform(begin(input), end(input), std::back_inserter(result));
    return result;
}

int main()
{
    const std::string input = "abcdefghijklmnopqrstuvwxyz";
    auto output = t9_transform(begin(input), end(input), std::ostream_iterator<char>(std::cout));

    std::cout << std::endl << t9("hello world!") << std::endl;

    // or, how about translating all of stdin to stdout, in streaming mode?
    *t9_transform(std::istreambuf_iterator<char>(std::cin), std::istreambuf_iterator<char>(), output) = '\n';
}

// ------------------------------------------------
#if 0 // stdin
some poetry wouldn't be remiss
#endif
#if 0 // stdout
2 22 2223 33 3334 44 4445 55 5556 66 6667 77 777 77778 88 8889 99 999 9999
4433555 5556660966677755530
7777666 633076663387779990 966688555366080223307773364447777 7777

#endif
#if 0 // stderr

#endif
#if 0 // cmpinfo

#endif
