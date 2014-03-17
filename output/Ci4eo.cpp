// error:	OK
// langId:	1
// langName:	C++ 4.8.1
// langVersion:	gcc-4.8.1
// time:	0
// date:	2011-12-09 15:27:15
// status:	0
// result:	15
// memory:	2724
// signal:	0
// public:	true
// ------------------------------------------------
#include <fstream>
#include <iostream>
#include <string>

struct Logger
{
    Logger(std::ostream& os) : m_log(os.rdbuf()) { }

    std::streambuf* reset(std::ostream& os) 
    {
        return m_log.rdbuf(os.rdbuf());
    }

    template <typename T> friend Logger& operator<<(Logger& os, const T& t)
    { os.m_log << t; return os; }

    friend Logger& operator<<(Logger& os, std::ostream& ( *pf )(std::ostream&))
    { os.m_log << pf; return os; }
    
  private:
    std::ostream m_log;
};

int main(int argc, const char *argv[])
{
    Logger logto(std::cout);

    logto << "Hello world" << std::endl;

    logto.reset(std::cerr);
    logto << "Error world" << std::endl;

    return 0;
}



// ------------------------------------------------
#if 0 // stdin

#endif
#if 0 // stdout
Hello world

#endif
#if 0 // stderr

#endif
#if 0 // cmpinfo

#endif
