// error:	OK
// langId:	44
// langName:	C++11
// langVersion:	gcc-4.8.1
// time:	0
// date:	2013-05-15 00:11:43
// status:	0
// result:	11
// memory:	0
// signal:	0
// public:	false
// ------------------------------------------------
#include <iterator>
#include <iostream>

template <typename In, typename Out>
   Out t9_transform(In f, In l, Out out)
{
    auto magic = [](decltype(*f) i) { return '2' + std::min(7, (i - (i >> 4)) / 3); };
    decltype(0+*f) last = ' ';

    for(;f!=l;++f) {
        if (*f>='a' && *f<='z') {
            auto idx = *f - 'a';

            auto digit = magic(idx);
            if (digit == last) *out++ = ' ';
            last = digit;

            static_assert(std::is_signed<decltype(idx)>::value, "difference type is required to be signed here");
            for (auto rep = idx; idx>=0 && digit == magic(idx); --idx)
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
    *t9_transform(std::istreambuf_iterator<char>(std::cin), std::istreambuf_iterator<char>(), out) = '\n';
}

// ------------------------------------------------
#if 0 // stdin
some poetry wouldn't run afoul
#endif
#if 0 // stdout

#endif
#if 0 // stderr

#endif
#if 0 // cmpinfo
prog.cpp: In function ‘int main()’:
prog.cpp:44:95: error: ‘out’ was not declared in this scope
prog.cpp: In instantiation of ‘Out t9_transform(In, In, Out) [with In = __gnu_cxx::__normal_iterator<const char*, std::basic_string<char> >; Out = std::back_insert_iterator<std::basic_string<char> >]’:
prog.cpp:32:70:   required from here
prog.cpp:19:23: warning: unused variable ‘rep’ [-Wunused-variable]
prog.cpp: In instantiation of ‘Out t9_transform(In, In, Out) [with In = __gnu_cxx::__normal_iterator<const char*, std::basic_string<char> >; Out = std::ostream_iterator<char>]’:
prog.cpp:39:96:   required from here
prog.cpp:19:23: warning: unused variable ‘rep’ [-Wunused-variable]

#endif
