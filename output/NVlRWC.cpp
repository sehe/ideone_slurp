// error:	OK
// langId:	44
// langName:	C++11
// langVersion:	gcc-4.8.1
// time:	0
// date:	2012-11-10 01:55:55
// status:	0
// result:	15
// memory:	3076
// signal:	0
// public:	false
// ------------------------------------------------
#include <map>
#include <string>
#include <fstream>
#include <iostream>
#include <algorithm>

typedef std::map<std::string, std::string> Map;

struct Settings
{
    std::string file;
    Settings(std::string f="") : file(f) {}
    Map Init();
};

static inline std::string& line_trim(std::string& s)
{
    s.erase(s.begin(),
            std::find_if(s.begin(),
                s.end(),
                std::not1(std::ptr_fun<int, int>(std::isspace))));
    return s;
}

static inline std::string& end_trim(std::string& s)
{
    s.erase(std::find_if(s.rbegin(),
                s.rend(),
                std::not1(std::ptr_fun<int, int>(std::isspace))).base(),
            s.end());
    return s;
}

static inline std::string& trim(std::string &s)
{
    return line_trim(end_trim(s));
}

Map loadSettings(std::istream& is)
{
    Map config;
    std::string line;
    while(std::getline(is, line))
    {
        int pos = line.find('=');
        if(pos != std::string::npos)
        {
            std::string key   = line.substr(0, pos);
            std::string value = line.substr(pos + 1);
            config[trim(key)] = trim(value);          // trim function removes white spaces
        }
    }
    return config;
}

Map Settings::Init()
{
    if (trim(file).empty())
        return loadSettings(std::cin);

    std::ifstream is(file);
    return loadSettings(is);
}

int main()
{
    Settings Config;
    Map config = Config.Init();
    std::cout << config["noot"] << "\n";
}

// ------------------------------------------------
#if 0 // stdin
aap = 123
noot = 456
mies = 567

#endif
#if 0 // stdout
456

#endif
#if 0 // stderr

#endif
#if 0 // cmpinfo

#endif
