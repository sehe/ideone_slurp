// error:	OK
// langId:	1
// langName:	C++ 4.8.1
// langVersion:	gcc-4.8.1
// time:	0
// date:	2012-02-22 04:06:41
// status:	0
// result:	11
// memory:	0
// signal:	0
// public:	false
// ------------------------------------------------
static bool process(std::string& macro)
{
    if (macro == "error")
    {
        return false; // fail the parse
    }

    if (macro == "hello")
    {
        macro = "bye";
    }
    else if (macro == "bye")
    {
        macro = "We meet again";
    }
    else if (macro == "sideeffect")
    {
        std::cerr << "this is a side effect while parsing\n";
        macro = "(done)";
    }
    else if (std::string::npos != macro.find('~'))
    {
        std::reverse(macro.begin(), macro.end());
        macro.erase(std::remove(macro.begin(), macro.end(), '~'));
    }
    else
    {
        macro = std::string("<<") + macro + ">>"; // this makes the unsupported macros appear unchanged
    }

    return true;
}

// ------------------------------------------------
#if 0 // stdin

#endif
#if 0 // stdout

#endif
#if 0 // stderr

#endif
#if 0 // cmpinfo
prog.cpp:1: error: ‘string’ is not a member of ‘std’
prog.cpp:1: error: ‘macro’ was not declared in this scope
prog.cpp:2: error: expected ‘,’ or ‘;’ before ‘{’ token
prog.cpp:1: warning: ‘process’ defined but not used

#endif
