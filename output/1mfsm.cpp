// error:	OK
// langId:	1
// langName:	C++ 4.8.1
// langVersion:	gcc-4.8.1
// time:	0
// date:	2011-10-04 12:15:15
// status:	0
// result:	15
// memory:	2728
// signal:	0
// public:	false
// ------------------------------------------------
#include <vector>
#include <iostream>

template<typename T> class TStack;
template<typename T> TStack<T> operator+(const TStack<T> &s1, const TStack<T> &s2);

template<typename T>
class TStack {
    friend TStack<T> operator+<>(const TStack<T> &s1, const TStack<T> &s2);
    private:
        std::vector<T> items;
    public:
		TStack() : items() {}
		TStack(const TStack& rhs) : items(rhs.items) {}
		TStack& operator=(const TStack& rhs) 
		{
			items = rhs.items;
		}

        void printAll() {
            std::cout << "The content of the stack is: ";
            typename std::vector<T>::iterator it;
            for(it = items.begin(); it < items.end(); it++) {
                std::cout << *it << " ";
            }
            std::cout << std::endl;
        }
};

template<typename T>
TStack<T> operator+(const TStack<T> &s1, const TStack<T> &s2) {
    TStack<T> result = s1;
    typename std::vector<T>::const_iterator it;
    //below is line 41
    for(it = s2.items.begin(); it < s2.items.end(); it++) {
        result.items.push_back(*it);
    }
    return result;
}

using namespace std;

int main(int argc, char *argv[]) {
    TStack<int> intStack;
    // intStack.push(4);

    TStack<int> secondIntStack;
    // secondIntStack.push(10);

    cout << "Addition result: " << endl;
    //below is line 27
    TStack<int> result = intStack + secondIntStack;
    result.printAll();
    return 0;
}

// ------------------------------------------------
#if 0 // stdin

#endif
#if 0 // stdout
Addition result: 
The content of the stack is: 

#endif
#if 0 // stderr

#endif
#if 0 // cmpinfo

#endif
