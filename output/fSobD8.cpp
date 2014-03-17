// error:	OK
// langId:	44
// langName:	C++11
// langVersion:	gcc-4.8.1
// time:	0
// date:	2013-07-22 03:27:31
// status:	0
// result:	0
// memory:	0
// signal:	0
// public:	true
// ------------------------------------------------
template<typename T, class...Fs> struct visitor_t;
 
template<typename T, class F1, class...Fs>
struct visitor_t<T, F1, Fs...> : F1, visitor_t<T, Fs...>::type {
    typedef visitor_t type;
    visitor_t(F1 head, Fs...tail) : F1(head), visitor_t<T, Fs...>::type(tail...) {}
    
    using F1::operator();
    using visitor_t<T, Fs...>::type::operator();
};
 
template<typename T, class F> struct visitor_t<T, F> : F, boost::static_visitor<T> {
    typedef visitor_t type;
    visitor_t(F f) : F(f) {}
    using F::operator();
};
 
template<typename T=void, class...Fs>
typename visitor_t<T, Fs...>::type make_visitor(Fs...x) { return {x...}; }

struct Person
{
    std::string name;
    double height, weight;
    friend std::ostream& operator<<(std::ostream& os, Person const& s) {
        return os << "Person { name:" << s.name << ", height:" << s.height << ", weight:" << s.weight << " }";
    }
};


// ------------------------------------------------
#if 0 // stdin

#endif
#if 0 // stdout

#endif
#if 0 // stderr

#endif
#if 0 // cmpinfo

#endif
