// error:	OK
// langId:	1
// langName:	C++ 4.8.1
// langVersion:	gcc-4.8.1
// time:	0
// date:	2012-07-11 01:39:26
// status:	0
// result:	0
// memory:	0
// signal:	0
// public:	true
// ------------------------------------------------
#define BOOST_SPIRIT_USE_PHOENIX_V3

#include <boost/spirit/include/qi.hpp>
#include <boost/spirit/include/lex_lexertl.hpp>
#include <boost/spirit/include/phoenix.hpp>
#include <boost/phoenix/function/adapt_callable.hpp>

using namespace boost::spirit;
using namespace boost::spirit::ascii;

enum tokenids { IDANY = lex::min_token_id + 10 };

template <typename Lexer>
struct word_count_tokens : lex::lexer<Lexer> {
    word_count_tokens() {
        this->self.add_pattern("WORD", "[^ \t\n]+");
        word = "{WORD}";
        this->self.add(word)('\n')(".", IDANY);
    }
    lex::token_def<std::string> word;
};

struct SA {
    template<typename> struct result { typedef void type; };
    template<typename P>
    void operator()(P pair) const {
        std::cout << pair.begin()->id() << '\n';
    }
};

BOOST_PHOENIX_ADAPT_CALLABLE(sa, SA, 1);

template <typename Iterator>
struct grammar : qi::grammar<Iterator> {
    template <typename TokenDef>
    grammar(TokenDef const& tok) : grammar::base_type(start) {
        start =  *( raw[tok.word]         [sa(qi::_1)]
                  | raw[lit('\n')]        [sa(qi::_1)] 
                  | raw[qi::token(IDANY)] [sa(qi::_1)] );
    }
    qi::rule<Iterator> start;
};

int main(int argc, char* argv[])
{
    typedef lex::lexertl::token<char const*, boost::mpl::vector<std::string> > token_type;
    typedef lex::lexertl::lexer<token_type> lexer_type;

    typedef word_count_tokens<lexer_type>::iterator_type iterator_type;

    word_count_tokens<lexer_type> word_count; // Our lexer
    grammar<iterator_type> g (word_count);    // Our parser 

    std::string str("why did the hickup cross the broad?");
    char const* first = str.c_str(), * last = first + str.size();
    lex::tokenize_and_parse(first, last, word_count, g);
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
