// error:	OK
// langId:	1
// langName:	C++ 4.8.1
// langVersion:	gcc-4.8.1
// time:	0
// date:	2011-11-11 14:34:18
// status:	0
// result:	15
// memory:	2720
// signal:	0
// public:	true
// ------------------------------------------------
enum LogType_E {
        LOG_ERROR       = 0,            //!< error
        LOG_WARNING     = 1,            //!< warning
        LOG_SUCCESS     = 2,            //!< success
        LOG_INFO        = 3,            //!< info
        LOG_TRACE       = 4,            //!< trace message if tracing is enabled
        LOG_TRACE1      = 5,            //!< trace level 1
        LOG_TRACE2      = 6,            //!< trace level 2
        LOG_TRACE3      = 7,            //!< trace level 3
        LOG_TRACE4      = 8             //!< trace level 4
    };


bool logMessage(LogType_E, unsigned int, int, const char *, ...)
{
    return true;
}

bool logMessage(LogType_E, int, const char *, ...)
{
    return true;
}

int main()
{
    logMessage(LOG_TRACE, 0u, 0, "Teststring 2");
    return 0;
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
