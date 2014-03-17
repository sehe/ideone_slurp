// error:	OK
// langId:	44
// langName:	C++11
// langVersion:	gcc-4.8.1
// time:	0
// date:	2013-07-05 04:03:46
// status:	0
// result:	11
// memory:	0
// signal:	0
// public:	false
// ------------------------------------------------
#include <boost/fusion/adapted.hpp>
#include <boost/spirit/include/qi.hpp>
#include <boost/iostreams/device/mapped_file.hpp>

namespace qi = boost::spirit::qi;

#if 1
    struct float3
    {
        float x,y,z;
    };

    BOOST_FUSION_ADAPT_STRUCT(float3, (float, x)(float, y)(float, z))

    typedef std::vector<float3> data_t;
#else
    // there is no speed difference when parsing into a straight container
    // (only works with the spirit implementation)
    typedef std::vector<float> data_t;
#endif

double scan_float(const char* str, size_t& off, size_t len);

int main()
{
#if 0
    std::cin.unsetf(std::ios::skipws);
    std::istreambuf_iterator<char> f_(std::cin), l_;

    const std::vector<char> v(f_, l_);
    auto f = v.data(), l = f+v.size();
#elif 1
    boost::iostreams::mapped_file mmap(
            "input.txt", 
            boost::iostreams::mapped_file::readonly);
    auto f = mmap.const_data();
    auto l = f + mmap.size();
#endif

    data_t data;
    data.reserve(11000000);

#if 0
    using namespace qi;
    bool ok = phrase_parse(f,l,(double_ > double_ > double_) % eol, blank, data);
    if (ok)   
        std::cout << "parse success\n";
    else 
        std::cerr << "parse failed: '" << std::string(f,l) << "'\n";

    if (f!=l) std::cerr << "trailing unparsed: '" << std::string(f,l) << "'\n";
#elif 0
    errno = 0;
    char* next = nullptr;
    float3 tmp;
    while (errno == 0 && f && f<(l-12) ) {
        tmp.x = strtod(f, &next); f = next;
        tmp.y = strtod(f, &next); f = next;
        tmp.z = strtod(f, &next); f = next;
        data.push_back(tmp);
    }
#elif 0
    FILE* file = fopen("input.txt", "r");
    if (NULL == file) {
        printf("Failed to open 'input.txt'");
        return 255;
    }
    float3 tmp;
    do {
        int nItemsRead = fscanf(file,"%f %f %f\n", &tmp.x, &tmp.y, &tmp.z);
        if (3 != nItemsRead)
            break;
        data.push_back(tmp);
    } while (1);
#else
    size_t len = std::distance(f,l);
    const char* str = f;
    float3 tmp;
    for (size_t i=0; i<len;)
    {
        while (i<len && isspace(str[i])) ++i;
        tmp.x = scan_float(str, i, len);
        while (i<len && isspace(str[i])) ++i;
        tmp.y = scan_float(str, i, len);
        while (i<len && isspace(str[i])) ++i;
        tmp.z = scan_float(str, i, len);

        if (i<len) // requires at least trailing newline for now
            data.push_back(tmp);
        //if (0 == (data.size()%1000)) std::cout << "now at " << data.size() << "/11000000\n";
    }
#endif

    std::cout << "data.size():   " << data.size() << "\n";
}

double scan_float(const char* str, size_t& off, size_t len)
{
    static const double bases[13] = {
        0.0, 10.0, 100.0, 1000.0, 10000.0,
        100000.0, 1000000.0, 10000000.0, 100000000.0,
        1000000000.0, 10000000000.0, 100000000000.0, 1000000000000.0,
    };

    bool   begin = false;
    bool   fail  = false;
    bool   minus = false;
    int    pfrac = 0;

    double dec   = 0.0;
    double frac  = 0.0;

    for (; !fail && off<len; ++off)
    {
        char c = str[off];
        if (c == '+')
        {
            if (!begin)
                begin = true;
            else
                fail = true;
        }
        else if (c == '-')
        {
            if (!begin)
                begin = true;
            else
                fail = true;
            minus = true;
        }
        else if (c == '.')
        {
            if (!begin)
                begin = true;
            else if (pfrac)
                fail = true;
            pfrac = 1;
        }
        else if (c >= '0' && c <= '9')
        {
            if (!begin)
                begin = true;
            if (pfrac == 0)
            {
                dec *= 10;
                dec += c - '0';
            }
            else if (pfrac < 13)
            {
                frac += (c - '0') / bases[pfrac];
                ++pfrac;
            }
        }
        else
        {
            break;
        }
    }

    if (!fail)
    {
        double f = dec + frac;
        if (minus)
            f = -f;
        return f;
    }

    return 0.0;
}


// ------------------------------------------------
#if 0 // stdin

#endif
#if 0 // stdout

#endif
#if 0 // stderr

#endif
#if 0 // cmpinfo
prog.cpp:1:36: fatal error: boost/fusion/adapted.hpp: No such file or directory
compilation terminated.

#endif
