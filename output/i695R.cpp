// error:	OK
// langId:	1
// langName:	C++ 4.8.1
// langVersion:	gcc-4.8.1
// time:	0
// date:	2012-02-21 23:03:04
// status:	0
// result:	11
// memory:	0
// signal:	0
// public:	false
// ------------------------------------------------
// #define BOOST_SPIRIT_DEBUG
#include <iostream>
#include <iterator>
#include <boost/spirit/include/qi.hpp>
#include <boost/spirit/include/phoenix.hpp>

namespace qi = boost::spirit::qi;

namespace
{
    template<typename Iterator>
        struct skel_grammar : public qi::grammar<Iterator>
    {
        skel_grammar() : skel_grammar::base_type(start)
        {
            using namespace qi;

            text    = no_skip[+(char_ - macro_b)];  // [_val      += _1]];
            macro_b = lit("<<");
            macro_e = lit(">>");
            macro  %= macro_b >> skip(space) [ id ] >> macro_e;
            id     %= 
                -(alpha | char_('_'))
             >> +(alnum | char_('_'));

            start   = *(text | macro);

            BOOST_SPIRIT_DEBUG_NODE(start);
            BOOST_SPIRIT_DEBUG_NODE(macro);
            BOOST_SPIRIT_DEBUG_NODE(macro_e);
            BOOST_SPIRIT_DEBUG_NODE(macro_b);
            BOOST_SPIRIT_DEBUG_NODE(id);
            BOOST_SPIRIT_DEBUG_NODE(text);
        }

        private:
        qi::rule<Iterator> macro_b;
        qi::rule<Iterator> macro_e;
        qi::rule<Iterator, qi::space_type> id;
        qi::rule<Iterator> macro;
        qi::rule<Iterator> text;
        qi::rule<Iterator> start;
    };

}  // namespace

int main(int argc, char* argv[])
{
    std::string input(std::istreambuf_iterator<char>(std::cin),
                      (std::istreambuf_iterator<char>()));
    skel_grammar<std::string::iterator> grammar;

    bool r = qi::parse(input.begin(), input.end(), grammar);

    std::cout << std::boolalpha << r << '\n';

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
prog.cpp:39: error: ‘space_type’ is not a member of ‘qi’
prog.cpp:39: error: ‘space_type’ is not a member of ‘qi’
prog.cpp:39: error: template argument 2 is invalid
prog.cpp: In constructor ‘<unnamed>::skel_grammar<Iterator>::skel_grammar()’:
prog.cpp:18: error: ‘no_skip’ was not declared in this scope
prog.cpp:18: error: ‘char_’ was not declared in this scope
prog.cpp:19: error: there are no arguments to ‘lit’ that depend on a template parameter, so a declaration of ‘lit’ must be available
prog.cpp:19: error: (if you use ‘-fpermissive’, G++ will accept your code, but allowing the use of an undeclared name is deprecated)
prog.cpp:20: error: there are no arguments to ‘lit’ that depend on a template parameter, so a declaration of ‘lit’ must be available
prog.cpp:21: error: ‘space’ was not declared in this scope
prog.cpp:23: error: ‘alpha’ was not declared in this scope
prog.cpp:24: error: ‘alnum’ was not declared in this scope
prog.cpp: In function ‘int main(int, char**)’:
prog.cpp:53: error: invalid initialization of non-const reference of type ‘__gnu_cxx::__normal_iterator<char*, std::basic_string<char, std::char_traits<char>, std::allocator<char> > >&’ from a temporary of type ‘__gnu_cxx::__normal_iterator<char*, std::basic_string<char, std::char_traits<char>, std::allocator<char> > >’
/usr/include/boost/spirit/home/qi/parse.hpp:23: error: in passing argument 1 of ‘bool boost::spirit::qi::parse(Iterator&, Iterator, const Expr&) [with Iterator = __gnu_cxx::__normal_iterator<char*, std::basic_string<char, std::char_traits<char>, std::allocator<char> > >, Expr = <unnamed>::skel_grammar<__gnu_cxx::__normal_iterator<char*, std::basic_string<char, std::char_traits<char>, std::allocator<char> > > >]’
prog.cpp: In constructor ‘<unnamed>::skel_grammar<Iterator>::skel_grammar() [with Iterator = __gnu_cxx::__normal_iterator<char*, std::basic_string<char, std::char_traits<char>, std::allocator<char> > >]’:
prog.cpp:51:   instantiated from here
prog.cpp:19: error: ‘lit’ was not declared in this scope

#endif
