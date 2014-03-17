// error:	OK
// langId:	10
// langName:	Java
// langVersion:	sun-jdk-1.7.0_25
// time:	0
// date:	2013-11-10 00:24:59
// status:	0
// result:	11
// memory:	0
// signal:	0
// public:	false
// ------------------------------------------------
// The MIT License (MIT)

// Copyright (c) 2012-2013 Danny Y., Rapptz

// Permission is hereby granted, free of charge, to any person obtaining a copy of
// this software and associated documentation files (the "Software"), to deal in
// the Software without restriction, including without limitation the rights to
// use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
// the Software, and to permit persons to whom the Software is furnished to do so,
// subject to the following conditions:

// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.

// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
// FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
// COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
// IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
// CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

#ifndef GEARS_COMMAND_LINE_ARG_HPP
#define GEARS_COMMAND_LINE_ARG_HPP

#include <string>

#ifndef GEARS_NO_IOSTREAM
#include <iosfwd>
#endif // GEARS_NO_IOSTREAM

namespace gears
{
namespace command_line
{
struct arg
{
private:
    friend class parser;
    std::string name;
    std::string description;
    std::string parameter;
    std::string value;
    bool active = false;
    bool req;
    char short_name;
public:
    arg(std::string name, 
        std::string desc  = "",
        char shorter      = '\0',
        bool req          = false,
        std::string param = "",
        std::string val   = ""
    ) noexcept
        : name(std::move(name)),
          description(std::move(desc)),
          parameter(std::move(param)),
          value(std::move(val)),
          req(req),
          short_name(shorter) 
    {
    }

    bool is_value() const noexcept
    {
        return !parameter.empty();
    }

    arg& shorter(char c) noexcept
    {
        short_name = c;
        return *this;
    }

    arg& help(std::string str) noexcept
    {
        description = std::move(str);
        return *this;
    }

    arg& param(std::string str) noexcept
    {
        parameter = std::move(str);
        return *this;
    }

    arg& default_value(std::string str) noexcept
    {
        value = std::move(str);
        return *this;
    }

    arg& required(bool b = true) noexcept
    {
        req = b;
        return *this;
    }

#ifndef GEARS_NO_IOSTREAM

    template<typename Elem, typename Traits>
    friend auto operator<<(std::basic_ostream<Elem, Traits>& out, const arg& a) -> decltype(out)
    {
        int spaces = 30;
        out << "    ";
        if(!a.name.empty())
        {
            if(a.short_name != '\0')
            {
                out << '-' << a.short_name << ", ";
                spaces -= 4;
            }
            out << "--" << a.name;
            spaces -= 2 + a.name.size();
            if(!a.parameter.empty())
            {
                out << "[=<" << a.parameter << ">]";
                spaces -= 5 + a.parameter.size();
            }
            for(int i = 0; i < spaces; ++i)
            {
                out << ' ';
            }
            out << a.description << '\n';
        }
        return out;
    }

#endif // GEARS_NO_IOSTREAM
};
} // command_line
} // gears

#endif // GEARS_COMMAND_LINE_ARG_HPP

// ------------------------------------------------
#if 0 // stdin

#endif
#if 0 // stdout

#endif
#if 0 // stderr

#endif
#if 0 // cmpinfo
Main.java:22: error: illegal character: \35
#ifndef GEARS_COMMAND_LINE_ARG_HPP
^
Main.java:23: error: illegal character: \35
#define GEARS_COMMAND_LINE_ARG_HPP
^
Main.java:25: error: illegal character: \35
#include <string>
^
Main.java:27: error: illegal character: \35
#ifndef GEARS_NO_IOSTREAM
^
Main.java:28: error: illegal character: \35
#include <iosfwd>
^
Main.java:29: error: illegal character: \35
#endif // GEARS_NO_IOSTREAM
^
Main.java:38: error: '{' expected
    friend class parser;
                       ^
Main.java:39: error: <identifier> expected
    std::string name;
       ^
Main.java:39: error: illegal start of type
    std::string name;
        ^
Main.java:39: error: ';' expected
    std::string name;
               ^
Main.java:39: error: <identifier> expected
    std::string name;
                    ^
Main.java:40: error: <identifier> expected
    std::string description;
       ^
Main.java:40: error: illegal start of type
    std::string description;
        ^
Main.java:40: error: ';' expected
    std::string description;
               ^
Main.java:40: error: <identifier> expected
    std::string description;
                           ^
Main.java:41: error: <identifier> expected
    std::string parameter;
       ^
Main.java:41: error: illegal start of type
    std::string parameter;
        ^
Main.java:41: error: ';' expected
    std::string parameter;
               ^
Main.java:41: error: <identifier> expected
    std::string parameter;
                         ^
Main.java:42: error: <identifier> expected
    std::string value;
       ^
Main.java:42: error: illegal start of type
    std::string value;
        ^
Main.java:42: error: ';' expected
    std::string value;
               ^
Main.java:42: error: <identifier> expected
    std::string value;
                     ^
Main.java:46: error: illegal start of type
public:
      ^
Main.java:46: error: ';' expected
public:
       ^
Main.java:47: error: illegal start of type
    arg(std::string name, 
       ^
Main.java:47: error: ';' expected
    arg(std::string name, 
           ^
Main.java:48: error: ';' expected
        std::string desc  = "",
           ^
Main.java:48: error: <identifier> expected
        std::string desc  = "",
                               ^
Main.java:49: error: <identifier> expected
        char shorter      = '\0',
                    ^
Main.java:50: error: ';' expected
        bool req          = false,
            ^
Main.java:50: error: <identifier> expected
        bool req          = false,
                ^
Main.java:51: error: ';' expected
        std::string param = "",
           ^
Main.java:52: error: ';' expected
        std::string val   = ""
           ^
Main.java:52: error: ';' expected
        std::string val   = ""
                              ^
Main.java:53: error: <identifier> expected
    ) noexcept
              ^
Main.java:54: error: invalid method declaration; return type required
        : name(std::move(name)),
          ^
Main.java:54: error: <identifier> expected
        : name(std::move(name)),
                  ^
Main.java:54: error: ';' expected
        : name(std::move(name)),
                   ^
Main.java:54: error: invalid method declaration; return type required
        : name(std::move(name)),
                    ^
Main.java:54: error: <identifier> expected
        : name(std::move(name)),
                             ^
Main.java:54: error: ';' expected
        : name(std::move(name)),
                              ^
Main.java:63: error: ';' expected
    bool is_value() const noexcept
                   ^
Main.java:68: error: <identifier> expected
    arg& shorter(char c) noexcept
       ^
Main.java:68: error: invalid method declaration; return type required
    arg& shorter(char c) noexcept
         ^
Main.java:68: error: ';' expected
    arg& shorter(char c) noexcept
                        ^
Main.java:71: error: illegal start of expression
        return *this;
               ^
Main.java:74: error: <identifier> expected
    arg& help(std::string str) noexcept
       ^
Main.java:74: error: invalid method declaration; return type required
    arg& help(std::string str) noexcept
         ^
Main.java:74: error: <identifier> expected
    arg& help(std::string str) noexcept
                 ^
Main.java:74: error: ';' expected
    arg& help(std::string str) noexcept
                  ^
Main.java:74: error: ';' expected
    arg& help(std::string str) noexcept
                             ^
Main.java:74: error: <identifier> expected
    arg& help(std::string str) noexcept
                                       ^
Main.java:76: error: <identifier> expected
        description = std::move(str);
                   ^
Main.java:76: error: ';' expected
        description = std::move(str);
                         ^
Main.java:76: error: invalid method declaration; return type required
        description = std::move(str);
                           ^
Main.java:76: error: <identifier> expected
        description = std::move(str);
                                   ^
Main.java:77: error: illegal start of type
        return *this;
        ^
Main.java:77: error: ';' expected
        return *this;
              ^
Main.java:77: error: illegal start of type
        return *this;
                ^
Main.java:77: error: <identifier> expected
        return *this;
                    ^
Main.java:77: error: ';' expected
        return *this;
                     ^
Main.java:80: error: <identifier> expected
    arg& param(std::string str) noexcept
       ^
Main.java:80: error: invalid method declaration; return type required
    arg& param(std::string str) noexcept
         ^
Main.java:80: error: <identifier> expected
    arg& param(std::string str) noexcept
                  ^
Main.java:80: error: ';' expected
    arg& param(std::string str) noexcept
                   ^
Main.java:80: error: ';' expected
    arg& param(std::string str) noexcept
                              ^
Main.java:80: error: <identifier> expected
    arg& param(std::string str) noexcept
                                        ^
Main.java:82: error: <identifier> expected
        parameter = std::move(str);
                 ^
Main.java:82: error: ';' expected
        parameter = std::move(str);
                       ^
Main.java:82: error: invalid method declaration; return type required
        parameter = std::move(str);
                         ^
Main.java:82: error: <identifier> expected
        parameter = std::move(str);
                                 ^
Main.java:83: error: illegal start of type
        return *this;
        ^
Main.java:83: error: ';' expected
        return *this;
              ^
Main.java:83: error: illegal start of type
        return *this;
                ^
Main.java:83: error: <identifier> expected
        return *this;
                    ^
Main.java:83: error: ';' expected
        return *this;
                     ^
Main.java:86: error: <identifier> expected
    arg& default_value(std::string str) noexcept
       ^
Main.java:86: error: invalid method declaration; return type required
    arg& default_value(std::string str) noexcept
         ^
Main.java:86: error: <identifier> expected
    arg& default_value(std::string str) noexcept
                          ^
Main.java:86: error: ';' expected
    arg& default_value(std::string str) noexcept
                           ^
Main.java:86: error: ';' expected
    arg& default_value(std::string str) noexcept
                                      ^
Main.java:86: error: <identifier> expected
    arg& default_value(std::string str) noexcept
                                                ^
Main.java:88: error: <identifier> expected
        value = std::move(str);
             ^
Main.java:88: error: ';' expected
        value = std::move(str);
                   ^
Main.java:88: error: invalid method declaration; return type required
        value = std::move(str);
                     ^
Main.java:88: error: <identifier> expected
        value = std::move(str);
                             ^
Main.java:89: error: illegal start of type
        return *this;
        ^
Main.java:89: error: ';' expected
        return *this;
              ^
Main.java:89: error: illegal start of type
        return *this;
                ^
Main.java:89: error: <identifier> expected
        return *this;
                    ^
Main.java:89: error: ';' expected
        return *this;
                     ^
Main.java:92: error: <identifier> expected
    arg& required(bool b = true) noexcept
       ^
Main.java:92: error: invalid method declaration; return type required
    arg& required(bool b = true) noexcept
         ^
Main.java:92: error: ')' expected
    arg& required(bool b = true) noexcept
                        ^
Main.java:92: error: illegal start of type
    arg& required(bool b = true) noexcept
                           ^
Main.java:92: error: <identifier> expected
    arg& required(bool b = true) noexcept
                               ^
Main.java:92: error: ';' expected
    arg& required(bool b = true) noexcept
                                ^
Main.java:95: error: illegal start of expression
        return *this;
               ^
Main.java:98: error: illegal character: \35
#ifndef GEARS_NO_IOSTREAM
^
100 errors

#endif
