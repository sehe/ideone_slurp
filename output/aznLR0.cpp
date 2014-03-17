// error:	OK
// langId:	44
// langName:	C++11
// langVersion:	gcc-4.8.1
// time:	0
// date:	2013-09-16 08:44:37
// status:	0
// result:	15
// memory:	3440
// signal:	0
// public:	false
// ------------------------------------------------
/** @file BagInterface.h */
#ifndef _BAG_INTERFACE
#define _BAG_INTERFACE
#include <vector>
#include <algorithm>

template<class ItemType>
class BagInterface
{
public:
    virtual int getCurrentSize() const = 0;
    virtual bool isEmpty() const = 0;
    virtual bool add(const ItemType& newEntry) = 0;
    virtual bool remove(const ItemType& anEntry) = 0;
    virtual void clear() = 0;
    virtual int getFrequencyOf(const ItemType& anEntry) const = 0;
    virtual std::vector<ItemType> toVector() const = 0;
}; // end BagInterface

#endif // _BAG_INTERFACE

///////////////////////////////////////////////////////////
// Implement Bag<T> to satisfy BagInterface<T>
template<class ItemType>
class Bag : public BagInterface<ItemType>
{
    std::vector<ItemType> _bag;
public:
    virtual int getCurrentSize() const
    {
        return _bag.size();
    }
    virtual bool isEmpty() const
    {
        return _bag.empty();
    }
    virtual bool add(const ItemType& newEntry)
    {
        _bag.push_back(newEntry);
        return true;
    }
    virtual bool remove(const ItemType& anEntry)
    {
        auto it = std::find(_bag.begin(), _bag.end(), anEntry);
        if(it!=_bag.end())
        {
            _bag.erase(it);
            return true;
        }
        else
        {
            return false;
        }
    }
    virtual void clear()
    {
        _bag = { };
    }
    virtual int getFrequencyOf(const ItemType& anEntry) const
    {
        return std::count(_bag.begin(), _bag.end(), anEntry);
    }
    virtual std::vector<ItemType> toVector() const
    {
        return _bag;
    }
}; // end Bag

#include <iostream> // For cout and cin
#include <string> // For string objects
#include <vector>
#include <string>
using namespace std;
int main()
{
    string clubs[] = { "Joker", "Ace", "Two", "Three",
                       "Four", "Five", "Six", "Seven",
                       "Eight", "Nine", "Ten", "Jack",
                       "Queen", "King"
                     };
// Create our bag to hold cards
    Bag <string> grabBag;
// Place six cards in the bag
    grabBag.add(clubs[1]);
    grabBag.add(clubs[2]);
    grabBag.add(clubs[4]);
    grabBag.add(clubs[8]);
    grabBag.add(clubs[10]);
    grabBag.add(clubs[12]);
// Get friend's guess and check it
    int guess = 0;

    while(!grabBag.isEmpty())
    {
        cout << "What is your guess?"
             << "(1 for Ace to 13 for King): ";
        cin >> guess;
// Is card in the bag?
        if(grabBag.getFrequencyOf(clubs[guess])>0)
        {
// Good guess – remove card from the bag
            cout << "You get the card!\n";
            grabBag.remove(clubs[guess]);
        }
        else
        {
            cout << "Sorry, card was not in the bag.\n";
        }
    }
    cout << "No more cards in the bag.\n";
    return 0;
}

// ------------------------------------------------
#if 0 // stdin
1
2
4
8
10
12
#endif
#if 0 // stdout
What is your guess?(1 for Ace to 13 for King): You get the card!
What is your guess?(1 for Ace to 13 for King): You get the card!
What is your guess?(1 for Ace to 13 for King): You get the card!
What is your guess?(1 for Ace to 13 for King): You get the card!
What is your guess?(1 for Ace to 13 for King): You get the card!
What is your guess?(1 for Ace to 13 for King): You get the card!
No more cards in the bag.

#endif
#if 0 // stderr

#endif
#if 0 // cmpinfo

#endif
