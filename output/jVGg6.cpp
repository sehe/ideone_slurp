// error:	OK
// langId:	1
// langName:	C++ 4.8.1
// langVersion:	gcc-4.8.1
// time:	0
// date:	2012-07-10 17:41:07
// status:	0
// result:	11
// memory:	0
// signal:	0
// public:	false
// ------------------------------------------------
bool nectar_loader::next_token(string& token,
                               const set<char>& special_characters)
{
    // TODO: test the *full* hell out of this function
    // FIXME: ugly as hell, alternatives welcome.
    token.clear();
    bool inside_quotes = false;
    char c;
    auto add_char = [&]
    {
        token.append(1, c);
    };
    while(m_stream.get(c))
    {
        debug(debug::lexer) << "nectar_loader::next_token::line number " << m_line_number << ", character: \'" << output_form(c) << "\', token so far: "
                            << output_form(token) << "\n";
        if(inside_quotes)
        {
            debug(debug::lexer) << "nectar_loader::next_token::Inside quotes.\n";
            if('\"' == c)
            {
                break;    // end of token at end of quotes
            }
            else if('\n' == c)
            {
                throw syntax_error("Quoted strings cannot span several lines.", m_filename, m_line_number);
            }
            else if(token.empty() && std::isspace(c, m_stream.getloc()))
            {
                throw syntax_error("Beginning quote must not be followed by a whitespace.", m_filename, m_line_number);
            }
            else
            {
                add_char();
            }
        }
        else
        {
            if(token.empty())
            {
                if('\n' == c)
                {
                    ++m_line_number;
                }

                if(contains(special_characters, c))
                {
                    // special characters are tokens of their own
                    debug(debug::lexer) << "nectar_loader::next_token::Detected special character.\n";
                    token.append(1, c);
                    return true;
                }
                else if('\"' == c)
                {
                    debug(debug::lexer) << "nectar_loader::next_token::Quote detected.\n";
                    inside_quotes = true;
                    continue;
                }
                else if(std::isspace(c, m_stream.getloc()))
                {
                    continue;
                }
                else if('#' == c)
                {
                    // skip over comments
                    debug(debug::lexer) << "nectar_loader::next_token::Skipping over comments.\n";
                    string temp;
                    std::getline(m_stream, temp);
                    m_stream.putback('\n');
                }
                else if('\\' == c)
                {
                    string temp;
                    std::getline(m_stream, temp);
                    ++m_line_number;
                }
                else
                {
                    add_char();
                }
            }
            else if(std::isspace(c, m_stream.getloc()) || contains(special_characters, c))
            {
                // special characters or whitespace seperate tokens
                debug(debug::lexer) << "nectar_loader::next_token::Detected special character or space.\n";
                m_stream.putback(c);
                break;
            }
            else if('\"' == c)
            {
                throw syntax_error("Beginning quotes must be preceded by a whitespace or a special character.", m_filename, m_line_number);
                return false;
            }
            else
            {
                add_char();
            }
        }
    }
    if(!token.empty())
    {
        debug(debug::lexer) << "nectar_loader::next_token:Token extracted: \'" << output_form(token) << "\'\n";
    }

    return !token.empty();
}

// ------------------------------------------------
#if 0 // stdin

#endif
#if 0 // stdout

#endif
#if 0 // stderr

#endif
#if 0 // cmpinfo
prog.cpp:1: error: ‘nectar_loader’ has not been declared
prog.cpp:1: error: ‘string’ was not declared in this scope
prog.cpp:1: error: ‘token’ was not declared in this scope
prog.cpp:2: error: expected primary-expression before ‘const’
prog.cpp:2: error: initializer expression list treated as compound expression
prog.cpp:3: error: expected ‘,’ or ‘;’ before ‘{’ token

#endif
