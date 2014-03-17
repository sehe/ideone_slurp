// error:	OK
// langId:	1
// langName:	C++ 4.8.1
// langVersion:	gcc-4.8.1
// time:	0
// date:	2011-11-02 00:27:50
// status:	0
// result:	15
// memory:	2720
// signal:	0
// public:	true
// ------------------------------------------------
struct base {};

class outer: public base
{
  private:
    enum { some=42, special=67, implementation=999, details=-13 };

  public:
    struct inner 
    { 
      protected: 
        void foo() { int can_usethis = special + implementation + details; } 
    };

    outer() : _inner() { }

    void call_inner(inner& i) const 
    { 
        //i.foo(); // fails (protected)
    }

    void call_inner() const 
    { 
        //_inner.foo(); // fails (protected)
    }

  private:
    inner _inner;
};


int main()
{
    outer o;
    outer::inner i;

    // i.foo(); // fails: protected
    o.call_inner(i);
}

// ------------------------------------------------
#if 0 // stdin

#endif
#if 0 // stdout

#endif
#if 0 // stderr

#endif
#if 0 // cmpinfo
prog.cpp: In member function ‘void outer::inner::foo()’:
prog.cpp:12: warning: unused variable ‘can_usethis’

#endif
