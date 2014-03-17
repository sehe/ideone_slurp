// error:	OK
// langId:	44
// langName:	C++11
// langVersion:	gcc-4.8.1
// time:	0
// date:	2013-07-11 19:06:54
// status:	0
// result:	0
// memory:	0
// signal:	0
// public:	false
// ------------------------------------------------

void g()
{
    try
    {
        f();
    }
    catch(my_error & x)
    {
        if(int const * mi=boost::get_error_info<my_info>(x))
        {
            std::cerr << "My info: " << *mi;
        }
    }
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
