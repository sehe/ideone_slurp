// error:	OK
// langId:	44
// langName:	C++11
// langVersion:	gcc-4.8.1
// time:	0
// date:	2013-07-23 09:17:25
// status:	0
// result:	0
// memory:	0
// signal:	0
// public:	true
// ------------------------------------------------
template <typename T>
struct Vector<T>
{
    friend Vector operator*(Vector const&, int); // note: nonmember fn!
    friend Vector operator*(int, Vector const&); // note: nonmember fn!

    Vector operator*(int) const;
    template <typename U>
        Vector operator*(Vector<U> const &) const;
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
