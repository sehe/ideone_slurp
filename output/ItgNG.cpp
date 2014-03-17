// error:	OK
// langId:	1
// langName:	C++ 4.8.1
// langVersion:	gcc-4.8.1
// time:	0.01
// date:	2012-10-15 09:26:07
// status:	0
// result:	15
// memory:	2676
// signal:	0
// public:	false
// ------------------------------------------------
#include <string>

int main()
{
    std::string newFolderName;
    if  (
            newFolderName.find (L'\\') != std::wstring::npos || newFolderName.find (L'/') != std::wstring::npos ||
            newFolderName.find (L':') != std::wstring::npos || newFolderName.find (L'*') != std::wstring::npos ||
            newFolderName.find (L'\?') != std::wstring::npos || newFolderName.find (L'\"') != std::wstring::npos || 
            newFolderName.find (L'<') != std::wstring::npos || newFolderName.find (L'>') != std::wstring::npos ||
            newFolderName.find (L'|')
        )
    {
        return false;
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
