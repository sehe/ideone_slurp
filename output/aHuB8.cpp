// error:	OK
// langId:	1
// langName:	C++ 4.8.1
// langVersion:	gcc-4.8.1
// time:	0.01
// date:	2012-10-19 10:41:05
// status:	0
// result:	15
// memory:	2816
// signal:	0
// public:	false
// ------------------------------------------------
#include <algorithm>
#include <vector>
#include <functional>
#include <iostream>

template <typename T> struct Term
{
    Term() : coeff(), exponent(0) { }
    Term(T c, int e) : coeff(c), exponent(e) { }
    T coeff;
    int exponent;
};

template <typename T> struct Poly
{
    typedef Term<T> term_t;
    typedef std::vector<term_t> terms_t;
    terms_t _terms;

    Poly(terms_t terms) : _terms(terms) { }

    void combineLikeTerms()
    {
        if (_terms.empty())
            return;

        std::sort(_terms.begin(), _terms.end(), order);

        term_t accum(T(), 0);
        std::vector<term_t> result;

        for (typename terms_t::const_iterator curr = _terms.begin(); curr!= _terms.end(); ++curr)
        {
            if (curr->exponent == accum.exponent)
                accum.coeff += curr->coeff;
            else
            {
                if (accum.coeff != 0)
                    result.push_back(accum);
                accum = *curr;
            }
        }        
        if (accum.coeff != 0)
            result.push_back(accum);

        std::swap(_terms, result); // only update if no exception
    }

  private: 
    static bool order(term_t const& a, term_t const& b)
        { return a.exponent > b.exponent; }
};

int main()
{
    Poly<int>::terms_t terms;
    terms.push_back(Term<int>( 4, 1 ));
    terms.push_back(Term<int>( 6, 7 ));
    terms.push_back(Term<int>(-3, 1 ));
    terms.push_back(Term<int>( 5, 5 ));

    Poly<int> demo(terms);

    typedef std::vector<Term<int> >::const_iterator It;
        
    demo.combineLikeTerms();

    for (It it = demo._terms.begin(); it!= demo._terms.end(); ++it)
        std::cout << (it->coeff>0? " +" : " ") << it->coeff << "x^" << it->exponent;

    std::cout << "\n";
}
// ------------------------------------------------
#if 0 // stdin

#endif
#if 0 // stdout
 +6x^7 +5x^5 +1x^1

#endif
#if 0 // stderr

#endif
#if 0 // cmpinfo

#endif
