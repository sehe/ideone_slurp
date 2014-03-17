// error:	OK
// langId:	1
// langName:	C++ 4.8.1
// langVersion:	gcc-4.8.1
// time:	0
// date:	2012-02-13 12:25:33
// status:	0
// result:	11
// memory:	0
// signal:	0
// public:	false
// ------------------------------------------------
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/ini_parser.hpp>
#include <iostream>
using boost::property_tree::ptree;

struct demo {
    int player;
    void load(const std::string &fname) {
        ptree pt;
        read_ini(fname, pt);
        player = pt.get("demo.player", 2);
    }
    void save(const std::string &fname) {
        ptree pt;
        pt.put("demo.player", player);
        write_ini(fname, pt);
    }
};

int main() {
    try {
        demo ds;
        ds.load("demo.ini");
        ds.save("demo_out.ini");
        std::cout << "Success\n";
    } catch (std::exception &e) {
        std::cout << "Error: " << e.what() << "\n";
    }
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
prog.cpp:1:41: error: boost/property_tree/ptree.hpp: No such file or directory
prog.cpp:2:46: error: boost/property_tree/ini_parser.hpp: No such file or directory
prog.cpp:4: error: ‘boost’ has not been declared
prog.cpp: In member function ‘void demo::load(const std::string&)’:
prog.cpp:9: error: ‘ptree’ was not declared in this scope
prog.cpp:9: error: expected `;' before ‘pt’
prog.cpp:10: error: ‘pt’ was not declared in this scope
prog.cpp:10: error: ‘read_ini’ was not declared in this scope
prog.cpp: In member function ‘void demo::save(const std::string&)’:
prog.cpp:14: error: ‘ptree’ was not declared in this scope
prog.cpp:14: error: expected `;' before ‘pt’
prog.cpp:15: error: ‘pt’ was not declared in this scope
prog.cpp:16: error: ‘write_ini’ was not declared in this scope

#endif
