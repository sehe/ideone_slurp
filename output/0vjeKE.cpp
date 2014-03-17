// error:	OK
// langId:	44
// langName:	C++11
// langVersion:	gcc-4.8.1
// time:	0
// date:	2013-06-30 01:15:28
// status:	0
// result:	0
// memory:	0
// signal:	0
// public:	false
// ------------------------------------------------
#include <boost/fusion/adapted/std_pair.hpp>
#include <boost/spirit/include/qi.hpp>
#include <boost/spirit/include/phoenix.hpp>
#include <boost/spirit/include/phoenix_fusion.hpp>

namespace qi    = boost::spirit::qi;
namespace phx   = boost::phoenix;

typedef std::string column_name_t;

enum sql_faggregate
{
    AVG,
    // ....
    SUM,
};

typedef std::pair<column_name_t, int/*sql_faggregate*/> column_and_aggregate;
typedef std::vector<column_and_aggregate> column_and_aggregate_container;

namespace parsers
{
    typedef std::string::const_iterator iterator;

    qi::rule< iterator, column_name_t() > quoted_string = 
        qi::lexeme["\"" >> +~qi::char_("\"") >> "\""];
    qi::rule< iterator, column_and_aggregate(), qi::space_type > agg_pair =
        quoted_string  [ phx::at_c<0>(qi::_val) = qi::_1 ]
        > ':'
        // A rule validation technic is used below.
        > qi::int_[qi::_pass = (qi::_1 >=AVG && qi::_1<=SUM), phx::at_c<1>(qi::_val) = qi::_1];//::boost::bind( &apply_col_and_aggr_visitor, qi::_val, qi::_1 )];
    qi::rule< iterator, column_and_aggregate_container(), qi::space_type > aggregates_parser =
        '{'
        > agg_pair/*[phoenix::push_back(qi::_val, qi::_1)]*/ % ',' // N.B.!!! list-redux technic
        > '}';
}

bool doParse(const std::string& input)
{
    using namespace parsers;

    auto f(begin(input)), l(end(input));

    //parser<iterator, qi::space_type> p;
    column_and_aggregate_container data;
    try
    {
        bool ok = qi::phrase_parse(f,l,aggregates_parser,qi::space,data);
        if (ok)   
        {
            std::cout << "parse success\n";
            for (auto& pair : data)
                std::cout << "result: '" << pair.first << "' : " << (int) pair.second << "\n";
        }
        else      std::cerr << "parse failed: '" << std::string(f,l) << "'\n";

        if (f!=l) std::cerr << "trailing unparsed: '" << std::string(f,l) << "'\n";
        return ok;
    }
    catch(const qi::expectation_failure<iterator>& e)
    {
        std::string frag(e.first, e.last);
        std::cerr << e.what() << "'" << frag << "'\n";
    }

    return false;
}

int main()
{
    //bool ok = doParse("{ 'column 1' : 1, 'column 2' : 0, 'column 3' : 1 }");
    doParse("{ \"column 1\" : 1, \"column 2\" : 0, \"column 3\" : 1 }");
    //return ok? 0 : 255;
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
