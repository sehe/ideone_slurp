// error:	OK
// langId:	44
// langName:	C++11
// langVersion:	gcc-4.8.1
// time:	0
// date:	2013-04-23 00:00:58
// status:	0
// result:	11
// memory:	0
// signal:	0
// public:	true
// ------------------------------------------------
#include <string>

namespace Foo
{
    bool operator ==(std::string const& s, int i) { return false; }
    bool operator ==(int i, std::string const& s) { return false; }
}


int main()
{
    //using namespace Foo;
    if  (std::string {} == 42)
    if  (42 == std::string {})
    {
    }
}


// ------------------------------------------------
#if 0 // stdin

#endif
#if 0 // stdout

#endif
#if 0 // stderr

#endif
#if 0 // cmpinfo
prog.cpp: In function ‘int main()’:
prog.cpp:13:28: error: no match for ‘operator==’ in ‘std::basic_string<char>() == 42’
prog.cpp:13:28: note: candidates are:
In file included from /usr/include/c++/4.7/string:54:0,
                 from prog.cpp:1:
/usr/include/c++/4.7/bits/basic_string.h:2516:5: note: template<class _CharT, class _Traits, class _Alloc> bool std::operator==(const std::basic_string<_CharT, _Traits, _Alloc>&, const _CharT*)
/usr/include/c++/4.7/bits/basic_string.h:2516:5: note:   template argument deduction/substitution failed:
prog.cpp:13:28: note:   mismatched types ‘const _CharT*’ and ‘int’
In file included from /usr/include/c++/4.7/string:54:0,
                 from prog.cpp:1:
/usr/include/c++/4.7/bits/basic_string.h:2504:5: note: template<class _CharT, class _Traits, class _Alloc> bool std::operator==(const _CharT*, const std::basic_string<_CharT, _Traits, _Alloc>&)
/usr/include/c++/4.7/bits/basic_string.h:2504:5: note:   template argument deduction/substitution failed:
prog.cpp:13:28: note:   mismatched types ‘const _CharT*’ and ‘std::basic_string<char>’
In file included from /usr/include/c++/4.7/string:54:0,
                 from prog.cpp:1:
/usr/include/c++/4.7/bits/basic_string.h:2490:5: note: template<class _CharT> typename __gnu_cxx::__enable_if<std::__is_char<_Tp>::__value, bool>::__type std::operator==(const std::basic_string<_CharT>&, const std::basic_string<_CharT>&)
/usr/include/c++/4.7/bits/basic_string.h:2490:5: note:   template argument deduction/substitution failed:
prog.cpp:13:28: note:   mismatched types ‘const std::basic_string<_CharT>’ and ‘int’
In file included from /usr/include/c++/4.7/string:54:0,
                 from prog.cpp:1:
/usr/include/c++/4.7/bits/basic_string.h:2483:5: note: template<class _CharT, class _Traits, class _Alloc> bool std::operator==(const std::basic_string<_CharT, _Traits, _Alloc>&, const std::basic_string<_CharT, _Traits, _Alloc>&)
/usr/include/c++/4.7/bits/basic_string.h:2483:5: note:   template argument deduction/substitution failed:
prog.cpp:13:28: note:   mismatched types ‘const std::basic_string<_CharT, _Traits, _Alloc>’ and ‘int’
In file included from /usr/include/c++/4.7/string:43:0,
                 from prog.cpp:1:
/usr/include/c++/4.7/bits/allocator.h:124:5: note: template<class _Tp> bool std::operator==(const std::allocator<_Tp1>&, const std::allocator<_Tp1>&)
/usr/include/c++/4.7/bits/allocator.h:124:5: note:   template argument deduction/substitution failed:
prog.cpp:13:28: note:   ‘std::basic_string<char>’ is not derived from ‘const std::allocator<_Tp1>’
In file included from /usr/include/c++/4.7/string:43:0,
                 from prog.cpp:1:
/usr/include/c++/4.7/bits/allocator.h:119:5: note: template<class _T1, class _T2> bool std::operator==(const std::allocator<_T1>&, const std::allocator<_T2>&)
/usr/include/c++/4.7/bits/allocator.h:119:5: note:   template argument deduction/substitution failed:
prog.cpp:13:28: note:   ‘std::basic_string<char>’ is not derived from ‘const std::allocator<_T1>’
In file included from /usr/include/c++/4.7/bits/char_traits.h:42:0,
                 from /usr/include/c++/4.7/string:42,
                 from prog.cpp:1:
/usr/include/c++/4.7/bits/postypes.h:218:5: note: template<class _StateT> bool std::operator==(const std::fpos<_StateT>&, const std::fpos<_StateT>&)
/usr/include/c++/4.7/bits/postypes.h:218:5: note:   template argument deduction/substitution failed:
prog.cpp:13:28: note:   ‘std::basic_string<char>’ is not derived from ‘const std::fpos<_StateT>’
In file included from /usr/include/c++/4.7/bits/stl_algobase.h:68:0,
                 from /usr/include/c++/4.7/bits/char_traits.h:41,
                 from /usr/include/c++/4.7/string:42,
                 from prog.cpp:1:
/usr/include/c++/4.7/bits/stl_iterator.h:1039:5: note: template<class _Iterator> bool std::operator==(const std::move_iterator<_Iterator>&, const std::move_iterator<_Iterator>&)
/usr/include/c++/4.7/bits/stl_iterator.h:1039:5: note:   template argument deduction/substitution failed:
prog.cpp:13:28: note:   ‘std::basic_string<char>’ is not derived from ‘const std::move_iterator<_Iterator>’
In file included from /usr/include/c++/4.7/bits/stl_algobase.h:68:0,
                 from /usr/include/c++/4.7/bits/char_traits.h:41,
                 from /usr/include/c++/4.7/string:42,
                 from prog.cpp:1:
/usr/include/c++/4.7/bits/stl_iterator.h:1033:5: note: template<class _IteratorL, class _IteratorR> bool std::operator==(const std::move_iterator<_IteratorL>&, const std::move_iterator<_IteratorR>&)
/usr/include/c++/4.7/bits/stl_iterator.h:1033:5: note:   template argument deduction/substitution failed:
prog.cpp:13:28: note:   ‘std::basic_string<char>’ is not derived from ‘const std::move_iterator<_IteratorL>’
In file included from /usr/include/c++/4.7/bits/stl_algobase.h:68:0,
                 from /usr/include/c++/4.7/bits/char_traits.h:41,
                 from /usr/include/c++/4.7/string:42,
                 from prog.cpp:1:
/usr/include/c++/4.7/bits/stl_iterator.h:343:5: note: template<class _IteratorL, class _IteratorR> bool std::operator==(const std::reverse_iterator<_IteratorL>&, const std::reverse_iterator<_IteratorR>&)
/usr/include/c++/4.7/bits/stl_iterator.h:343:5: note:   template argument deduction/substitution failed:
prog.cpp:13:28: note:   ‘std::basic_string<char>’ is not derived from ‘const std::reverse_iterator<_IteratorL>’
In file included from /usr/include/c++/4.7/bits/stl_algobase.h:68:0,
                 from /usr/include/c++/4.7/bits/char_traits.h:41,
                 from /usr/include/c++/4.7/string:42,
                 from prog.cpp:1:
/usr/include/c++/4.7/bits/stl_iterator.h:293:5: note: template<class _Iterator> bool std::operator==(const std::reverse_iterator<_Iterator>&, const std::reverse_iterator<_Iterator>&)
/usr/include/c++/4.7/bits/stl_iterator.h:293:5: note:   template argument deduction/substitution failed:
prog.cpp:13:28: note:   ‘std::basic_string<char>’ is not derived from ‘const std::reverse_iterator<_Iterator>’
In file included from /usr/include/c++/4.7/bits/stl_algobase.h:65:0,
                 from /usr/include/c++/4.7/bits/char_traits.h:41,
                 from /usr/include/c++/4.7/string:42,
                 from prog.cpp:1:
/usr/include/c++/4.7/bits/stl_pair.h:206:5: note: template<class _T1, class _T2> constexpr bool std::operator==(const std::pair<_T1, _T2>&, const std::pair<_T1, _T2>&)
/usr/include/c++/4.7/bits/stl_pair.h:206:5: note:   template argument deduction/substitution failed:
prog.cpp:13:28: note:   ‘std::basic_string<char>’ is not derived from ‘const std::pair<_T1, _T2>’
In file included from /usr/include/c++/4.7/i486-linux-gnu/bits/c++allocator.h:34:0,
                 from /usr/include/c++/4.7/bits/allocator.h:48,
                 from /usr/include/c++/4.7/string:43,
                 from prog.cpp:1:
/usr/include/c++/4.7/ext/new_allocator.h:129:5: note: template<class _Tp> bool __gnu_cxx::operator==(const __gnu_cxx::new_allocator<_Tp>&, const __gnu_cxx::new_allocator<_Tp>&)
/usr/include/c++/4.7/ext/new_allocator.h:129:5: note:   template argument deduction/substitution failed:
prog.cpp:13:28: note:   ‘std::basic_string<char>’ is not derived from ‘const __gnu_cxx::new_allocator<_Tp>’
In file included from /usr/include/c++/4.7/bits/stl_algobase.h:68:0,
                 from /usr/include/c++/4.7/bits/char_traits.h:41,
                 from /usr/include/c++/4.7/string:42,
                 from prog.cpp:1:
/usr/include/c++/4.7/bits/stl_iterator.h:813:5: note: template<class _Iterator, class _Container> bool __gnu_cxx::operator==(const __gnu_cxx::__normal_iterator<_Iterator, _Container>&, const __gnu_cxx::__normal_iterator<_Iterator, _Container>&)
/usr/include/c++/4.7/bits/stl_iterator.h:813:5: note:   template argument deduction/substitution failed:
prog.cpp:13:28: note:   ‘std::basic_string<char>’ is not derived from ‘const __gnu_cxx::__normal_iterator<_Iterator, _Container>’
In file included from /usr/include/c++/4.7/bits/stl_algobase.h:68:0,
                 from /usr/include/c++/4.7/bits/char_traits.h:41,
                 from /usr/include/c++/4.7/string:42,
                 from prog.cpp:1:
/usr/include/c++/4.7/bits/stl_iterator.h:807:5: note: template<class _IteratorL, class _IteratorR, class _Container> bool __gnu_cxx::operator==(const __gnu_cxx::__normal_iterator<_IteratorL, _Container>&, const __gnu_cxx::__normal_iterator<_IteratorR, _Container>&)
/usr/include/c++/4.7/bits/stl_iterator.h:807:5: note:   template argument deduction/substitution failed:
prog.cpp:13:28: note:   ‘std::basic_string<char>’ is not derived from ‘const __gnu_cxx::__normal_iterator<_IteratorL, _Container>’
prog.cpp:14:29: error: no match for ‘operator==’ in ‘42 == std::basic_string<char>()’
prog.cpp:14:29: note: candidates are:
In file included from /usr/include/c++/4.7/string:54:0,
                 from prog.cpp:1:
/usr/include/c++/4.7/bits/basic_string.h:2516:5: note: template<class _CharT, class _Traits, class _Alloc> bool std::operator==(const std::basic_string<_CharT, _Traits, _Alloc>&, const _CharT*)
/usr/include/c++/4.7/bits/basic_string.h:2516:5: note:   template argument deduction/substitution failed:
prog.cpp:14:29: note:   mismatched types ‘const std::basic_string<_CharT, _Traits, _Alloc>’ and ‘int’
In file included from /usr/include/c++/4.7/string:54:0,
                 from prog.cpp:1:
/usr/include/c++/4.7/bits/basic_string.h:2504:5: note: template<class _CharT, class _Traits, class _Alloc> bool std::operator==(const _CharT*, const std::basic_string<_CharT, _Traits, _Alloc>&)
/usr/include/c++/4.7/bits/basic_string.h:2504:5: note:   template argument deduction/substitution failed:
prog.cpp:14:29: note:   mismatched types ‘const _CharT*’ and ‘int’
In file included from /usr/include/c++/4.7/string:54:0,
                 from prog.cpp:1:
/usr/include/c++/4.7/bits/basic_string.h:2490:5: note: template<class _CharT> typename __gnu_cxx::__enable_if<std::__is_char<_Tp>::__value, bool>::__type std::operator==(const std::basic_string<_CharT>&, const std::basic_string<_CharT>&)
/usr/include/c++/4.7/bits/basic_string.h:2490:5: note:   template argument deduction/substitution failed:
prog.cpp:14:29: note:   mismatched types ‘const std::basic_string<_CharT>’ and ‘int’
In file included from /usr/include/c++/4.7/string:54:0,
                 from prog.cpp:1:
/usr/include/c++/4.7/bits/basic_string.h:2483:5: note: template<class _CharT, class _Traits, class _Alloc> bool std::operator==(const std::basic_string<_CharT, _Traits, _Alloc>&, const std::basic_string<_CharT, _Traits, _Alloc>&)
/usr/include/c++/4.7/bits/basic_string.h:2483:5: note:   template argument deduction/substitution failed:
prog.cpp:14:29: note:   mismatched types ‘const std::basic_string<_CharT, _Traits, _Alloc>’ and ‘int’
In file included from /usr/include/c++/4.7/string:43:0,
                 from prog.cpp:1:
/usr/include/c++/4.7/bits/allocator.h:124:5: note: template<class _Tp> bool std::operator==(const std::allocator<_Tp1>&, const std::allocator<_Tp1>&)
/usr/include/c++/4.7/bits/allocator.h:124:5: note:   template argument deduction/substitution failed:
prog.cpp:14:29: note:   mismatched types ‘const std::allocator<_Tp1>’ and ‘int’
In file included from /usr/include/c++/4.7/string:43:0,
                 from prog.cpp:1:
/usr/include/c++/4.7/bits/allocator.h:119:5: note: template<class _T1, class _T2> bool std::operator==(const std::allocator<_T1>&, const std::allocator<_T2>&)
/usr/include/c++/4.7/bits/allocator.h:119:5: note:   template argument deduction/substitution failed:
prog.cpp:14:29: note:   mismatched types ‘const std::allocator<_T1>’ and ‘int’
In file included from /usr/include/c++/4.7/bits/char_traits.h:42:0,
                 from /usr/include/c++/4.7/string:42,
                 from prog.cpp:1:
/usr/include/c++/4.7/bits/postypes.h:218:5: note: template<class _StateT> bool std::operator==(const std::fpos<_StateT>&, const std::fpos<_StateT>&)
/usr/include/c++/4.7/bits/postypes.h:218:5: note:   template argument deduction/substitution failed:
prog.cpp:14:29: note:   mismatched types ‘const std::fpos<_StateT>’ and ‘int’
In file included from /usr/include/c++/4.7/bits/stl_algobase.h:68:0,
                 from /usr/include/c++/4.7/bits/char_traits.h:41,
                 from /usr/include/c++/4.7/string:42,
                 from prog.cpp:1:
/usr/include/c++/4.7/bits/stl_iterator.h:1039:5: note: template<class _Iterator> bool std::operator==(const std::move_iterator<_Iterator>&, const std::move_iterator<_Iterator>&)
/usr/include/c++/4.7/bits/stl_iterator.h:1039:5: note:   template argument deduction/substitution failed:
prog.cpp:14:29: note:   mismatched types ‘const std::move_iterator<_Iterator>’ and ‘int’
In file included from /usr/include/c++/4.7/bits/stl_algobase.h:68:0,
                 from /usr/include/c++/4.7/bits/char_traits.h:41,
                 from /usr/include/c++/4.7/string:42,
                 from prog.cpp:1:
/usr/include/c++/4.7/bits/stl_iterator.h:1033:5: note: template<class _IteratorL, class _IteratorR> bool std::operator==(const std::move_iterator<_IteratorL>&, const std::move_iterator<_IteratorR>&)
/usr/include/c++/4.7/bits/stl_iterator.h:1033:5: note:   template argument deduction/substitution failed:
prog.cpp:14:29: note:   mismatched types ‘const std::move_iterator<_IteratorL>’ and ‘int’
In file included from /usr/include/c++/4.7/bits/stl_algobase.h:68:0,
                 from /usr/include/c++/4.7/bits/char_traits.h:41,
                 from /usr/include/c++/4.7/string:42,
                 from prog.cpp:1:
/usr/include/c++/4.7/bits/stl_iterator.h:343:5: note: template<class _IteratorL, class _IteratorR> bool std::operator==(const std::reverse_iterator<_IteratorL>&, const std::reverse_iterator<_IteratorR>&)
/usr/include/c++/4.7/bits/stl_iterator.h:343:5: note:   template argument deduction/substitution failed:
prog.cpp:14:29: note:   mismatched types ‘const std::reverse_iterator<_IteratorL>’ and ‘int’
In file included from /usr/include/c++/4.7/bits/stl_algobase.h:68:0,
                 from /usr/include/c++/4.7/bits/char_traits.h:41,
                 from /usr/include/c++/4.7/string:42,
                 from prog.cpp:1:
/usr/include/c++/4.7/bits/stl_iterator.h:293:5: note: template<class _Iterator> bool std::operator==(const std::reverse_iterator<_Iterator>&, const std::reverse_iterator<_Iterator>&)
/usr/include/c++/4.7/bits/stl_iterator.h:293:5: note:   template argument deduction/substitution failed:
prog.cpp:14:29: note:   mismatched types ‘const std::reverse_iterator<_Iterator>’ and ‘int’
In file included from /usr/include/c++/4.7/bits/stl_algobase.h:65:0,
                 from /usr/include/c++/4.7/bits/char_traits.h:41,
                 from /usr/include/c++/4.7/string:42,
                 from prog.cpp:1:
/usr/include/c++/4.7/bits/stl_pair.h:206:5: note: template<class _T1, class _T2> constexpr bool std::operator==(const std::pair<_T1, _T2>&, const std::pair<_T1, _T2>&)
/usr/include/c++/4.7/bits/stl_pair.h:206:5: note:   template argument deduction/substitution failed:
prog.cpp:14:29: note:   mismatched types ‘const std::pair<_T1, _T2>’ and ‘int’
In file included from /usr/include/c++/4.7/i486-linux-gnu/bits/c++allocator.h:34:0,
                 from /usr/include/c++/4.7/bits/allocator.h:48,
                 from /usr/include/c++/4.7/string:43,
                 from prog.cpp:1:
/usr/include/c++/4.7/ext/new_allocator.h:129:5: note: template<class _Tp> bool __gnu_cxx::operator==(const __gnu_cxx::new_allocator<_Tp>&, const __gnu_cxx::new_allocator<_Tp>&)
/usr/include/c++/4.7/ext/new_allocator.h:129:5: note:   template argument deduction/substitution failed:
prog.cpp:14:29: note:   mismatched types ‘const __gnu_cxx::new_allocator<_Tp>’ and ‘int’
In file included from /usr/include/c++/4.7/bits/stl_algobase.h:68:0,
                 from /usr/include/c++/4.7/bits/char_traits.h:41,
                 from /usr/include/c++/4.7/string:42,
                 from prog.cpp:1:
/usr/include/c++/4.7/bits/stl_iterator.h:813:5: note: template<class _Iterator, class _Container> bool __gnu_cxx::operator==(const __gnu_cxx::__normal_iterator<_Iterator, _Container>&, const __gnu_cxx::__normal_iterator<_Iterator, _Container>&)
/usr/include/c++/4.7/bits/stl_iterator.h:813:5: note:   template argument deduction/substitution failed:
prog.cpp:14:29: note:   mismatched types ‘const __gnu_cxx::__normal_iterator<_Iterator, _Container>’ and ‘int’
In file included from /usr/include/c++/4.7/bits/stl_algobase.h:68:0,
                 from /usr/include/c++/4.7/bits/char_traits.h:41,
                 from /usr/include/c++/4.7/string:42,
                 from prog.cpp:1:
/usr/include/c++/4.7/bits/stl_iterator.h:807:5: note: template<class _IteratorL, class _IteratorR, class _Container> bool __gnu_cxx::operator==(const __gnu_cxx::__normal_iterator<_IteratorL, _Container>&, const __gnu_cxx::__normal_iterator<_IteratorR, _Container>&)
/usr/include/c++/4.7/bits/stl_iterator.h:807:5: note:   template argument deduction/substitution failed:
prog.cpp:14:29: note:   mismatched types ‘const __gnu_cxx::__normal_iterator<_IteratorL, _Container>’ and ‘int’

#endif
