// error:	OK
// langId:	1
// langName:	C++ 4.8.1
// langVersion:	gcc-4.8.1
// time:	0
// date:	2011-10-19 01:54:10
// status:	0
// result:	11
// memory:	0
// signal:	0
// public:	false
// ------------------------------------------------
#include <boost/spirit/include/qi.hpp>
namespace qi = boost::spirit::qi;

typedef boost::make_recursive_variant<
    std::vector<boost::recursive_variant_>, 
    std::string>::type ast_t;

void dump(const ast_t& tree);

// adhoc parser rule:
static const qi::rule<std::string::iterator, ast_t()> node = 
    '{' >> *node >> '}' | +~qi::char_("{}");

int main()
{
     std::string input = "{Parent{{ChildA{ChildC}{ChildD}}{ChildB{ChildE}{ChildF}}}}";
     std::string::iterator f(input.begin()), l(input.end());

     ast_t tree;
     if (qi::parse(f, l, node, tree))
         dump(tree);
     else
         std::cerr << "Unparsed: " << std::string(f, l) << std::endl;
}

struct dump_visitor : boost::static_visitor<>
{
    dump_visitor(int indent=0) : _indent(indent) {}

    void operator()(const std::string& s) const { print(s); }

    template <class V>
        void operator()(const V& vec) const
    {
        print("{");
        for(typename V::const_iterator it=vec.begin(); it!=vec.end(); it++)
            boost::apply_visitor(dump_visitor(_indent+1), *it);
        print("}");
    }

  private:
    template <typename T> void print(const T& v) const 
      { std::cout << std::string(_indent*4, ' ') << v << std::endl; }
    int _indent;
};

void dump(const ast_t& tree)
{
    boost::apply_visitor(dump_visitor(), tree);
}


// ------------------------------------------------
#if 0 // stdin

#endif
#if 0 // stdout

#endif
#if 0 // stderr

#endif
#if 0 // cmpinfo
prog.cpp:12: error: ‘char_’ is not a member of ‘qi’
prog.cpp: In function ‘int main()’:
prog.cpp:23: error: ‘cerr’ is not a member of ‘std’
prog.cpp: In member function ‘void dump_visitor::print(const T&) const’:
prog.cpp:43: error: ‘cout’ is not a member of ‘std’

#endif
