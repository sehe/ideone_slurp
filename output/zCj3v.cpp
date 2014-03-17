// error:	OK
// langId:	1
// langName:	C++ 4.8.1
// langVersion:	gcc-4.8.1
// time:	0
// date:	2012-02-20 09:16:09
// status:	0
// result:	11
// memory:	0
// signal:	0
// public:	false
// ------------------------------------------------
#include <boost/spirit/include/qi.hpp>
#include <boost/spirit/include/phoenix.hpp>
namespace qi = boost::spirit::qi;

enum numeric_types
{
    fmt_none,
    fmt_float,
    fmt_double,
    fmt_uint,
    fmt_int,
    // fmt_hex, etc. 
};

template <typename It>
    bool is_numeric(It& f, It l, numeric_types& detected)
{
    return qi::phrase_parse(f,l,
            qi::uint_   [ qi::_val = fmt_uint   ]
          | qi::int_    [ qi::_val = fmt_int    ]
          | qi::float_  [ qi::_val = fmt_float  ]
          | qi::double_ [ qi::_val = fmt_double ]
           ,qi::space, detected);
}

template <typename It>
    bool is_numeric(It& f, It l)
{
    numeric_types detected = fmt_none;
    return is_numeric(f, l, detected);
}

int main()
{
    const std::string input = "124, -25, 582";
    std::string::const_iterator it = input.begin();

    bool ok = is_numeric(it, input.end());

    if (ok)   
    {
        std::cout << "parse success\n";
        if (it!=input.end()) 
            std::cerr << "trailing unparsed: '" << std::string(it,input.end()) << "'\n";
    }
    else 
        std::cerr << "parse failed: '" << std::string(it,input.end()) << "'\n";

    return ok? 0 : 255;
}

// ------------------------------------------------
#if 0 // stdin

#endif
#if 0 // stdout

#endif
#if 0 // stderr

#endif
#if 0 // cmpinfo
prog.cpp: In function ‘bool is_numeric(It&, It, numeric_types&)’:
prog.cpp:19: error: ‘uint_’ is not a member of ‘qi’
prog.cpp:19: error: ‘_val’ is not a member of ‘qi’
prog.cpp:20: error: ‘int_’ is not a member of ‘qi’
prog.cpp:20: error: ‘_val’ is not a member of ‘qi’
prog.cpp:21: error: ‘float_’ is not a member of ‘qi’
prog.cpp:21: error: ‘_val’ is not a member of ‘qi’
prog.cpp:22: error: ‘double_’ is not a member of ‘qi’
prog.cpp:22: error: ‘_val’ is not a member of ‘qi’
prog.cpp:23: error: ‘space’ is not a member of ‘qi’

#endif
