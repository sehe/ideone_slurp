// error:	OK
// langId:	1
// langName:	C++ 4.8.1
// langVersion:	gcc-4.8.1
// time:	0
// date:	2011-11-02 09:08:56
// status:	0
// result:	15
// memory:	2720
// signal:	0
// public:	true
// ------------------------------------------------
// stub mutex_t: implement this for your operating system
struct mutex_t 
{ 
    void Acquire() {} 
    void Release() {} 
};

struct LockGuard
{
     LockGuard(mutex_t& mutex) : _ref(mutex) 
     { 
         _ref.Acquire();  // TODO operating system specific
     };

     ~LockGuard() 
     { 
          _ref.Release(); // TODO operating system specific
     }
   private:
     LockGuard(const LockGuard&); // or use c++0x ` = delete`

     mutex_t& _ref;
};

int main()
{
    mutex_t mtx;

    {
        LockGuard lock(mtx);
        // LockGuard copy(lock); // ERROR: constructor private
        // lock = LockGuard(mtx);// ERROR: no default assignment operator
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
