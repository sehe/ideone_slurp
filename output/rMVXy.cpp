// error:	OK
// langId:	1
// langName:	C++ 4.8.1
// langVersion:	gcc-4.8.1
// time:	0.01
// date:	2012-05-10 23:24:15
// status:	0
// result:	15
// memory:	2720
// signal:	0
// public:	false
// ------------------------------------------------
template<typename T> 
struct a_p
{
    typedef T**********type;
};

template<int N,typename T>
struct a_ps : a_p<typename a_ps<N-1, T>::type> {};


template<typename T>
struct a_ps<0,T>
{
    typedef T type;
};

template<int N, typename T> 
struct amp : a_ps<80,typename amp<N-1, T>::type> {};

template<typename T>
struct amp<0,T>
{
    typedef T type;
};

int main()
{
    amp<80, int>::type p;
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
