// error:	OK
// langId:	44
// langName:	C++11
// langVersion:	gcc-4.8.1
// time:	0
// date:	2013-04-17 02:50:18
// status:	0
// result:	0
// memory:	0
// signal:	0
// public:	true
// ------------------------------------------------
namespace JSON
{
    template <typename Tag> struct Literal { };

    typedef Literal<struct tag_undefined> Undefined;
    typedef Literal<struct tag_false> False;
    typedef Literal<struct tag_null>  Null;
    typedef Literal<struct tag_true>  True;

    struct Object;
    struct Array;

    struct String { 
        std::wstring value; 
        bool operator==(String const& s) const { return value == s.value; }
    };
}

namespace std
{
    template <> struct hash<JSON::String>
    {
        size_t operator()(JSON::String const& s) const {
            static std::hash<std::wstring> _hash;
            return _hash(s.value);
        }
    };
}

namespace JSON
{
    struct Number { double value;      };

    typedef boost::variant<
            Undefined, // not legal as a JSON result
            False, 
            Null, 
            True, 
            boost::recursive_wrapper<Object>, 
            boost::recursive_wrapper<Array>,
            String,
            Number
        > Value;

    struct Object
    {
        typedef std::unordered_map<String, Value> values_t;
        values_t values;
    };

    struct Array
    {
        typedef std::deque<Value> values_t;
        values_t values;
    };
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
