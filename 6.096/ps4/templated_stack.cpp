#include <iostream>
#include <vector>

using namespace std;

template<typename T> class Stack;

template<typename T>
Stack<T> operator+(const Stack &a, const Stack &b);

template <typename T>
class Stack {
    vector<T> items;
    friend Stack<T> operator+<>(const Stack<T> &a, const Stack<T> &b);
    
    public:
    
    bool empty() const { return items.empty(); }
    void push(const T item) { items.push_back(item); }
    T &top() { return items.back(); }
    void pop() { items.pop_back(item); }
};

template<typename T>
Stack<T> operator+(const Stack &a, const Stack &b) {
    Stack<T> c = a;
    
    for (unsigned i=0; i<b.items.size(); i++)
        c.items.push_back(b.items[i]);
        
    return c;
}