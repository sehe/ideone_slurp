// error:	OK
// langId:	44
// langName:	C++11
// langVersion:	gcc-4.8.1
// time:	0
// date:	2011-10-14 23:45:47
// status:	0
// result:	11
// memory:	0
// signal:	0
// public:	true
// ------------------------------------------------
#include <boost/spirit/include/lex_lexertl.hpp>

#include <iostream>
#include <string>

namespace lex = boost::spirit::lex;

typedef std::string::iterator base_iterator_type;
typedef boost::spirit::lex::lexertl::token<base_iterator_type, boost::mpl::vector<int, std::string>> Tok;
typedef lex::lexertl::actor_lexer<Tok> lexer_type;

template<typename L>
class SimpleLexer : public lex::lexer<L> {
    private:

    public:
        SimpleLexer() {
            word = "[a-zA-Z]+";
            integer = "[0-9]+";
            literal = "...";
			
            this->self += integer | literal | word;
        }
       
        lex::token_def<std::string> word, literal;
        lex::token_def<int> integer;
};

int main(int argc, const char* argv[]) {
    SimpleLexer<lexer_type> lexer;

    std::string contents = "void";

    base_iterator_type first = contents.begin();
    base_iterator_type last = contents.end();

    lexer_type::iterator_type iter = lexer.begin(first, last);
    lexer_type::iterator_type end = lexer.end();
    
    assert(0 == iter->value().which());
    std::cout << "Value = " << boost::get<boost::iterator_range<base_iterator_type> >(iter->value()) << std::endl;

    std::string s;
    boost::spirit::traits::assign_to(*iter, s);
    assert(2 == iter->value().which());
    std::cout << "Value = " << s << std::endl;
	
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
prog.cpp:1:48: fatal error: boost/spirit/include/lex_lexertl.hpp: No such file or directory
compilation terminated.

#endif
