// error:	OK
// langId:	1
// langName:	C++ 4.8.1
// langVersion:	gcc-4.8.1
// time:	0
// date:	2012-08-31 21:04:41
// status:	0
// result:	11
// memory:	0
// signal:	0
// public:	false
// ------------------------------------------------
#include <algorithm>
#include <cassert>
#include <functional>
#include <iostream>
#include <iterator>
#include <map>
#include <string>
#include <type_traits>
#include <vector>

void startClock() {}
double getClock()
{
    return 0;
};

// ------------ QUICK SORT ------------------
template<typename T, typename key_compare>
void quicksort( T first, T last, const size_t pivot_index, key_compare comp )
{
    T saved_first = first;
    size_t N = last - first;
    if (N > 1)
    {
        // create a temp new array, which contains all items less than pivot
        // on left and greater on right. With pivot value in between.
        // vector<typename decltype(*T)> temp(N);
        typename std::iterator_traits<T>::pointer temp = (typename std::iterator_traits<T>::pointer) malloc(sizeof(T)*N);
        size_t left_index = 0, right_index = N - 1 ;
        typename std::iterator_traits<T>::value_type pivot_val = *(first + pivot_index);
        for(; first < saved_first + pivot_index; first++)
        {
            if( !comp(*first, pivot_val) )
            {
                temp[right_index--] = *first;
            }
            else
            {
                temp[left_index++] = *first;
            }
        }
        // skip the pivot value
        // TODO: swap the pivot to end so we can have a single loop instead.
        ++first;
        // do the rest
        for(; first < last; first++)
        {
            if( !comp(*first, pivot_val) )
            {
                temp[right_index--] = *first;
            }
            else
            {
                temp[left_index++] = *first;
            }
        }
        if( right_index == left_index )
        {
            temp[left_index] = pivot_val;
        }
        else
        {
            temp[left_index+1] = pivot_val;
        }
        // recurse for left and right..
        quicksort(temp, temp+left_index, left_index/2, comp);
        quicksort(temp+left_index+1, temp+N, (N-right_index)/2, comp);

        // return a concat'd array..
        for(size_t i = 0; i < N; i++)
        {
            *saved_first++ = temp[i];
        }

        free(temp);
    }
}
/*
** best, average, worst: n log n, n log n, n^2
** space: log n
*/
template<typename T, typename key_compare >
void quicksort( T first, T last, key_compare comp )
{
    size_t pivot_index = (last - first) / 2;
    quicksort( first, last, pivot_index, comp);
}

// ------------ QUICK with optimizations ------------------
/*
quicksort partition on range [first, last[ using predicate function as the comparator.
"mid" is in-out param, function uses mid as mid, and updates it before returning it with
current/new mid position after partitioning.
*/
template<typename T, typename key_compare >
void _partial_quicksort_partition( T first, T last, T& mid, key_compare comp )
{
    T savedFirst = first;
    typedef typename std::iterator_traits<T>::value_type _val_type;
    size_t N = last - first;
    _val_type *temp = (_val_type *) malloc((N*sizeof(_val_type)));

    // move pivot to the end..
    _val_type pivot_val = *mid;
    std::swap(*mid, *(last - 1));
    size_t left_index = 0, right_index = N - 1;

    for( ; first != last - 1; first++ )
    {
        if( !comp(*first, pivot_val) )
        {
            temp[right_index--] = *first;
        }
        else
        {
            temp[left_index++] = *first;
        }
    }

    assert( right_index == left_index );

    temp[left_index] = pivot_val;

    std::copy(temp, temp+N, savedFirst);
    free(temp);
    mid = savedFirst + left_index;
}

template<typename T, typename key_compare >
void _partial_quicksort( T first, T last, key_compare comp )
{
    size_t s = last - first;
    // sort only if the list is smaller than our limit.. else it's too small for
    // us to bother.. caller would take care of it using some other stupid algo..
    if( 16 > s )
    {
        // only one call to insertion_sort(), after whole array is partially sorted
        // using quicksort().
        // insertion_sort(first, last, pred);
        return ;
    }

    // select pivot.. use median 3
    T mid = median3(first, last - 1, s, comp);
    // partition
    _partial_quicksort_partition(first, last, mid, comp);
    // recurse..
    _partial_quicksort(first, mid, comp);
    // tail recurse..
    // TODO: tail recurse on longer partition..
    _partial_quicksort(mid+1, last, comp);
}

template<typename T, typename key_compare >
void mixed_quicksort( T first, T last, key_compare pred )
{
    _partial_quicksort(first, last, pred );
    insertion_sort(first, last, pred);
}

// ------------ "in place" QUICK with optimizations ------------------
/*
in place quicksort partition on range [first, last[ using predicate function as the comparator.
"mid" is in-out param, function uses mid as mid, and updates it before returning it with
current/new mid position after partitioning.
*/
template<typename T, typename key_compare >
void _partial_inplace_quicksort_partition( T first, T last, T& mid, key_compare comp )
{
    typename std::iterator_traits<T>::value_type midVal = *mid;
    // move pivot to end..
    std::swap(*mid, *(last - 1));
    mid = first;
    // in-place quick sort:
    for( ; first < last - 1; first++ )
    {
        if( comp(*first, midVal) )
        {
            std::swap(*first, *mid);
            mid++;
        }
    }
    // bring pivot to the mid..
    std::swap(*mid, *(last - 1));
}

// brings best median to middle and returns it..
// works on array as [first, last] NOT [first, last[
template<typename T, typename key_compare >
T median3(T first, T last, size_t size, key_compare comp )
{
    T mid = first + size/2;
    if (comp(*mid, *first))
    {
        std::swap(*mid, *first);
    }
    if (comp(*last, *mid))
    {
        std::swap(*last, *mid);
    }
    if (comp(*mid, *first))
    {
        std::swap(*mid, *first);
    }
    return mid;
}

template<typename T, typename key_compare >
void _partial_inplace_quicksort( T first, T last, key_compare comp )
{
    size_t s = last - first;
    // sort only if the list is smaller than our limit.. else it's too small for
    // us to bother.. caller would take care of it using some other stupid algo..
    if( 16 > s )
    {
        // only one call to insertion_sort(), after whole array is partially sorted
        // using quicksort().
        // insertion_sort(first, last, pred);
        return ;
    }

    // select pivot.. use median 3
    T mid = median3(first, last - 1, s, comp);
    // partition
    _partial_inplace_quicksort_partition(first, last, mid, comp);
    // recurse..
    _partial_inplace_quicksort(first, mid, comp);
    // tail recurse..
    _partial_inplace_quicksort(mid+1, last, comp);
    // print_array(first, last, "_partial_inplace_quicksort(exit2)" );
}

// ---------------- INSERTION SORT used above ----------------

template<typename T, typename key_compare>
void insertion_sort( T first, T last, key_compare comp )
{
    // for each element in the array [first+1, last[
    for( T j = first+1; j < last; j++)
    {
        typename std::iterator_traits<T>::value_type curr = *j;
        T hole = j;
        // keep moving all the elements comp(hole.e. > or <) hole to right
        while( hole > first && comp(curr, *(hole-1)) )
        {
            *hole = *(hole-1);
            --hole;
        }
        // insert curr at the correct position.
        *hole = curr;
    }
}

template<typename T, typename key_compare = std::less<T>>
class MySortAlgoTester
{
    key_compare comp;
    std::vector<T> vec;
    typedef typename std::vector<T>::iterator vecIter;
    std::vector<T> vec_copy;
    size_t m_numElements;
    bool is_sorted(vecIter first, vecIter last)
    {
        vecIter sFirst = first;
        for(vecIter next = first+1; next != last;)
            // '>' associativity: left to right
            // ++ has precedence over >
            if( !comp(*(first++), *(next++)) )
            {
                if(*(next-1) == *(first-1))
                {
                    continue;
                }
                print_array(sFirst, last, "is_sorted() returning false: ");
                std::cout << "comp(" << *(first-1) << ", " << *(next-1) << ") = false && "
                    << *(next-1) << " != " << *(first-1) << std::endl ;
                return false;
            }

        return true;
    }

    public:
    MySortAlgoTester(size_t numElements) : m_numElements(numElements)
    {
        srand(123456789L);
        vec.resize(m_numElements);
        vec_copy.resize(m_numElements);
        //		std::generate(vec.begin(), vec.end(), rand);
        for(size_t i = 0; i < vec.size(); i++)
        {
            vec[i] = rand() % (m_numElements * 2);
            vec_copy[i] = vec[i];
        }
    }

    ~MySortAlgoTester()
    {
    }

    void reset()
    {
        // copy the data back so next algo can be tested with same array.
        std::copy(vec_copy.begin(), vec_copy.end(), vec.begin());
        for(size_t i = 0; i < vec_copy.size(); i++)
        {
            vec[i] = vec_copy[i];
        }
        // std::copy(vec_copy.begin(), vec_copy.end(),  vec);
    }

    double test( void (*sort_func)(typename std::vector<T>::iterator first, typename std::vector<T>::iterator last, key_compare pred), const char* name )
    {
        std::cout << "START Testing: " << name << ". With --- " << m_numElements << " elements." << std::endl;
        startClock();

        sort_func(vec.begin(), vec.end(), comp);
        double ms = getClock();
        if(!std::is_sorted(vec.begin(), vec.end()))
        {
            std::cout << name << " did not sort the array." << std::endl;
            // throw string(name) + " did not sort the array.";
        }
        std::cout << "DONE Testing: " << name << ". Time taken (ms): " << ms << std::endl;
        return ms;
    }

    double test( void (*sort_func)(typename std::vector<T>::iterator first, typename std::vector<T>::iterator last), const char* name )
    {
        std::cout << "START Testing: " << name << ". With --- " << m_numElements << " elements." << std::endl;
        startClock();

        sort_func(vec.begin(), vec.end());
        double ms = getClock();
        if(!MySortAlgoTester::is_sorted(vec.begin(), vec.end()))
        {
            std::cout << name << " did not sort the array." << std::endl;
            // throw string(name) + " did not sort the array.";
        }
        std::cout << "DONE Testing: " << name << ". Time taken (ms): " << ms << std::endl;
        return ms;
    }
};


int main ()
{
    srand(123456789L);
    size_t numElements = 4;
    std::vector<const char*> algoNames;
    std::map<double, std::vector<double>> results;
    int numTests = 0;
    while( (numElements *= 2) <= 4096*16 )
    {
        MySortAlgoTester<int> tester(numElements);
        results[numElements] = std::vector<double>();
#if 0
        algoNames.push_back("insertion_sort");
        results[numElements].push_back(tester.test(insertion_sort, "insertion_sort"));
        tester.reset();
#elif 0
        algoNames.push_back("quick");
        results[numElements].push_back(tester.test(quicksort, "quicksort"));
        tester.reset();
#elif 1
        algoNames.push_back("mixed_quicksort");
        results[numElements].push_back(tester.test(mixed_quicksort, "mixed_quicksort"));
#endif
    }
    // --- print the results...
}

// ------------------------------------------------
#if 0 // stdin

#endif
#if 0 // stdout

#endif
#if 0 // stderr

#endif
#if 0 // cmpinfo
In file included from /usr/lib/gcc/i686-pc-linux-gnu/4.3.4/include/g++-v4/type_traits:40,
                 from prog.cpp:8:
/usr/lib/gcc/i686-pc-linux-gnu/4.3.4/include/g++-v4/c++0x_warning.h:36:2: error: #error This file requires compiler and library support for the upcoming ISO C++ standard, C++0x. This support is currently experimental, and must be enabled with the -std=c++0x or -std=gnu++0x compiler options.
In file included from prog.cpp:8:
/usr/lib/gcc/i686-pc-linux-gnu/4.3.4/include/g++-v4/type_traits:82: error: template argument 1 is invalid
/usr/lib/gcc/i686-pc-linux-gnu/4.3.4/include/g++-v4/type_traits:106: error: template argument 1 is invalid
/usr/lib/gcc/i686-pc-linux-gnu/4.3.4/include/g++-v4/type_traits:136: error: expected unqualified-id before ‘&&’ token
prog.cpp:254: warning: ‘>>’ operator will be treated as two right angle brackets in C++0x
prog.cpp:254: warning: suggest parentheses around ‘>>’ expression
prog.cpp:254: error: spurious ‘>>’, use ‘>’ to terminate a template argument list
prog.cpp:256: error: definition of ‘class MySortAlgoTester’ inside template parameter list
prog.cpp:343: error: two or more data types in declaration of ‘type name’
prog.cpp:343: error: expected ‘>’ before ‘;’ token
prog.cpp:343: error: expected unqualified-id before ‘;’ token
prog.cpp: In function ‘int main()’:
prog.cpp:351: error: ‘>>’ should be ‘> >’ within a nested template argument list
prog.cpp:355: error: ‘MySortAlgoTester’ was not declared in this scope
prog.cpp:355: error: expected primary-expression before ‘int’
prog.cpp:355: error: expected `;' before ‘int’
prog.cpp:367: error: ‘tester’ was not declared in this scope
prog.cpp:352: warning: unused variable ‘numTests’

#endif
