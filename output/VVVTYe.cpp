// error:	OK
// langId:	44
// langName:	C++11
// langVersion:	gcc-4.8.1
// time:	0
// date:	2013-08-22 00:00:23
// status:	0
// result:	0
// memory:	0
// signal:	0
// public:	false
// ------------------------------------------------
//#define BOOST_SPIRIT_DEBUG
#include <boost/spirit/include/qi.hpp>

namespace qi = boost::spirit::qi;

typedef std::string Column;
typedef std::vector<Column> Columns;
typedef Columns CsvLine;
typedef std::vector<CsvLine> CsvFile;

template <typename It>
struct CsvGrammar : qi::grammar<It, CsvFile(), qi::blank_type>
{
    CsvGrammar() : CsvGrammar::base_type(start)
    {
        static const char colsep = ',';

        start  = -line % qi::eol;
        line   = column % colsep;
        column = quoted | *~qi::char_(colsep);
        quoted = '"' >> *("\"\"" | ~qi::char_('"')) >> '"';

        BOOST_SPIRIT_DEBUG_NODES((start)(line)(column)(quoted));
    }
  private:
    qi::rule<It, CsvFile(), qi::blank_type> start;
    qi::rule<It, CsvLine(), qi::blank_type> line;
    qi::rule<It, Column(),  qi::blank_type> column;
    qi::rule<It, std::string()> quoted;
};

int main()
{
    const std::string s = "1997,Ford,E350,\"ac, abs, moon\",\"\"\"rusty\"\"\",3001.00";

    typedef std::string::const_iterator It;
    It f(s.begin()), l(s.end());
    CsvGrammar<It> p;

    CsvFile parsed;
    bool ok = qi::phrase_parse(f,l,p,qi::blank,parsed);

    if (ok)
    {
        for (CsvFile::const_iterator lit = parsed.begin(); lit != parsed.end(); ++lit) {
            for (Columns::const_iterator cit = lit->begin(); cit != lit->end(); ++cit)
                std::cout << '[' << *cit << ']';
            std::cout << std::endl;
        }
    } else
    {
        std::cout << "Parse failed\n";
    }

    if (f!=l)
        std::cout << "Remaining unparsed: '" << std::string(f,l) << "'\n";
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
