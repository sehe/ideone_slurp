// error:	OK
// langId:	44
// langName:	C++11
// langVersion:	gcc-4.8.1
// time:	0
// date:	2011-11-22 10:23:05
// status:	0
// result:	11
// memory:	0
// signal:	0
// public:	false
// ------------------------------------------------
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

typedef char myarray[9][9];
typedef string string_array[9][9];

void function2(vector<string_array>*my_3d_string_array, int d)
{
	string::iterator it;
	int j,cl;
	it=find((*my_3d_string_array)[d][j][cl].begin(),(*my_3d_string_array)[d][j][cl].end(),3);
	(*my_3d_string_array)[d][2][3].erase(it);
}

void function(vector<string_array>*my_3d_string_array, int d)
{
	(*my_3d_string_array)[d][3][4] = 2;
	function2(my_3d_string_array,d);
}

int main()
{
	myarray matrix;
	string_array string_matrix;

	std::vector<myarray>      my_3d_array;
	std::vector<string_array> my_3d_string_array;

	// fill_matrix(matrix);
	// fill_string_matrix(string_matrix)

	int d;
	function(&my_3d_string_array, d); // passing pointer to vector to a function d is the 3rd dimention

	my_3d_array.push_back(matrix);
	my_3d_string_array.push_back(string_matrix);
}

// ------------------------------------------------
#if 0 // stdin

#endif
#if 0 // stdout

#endif
#if 0 // stderr

#endif
#if 0 // cmpinfo
In file included from /usr/lib/gcc/i686-pc-linux-gnu/4.5.1/../../../../include/c++/4.5.1/i686-pc-linux-gnu/bits/c++allocator.h:34:0,
                 from /usr/lib/gcc/i686-pc-linux-gnu/4.5.1/../../../../include/c++/4.5.1/bits/allocator.h:48,
                 from /usr/lib/gcc/i686-pc-linux-gnu/4.5.1/../../../../include/c++/4.5.1/vector:62,
                 from prog.cpp:1:
/usr/lib/gcc/i686-pc-linux-gnu/4.5.1/../../../../include/c++/4.5.1/ext/new_allocator.h: In member function 'void __gnu_cxx::new_allocator<_Tp>::construct(_Tp*, const _Tp&) [with _Tp = char [9][9], _Tp* = char (*)[9][9]]':
/usr/lib/gcc/i686-pc-linux-gnu/4.5.1/../../../../include/c++/4.5.1/bits/stl_vector.h:745:6:   instantiated from 'void std::vector<_Tp, _Alloc>::push_back(const value_type&) [with _Tp = char [9][9], _Alloc = std::allocator<char [9][9]>, value_type = char [9][9]]'
prog.cpp:38:30:   instantiated from here
/usr/lib/gcc/i686-pc-linux-gnu/4.5.1/../../../../include/c++/4.5.1/ext/new_allocator.h:105:9: error: ISO C++ forbids initialization in array new
In file included from /usr/lib/gcc/i686-pc-linux-gnu/4.5.1/../../../../include/c++/4.5.1/vector:69:0,
                 from prog.cpp:1:
/usr/lib/gcc/i686-pc-linux-gnu/4.5.1/../../../../include/c++/4.5.1/bits/vector.tcc: In member function 'void std::vector<_Tp, _Alloc>::_M_insert_aux(std::vector<_Tp, _Alloc>::iterator, _Args&& ...) [with _Args = {const char (&)[9][9]}, _Tp = char [9][9], _Alloc = std::allocator<char [9][9]>, std::vector<_Tp, _Alloc>::iterator = __gnu_cxx::__normal_iterator<char (*)[9][9], std::vector<char [9][9]> >, typename std::vector<_Tp, _Alloc>::_Base::_Tp_alloc_type::pointer = char (*)[9][9]]':
/usr/lib/gcc/i686-pc-linux-gnu/4.5.1/../../../../include/c++/4.5.1/bits/stl_vector.h:749:4:   instantiated from 'void std::vector<_Tp, _Alloc>::push_back(const value_type&) [with _Tp = char [9][9], _Alloc = std::allocator<char [9][9]>, value_type = char [9][9]]'
prog.cpp:38:30:   instantiated from here
/usr/lib/gcc/i686-pc-linux-gnu/4.5.1/../../../../include/c++/4.5.1/bits/vector.tcc:314:4: error: ISO C++ forbids casting to an array type 'char [9][9]'
In file included from /usr/lib/gcc/i686-pc-linux-gnu/4.5.1/../../../../include/c++/4.5.1/i686-pc-linux-gnu/bits/c++allocator.h:34:0,
                 from /usr/lib/gcc/i686-pc-linux-gnu/4.5.1/../../../../include/c++/4.5.1/bits/allocator.h:48,
                 from /usr/lib/gcc/i686-pc-linux-gnu/4.5.1/../../../../include/c++/4.5.1/vector:62,
                 from prog.cpp:1:
/usr/lib/gcc/i686-pc-linux-gnu/4.5.1/../../../../include/c++/4.5.1/ext/new_allocator.h: In member function 'void __gnu_cxx::new_allocator<_Tp>::construct(_Tp*, const _Tp&) [with _Tp = std::basic_string<char> [9][9], _Tp* = std::basic_string<char> (*)[9][9]]':
/usr/lib/gcc/i686-pc-linux-gnu/4.5.1/../../../../include/c++/4.5.1/bits/stl_vector.h:745:6:   instantiated from 'void std::vector<_Tp, _Alloc>::push_back(const value_type&) [with _Tp = std::basic_string<char> [9][9], _Alloc = std::allocator<std::basic_string<char> [9][9]>, value_type = std::basic_string<char> [9][9]]'
prog.cpp:39:44:   instantiated from here
/usr/lib/gcc/i686-pc-linux-gnu/4.5.1/../../../../include/c++/4.5.1/ext/new_allocator.h:105:9: error: ISO C++ forbids initialization in array new
/usr/lib/gcc/i686-pc-linux-gnu/4.5.1/../../../../include/c++/4.5.1/ext/new_allocator.h:105:9: sorry, unimplemented: cannot initialize multi-dimensional array with initializer
In file included from /usr/lib/gcc/i686-pc-linux-gnu/4.5.1/../../../../include/c++/4.5.1/vector:69:0,
                 from prog.cpp:1:
/usr/lib/gcc/i686-pc-linux-gnu/4.5.1/../../../../include/c++/4.5.1/bits/vector.tcc: In member function 'void std::vector<_Tp, _Alloc>::_M_insert_aux(std::vector<_Tp, _Alloc>::iterator, _Args&& ...) [with _Args = {const std::basic_string<char> (&)[9][9]}, _Tp = std::basic_string<char> [9][9], _Alloc = std::allocator<std::basic_string<char> [9][9]>, std::vector<_Tp, _Alloc>::iterator = __gnu_cxx::__normal_iterator<std::basic_string<char> (*)[9][9], std::vector<std::basic_string<char> [9][9]> >, typename std::vector<_Tp, _Alloc>::_Base::_Tp_alloc_type::pointer = std::basic_string<char> (*)[9][9]]':
/usr/lib/gcc/i686-pc-linux-gnu/4.5.1/../../../../include/c++/4.5.1/bits/stl_vector.h:749:4:   instantiated from 'void std::vector<_Tp, _Alloc>::push_back(const value_type&) [with _Tp = std::basic_string<char> [9][9], _Alloc = std::allocator<std::basic_string<char> [9][9]>, value_type = std::basic_string<char> [9][9]]'
prog.cpp:39:44:   instantiated from here
/usr/lib/gcc/i686-pc-linux-gnu/4.5.1/../../../../include/c++/4.5.1/bits/vector.tcc:314:4: error: ISO C++ forbids casting to an array type 'std::basic_string<char> [9][9]'
In file included from /usr/lib/gcc/i686-pc-linux-gnu/4.5.1/../../../../include/c++/4.5.1/i686-pc-linux-gnu/bits/c++allocator.h:34:0,
                 from /usr/lib/gcc/i686-pc-linux-gnu/4.5.1/../../../../include/c++/4.5.1/bits/allocator.h:48,
                 from /usr/lib/gcc/i686-pc-linux-gnu/4.5.1/../../../../include/c++/4.5.1/vector:62,
                 from prog.cpp:1:
/usr/lib/gcc/i686-pc-linux-gnu/4.5.1/../../../../include/c++/4.5.1/ext/new_allocator.h: In member function 'void __gnu_cxx::new_allocator<_Tp>::construct(_Tp*, _Args&& ...) [with _Args = {char [9][9]}, _Tp = char [9][9], _Tp* = char (*)[9][9]]':
/usr/lib/gcc/i686-pc-linux-gnu/4.5.1/../../../../include/c++/4.5.1/bits/vector.tcc:301:4:   instantiated from 'void std::vector<_Tp, _Alloc>::_M_insert_aux(std::vector<_Tp, _Alloc>::iterator, _Args&& ...) [with _Args = {const char (&)[9][9]}, _Tp = char [9][9], _Alloc = std::allocator<char [9][9]>, std::vector<_Tp, _Alloc>::iterator = __gnu_cxx::__normal_iterator<char (*)[9][9], std::vector<char [9][9]> >, typename std::vector<_Tp, _Alloc>::_Base::_Tp_alloc_type::pointer = char (*)[9][9]]'
/usr/lib/gcc/i686-pc-linux-gnu/4.5.1/../../../../include/c++/4.5.1/bits/stl_vector.h:749:4:   instantiated from 'void std::vector<_Tp, _Alloc>::push_back(const value_type&) [with _Tp = char [9][9], _Alloc = std::allocator<char [9][9]>, value_type = char [9][9]]'
prog.cpp:38:30:   instantiated from here
/usr/lib/gcc/i686-pc-linux-gnu/4.5.1/../../../../include/c++/4.5.1/ext/new_allocator.h:111:4: error: ISO C++ forbids initialization in array new
/usr/lib/gcc/i686-pc-linux-gnu/4.5.1/../../../../include/c++/4.5.1/ext/new_allocator.h: In member function 'void __gnu_cxx::new_allocator<_Tp>::destroy(_Tp*) [with _Tp = char [9][9], _Tp* = char (*)[9][9]]':
/usr/lib/gcc/i686-pc-linux-gnu/4.5.1/../../../../include/c++/4.5.1/bits/vector.tcc:353:3:   instantiated from 'void std::vector<_Tp, _Alloc>::_M_insert_aux(std::vector<_Tp, _Alloc>::iterator, _Args&& ...) [with _Args = {const char (&)[9][9]}, _Tp = char [9][9], _Alloc = std::allocator<char [9][9]>, std::vector<_Tp, _Alloc>::iterator = __gnu_cxx::__normal_iterator<char (*)[9][9], std::vector<char [9][9]> >, typename std::vector<_Tp, _Alloc>::_Base::_Tp_alloc_type::pointer = char (*)[9][9]]'
/usr/lib/gcc/i686-pc-linux-gnu/4.5.1/../../../../include/c++/4.5.1/bits/stl_vector.h:749:4:   instantiated from 'void std::vector<_Tp, _Alloc>::push_back(const value_type&) [with _Tp = char [9][9], _Alloc = std::allocator<char [9][9]>, value_type = char [9][9]]'
prog.cpp:38:30:   instantiated from here
/usr/lib/gcc/i686-pc-linux-gnu/4.5.1/../../../../include/c++/4.5.1/ext/new_allocator.h:115:30: error: request for member '~char [9][9]' in '* __p', which is of non-class type 'char [9][9]'
/usr/lib/gcc/i686-pc-linux-gnu/4.5.1/../../../../include/c++/4.5.1/ext/new_allocator.h: In member function 'void __gnu_cxx::new_allocator<_Tp>::construct(_Tp*, _Args&& ...) [with _Args = {std::basic_string<char> [9][9]}, _Tp = std::basic_string<char> [9][9], _Tp* = std::basic_string<char> (*)[9][9]]':
/usr/lib/gcc/i686-pc-linux-gnu/4.5.1/../../../../include/c++/4.5.1/bits/vector.tcc:301:4:   instantiated from 'void std::vector<_Tp, _Alloc>::_M_insert_aux(std::vector<_Tp, _Alloc>::iterator, _Args&& ...) [with _Args = {const std::basic_string<char> (&)[9][9]}, _Tp = std::basic_string<char> [9][9], _Alloc = std::allocator<std::basic_string<char> [9][9]>, std::vector<_Tp, _Alloc>::iterator = __gnu_cxx::__normal_iterator<std::basic_string<char> (*)[9][9], std::vector<std::basic_string<char> [9][9]> >, typename std::vector<_Tp, _Alloc>::_Base::_Tp_alloc_type::pointer = std::basic_string<char> (*)[9][9]]'
/usr/lib/gcc/i686-pc-linux-gnu/4.5.1/../../../../include/c++/4.5.1/bits/stl_vector.h:749:4:   instantiated from 'void std::vector<_Tp, _Alloc>::push_back(const value_type&) [with _Tp = std::basic_string<char> [9][9], _Alloc = std::allocator<std::basic_string<char> [9][9]>, value_type = std::basic_string<char> [9][9]]'
prog.cpp:39:44:   instantiated from here
/usr/lib/gcc/i686-pc-linux-gnu/4.5.1/../../../../include/c++/4.5.1/ext/new_allocator.h:111:4: error: ISO C++ forbids initialization in array new
/usr/lib/gcc/i686-pc-linux-gnu/4.5.1/../../../../include/c++/4.5.1/ext/new_allocator.h:111:4: sorry, unimplemented: cannot initialize multi-dimensional array with initializer
/usr/lib/gcc/i686-pc-linux-gnu/4.5.1/../../../../include/c++/4.5.1/ext/new_allocator.h: In member function 'void __gnu_cxx::new_allocator<_Tp>::destroy(_Tp*) [with _Tp = std::basic_string<char> [9][9], _Tp* = std::basic_string<char> (*)[9][9]]':
/usr/lib/gcc/i686-pc-linux-gnu/4.5.1/../../../../include/c++/4.5.1/bits/vector.tcc:353:3:   instantiated from 'void std::vector<_Tp, _Alloc>::_M_insert_aux(std::vector<_Tp, _Alloc>::iterator, _Args&& ...) [with _Args = {const std::basic_string<char> (&)[9][9]}, _Tp = std::basic_string<char> [9][9], _Alloc = std::allocator<std::basic_string<char> [9][9]>, std::vector<_Tp, _Alloc>::iterator = __gnu_cxx::__normal_iterator<std::basic_string<char> (*)[9][9], std::vector<std::basic_string<char> [9][9]> >, typename std::vector<_Tp, _Alloc>::_Base::_Tp_alloc_type::pointer = std::basic_string<char> (*)[9][9]]'
/usr/lib/gcc/i686-pc-linux-gnu/4.5.1/../../../../include/c++/4.5.1/bits/stl_vector.h:749:4:   instantiated from 'void std::vector<_Tp, _Alloc>::push_back(const value_type&) [with _Tp = std::basic_string<char> [9][9], _Alloc = std::allocator<std::basic_string<char> [9][9]>, value_type = std::basic_string<char> [9][9]]'
prog.cpp:39:44:   instantiated from here
/usr/lib/gcc/i686-pc-linux-gnu/4.5.1/../../../../include/c++/4.5.1/ext/new_allocator.h:115:30: error: request for member '~std::basic_string<char> [9][9]' in '* __p', which is of non-class type 'std::basic_string<char> [9][9]'
In file included from /usr/lib/gcc/i686-pc-linux-gnu/4.5.1/../../../../include/c++/4.5.1/vector:63:0,
                 from prog.cpp:1:
/usr/lib/gcc/i686-pc-linux-gnu/4.5.1/../../../../include/c++/4.5.1/bits/stl_construct.h: In function 'void std::_Destroy(_Tp*) [with _Tp = std::basic_string<char> [9][9]]':
/usr/lib/gcc/i686-pc-linux-gnu/4.5.1/../../../../include/c++/4.5.1/bits/stl_construct.h:99:6:   instantiated from 'static void std::_Destroy_aux<<anonymous> >::__destroy(_ForwardIterator, _ForwardIterator) [with _ForwardIterator = std::basic_string<char> (*)[9][9], bool <anonymous> = false]'
/usr/lib/gcc/i686-pc-linux-gnu/4.5.1/../../../../include/c++/4.5.1/bits/stl_construct.h:122:7:   instantiated from 'void std::_Destroy(_ForwardIterator, _ForwardIterator) [with _ForwardIterator = std::basic_string<char> (*)[9][9]]'
/usr/lib/gcc/i686-pc-linux-gnu/4.5.1/../../../../include/c++/4.5.1/bits/stl_construct.h:148:7:   instantiated from 'void std::_Destroy(_ForwardIterator, _ForwardIterator, std::allocator<_T2>&) [with _ForwardIterator = std::basic_string<char> (*)[9][9], _Tp = std::basic_string<char> [9][9]]'
/usr/lib/gcc/i686-pc-linux-gnu/4.5.1/../../../../include/c++/4.5.1/bits/stl_vector.h:313:9:   instantiated from 'std::vector<_Tp, _Alloc>::~vector() [with _Tp = std::basic_string<char> [9][9], _Alloc = std::allocator<std::basic_string<char> [9][9]>]'
prog.cpp:30:28:   instantiated from here
/usr/lib/gcc/i686-pc-linux-gnu/4.5.1/../../../../include/c++/4.5.1/bits/stl_construct.h:89:7: error: request for member '~std::basic_string<char> [9][9]' in '* __pointer', which is of non-class type 'std::basic_string<char> [9][9]'
In file included from /usr/lib/gcc/i686-pc-linux-gnu/4.5.1/../../../../include/c++/4.5.1/vector:61:0,
                 from prog.cpp:1:
/usr/lib/gcc/i686-pc-linux-gnu/4.5.1/../../../../include/c++/4.5.1/bits/stl_algobase.h: In static member function 'static _BI2 std::__copy_move_backward<true, false, std::random_access_iterator_tag>::__copy_move_b(_BI1, _BI1, _BI2) [with _BI1 = std::basic_string<char> (*)[9][9], _BI2 = std::basic_string<char> (*)[9][9]]':
/usr/lib/gcc/i686-pc-linux-gnu/4.5.1/../../../../include/c++/4.5.1/bits/stl_algobase.h:601:18:   instantiated from '_BI2 std::__copy_move_backward_a(_BI1, _BI1, _BI2) [with bool _IsMove = true, _BI1 = std::basic_string<char> (*)[9][9], _BI2 = std::basic_string<char> (*)[9][9]]'
/usr/lib/gcc/i686-pc-linux-gnu/4.5.1/../../../../include/c++/4.5.1/bits/stl_algobase.h:610:34:   instantiated from '_BI2 std::__copy_move_backward_a2(_BI1, _BI1, _BI2) [with bool _IsMove = true, _BI1 = std::basic_string<char> (*)[9][9], _BI2 = std::basic_string<char> (*)[9][9]]'
/usr/lib/gcc/i686-pc-linux-gnu/4.5.1/../../../../include/c++/4.5.1/bits/stl_algobase.h:681:15:   instantiated from '_BI2 std::move_backward(_BI1, _BI1, _BI2) [with _BI1 = std::basic_string<char> (*)[9][9], _BI2 = std::basic_string<char> (*)[9][9]]'
/usr/lib/gcc/i686-pc-linux-gnu/4.5.1/../../../../include/c++/4.5.1/bits/vector.tcc:308:4:   instantiated from 'void std::vector<_Tp, _Alloc>::_M_insert_aux(std::vector<_Tp, _Alloc>::iterator, _Args&& ...) [with _Args = {const std::basic_string<char> (&)[9][9]}, _Tp = std::basic_string<char> [9][9], _Alloc = std::allocator<std::basic_string<char> [9][9]>, std::vector<_Tp, _Alloc>::iterator = __gnu_cxx::__normal_iterator<std::basic_string<char> (*)[9][9], std::vector<std::basic_string<char> [9][9]> >, typename std::vector<_Tp, _Alloc>::_Base::_Tp_alloc_type::pointer = std::basic_string<char> (*)[9][9]]'
/usr/lib/gcc/i686-pc-linux-gnu/4.5.1/../../../../include/c++/4.5.1/bits/stl_vector.h:749:4:   instantiated from 'void std::vector<_Tp, _Alloc>::push_back(const value_type&) [with _Tp = std::basic_string<char> [9][9], _Alloc = std::allocator<std::basic_string<char> [9][9]>, value_type = std::basic_string<char> [9][9]]'
prog.cpp:39:44:   instantiated from here
/usr/lib/gcc/i686-pc-linux-gnu/4.5.1/../../../../include/c++/4.5.1/bits/stl_algobase.h:566:6: error: invalid array assignment
In file included from /usr/lib/gcc/i686-pc-linux-gnu/4.5.1/../../../../include/c++/4.5.1/vector:63:0,
                 from prog.cpp:1:
/usr/lib/gcc/i686-pc-linux-gnu/4.5.1/../../../../include/c++/4.5.1/bits/stl_construct.h: In function 'void std::_Construct(_T1*, _T2&&) [with _T1 = std::basic_string<char> [9][9], _T2 = std::basic_string<char> [9][9]]':
/usr/lib/gcc/i686-pc-linux-gnu/4.5.1/../../../../include/c++/4.5.1/bits/stl_uninitialized.h:74:3:   instantiated from 'static _ForwardIterator std::__uninitialized_copy<<anonymous> >::uninitialized_copy(_InputIterator, _InputIterator, _ForwardIterator) [with _InputIterator = std::move_iterator<std::basic_string<char> (*)[9][9]>, _ForwardIterator = std::basic_string<char> (*)[9][9], bool <anonymous> = false]'
/usr/lib/gcc/i686-pc-linux-gnu/4.5.1/../../../../include/c++/4.5.1/bits/stl_uninitialized.h:116:46:   instantiated from '_ForwardIterator std::uninitialized_copy(_InputIterator, _InputIterator, _ForwardIterator) [with _InputIterator = std::move_iterator<std::basic_string<char> (*)[9][9]>, _ForwardIterator = std::basic_string<char> (*)[9][9]]'
/usr/lib/gcc/i686-pc-linux-gnu/4.5.1/../../../../include/c++/4.5.1/bits/stl_uninitialized.h:318:63:   instantiated from '_ForwardIterator std::__uninitialized_copy_a(_InputIterator, _InputIterator, _ForwardIterator, std::allocator<_Tp>&) [with _InputIterator = std::move_iterator<std::basic_string<char> (*)[9][9]>, _ForwardIterator = std::basic_string<char> (*)[9][9], _Tp = std::basic_string<char> [9][9]]'
/usr/lib/gcc/i686-pc-linux-gnu/4.5.1/../../../../include/c++/4.5.1/bits/stl_uninitialized.h:328:24:   instantiated from '_ForwardIterator std::__uninitialized_move_a(_InputIterator, _InputIterator, _ForwardIterator, _Allocator&) [with _InputIterator = std::basic_string<char> (*)[9][9], _ForwardIterator = std::basic_string<char> (*)[9][9], _Allocator = std::allocator<std::basic_string<char> [9][9]>]'
/usr/lib/gcc/i686-pc-linux-gnu/4.5.1/../../../../include/c++/4.5.1/bits/vector.tcc:338:8:   instantiated from 'void std::vector<_Tp, _Alloc>::_M_insert_aux(std::vector<_Tp, _Alloc>::iterator, _Args&& ...) [with _Args = {const std::basic_string<char> (&)[9][9]}, _Tp = std::basic_string<char> [9][9], _Alloc = std::allocator<std::basic_string<char> [9][9]>, std::vector<_Tp, _Alloc>::iterator = __gnu_cxx::__normal_iterator<std::basic_string<char> (*)[9][9], std::vector<std::basic_string<char> [9][9]> >, typename std::vector<_Tp, _Alloc>::_Base::_Tp_alloc_type::pointer = std::basic_string<char> (*)[9][9]]'
/usr/lib/gcc/i686-pc-linux-gnu/4.5.1/../../../../include/c++/4.5.1/bits/stl_vector.h:749:4:   instantiated from 'void std::vector<_Tp, _Alloc>::push_back(const value_type&) [with _Tp = std::basic_string<char> [9][9], _Alloc = std::allocator<std::basic_string<char> [9][9]>, value_type = std::basic_string<char> [9][9]]'
prog.cpp:39:44:   instantiated from here
/usr/lib/gcc/i686-pc-linux-gnu/4.5.1/../../../../include/c++/4.5.1/bits/stl_construct.h:80:7: error: ISO C++ forbids initialization in array new
/usr/lib/gcc/i686-pc-linux-gnu/4.5.1/../../../../include/c++/4.5.1/bits/stl_construct.h:80:7: sorry, unimplemented: cannot initialize multi-dimensional array with initializer

#endif
