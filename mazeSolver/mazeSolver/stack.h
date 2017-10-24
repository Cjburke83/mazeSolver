/*My_vec.h
 Connor Burke
 Header file for a vector data structure.
 */

#ifndef vectorStack_h
#define vectorStack_h

#include <stdio.h>
#include <ostream>
#include <vector>
class stack {
    std::vector<int> S;
    
public:
    //member functions
    stack() { // constructor
        std::vector<int> S;
    }
    bool isEmpty() const { // checks whether no elements are stored
        if (S.empty()) { return true; }
        else { return false; }
    }
    int top() { // return the top object of a non-empty stack, can throw(StackEmptyException)
        if(S.empty()) {
            throw std::out_of_range("Stack Empty Exception");
        }
        return S[S.size()-1];
    }
    
    void push(const int elem) { // push object onto the stack
        S.push_back(elem);
    }
    
    int pop() { // returns first object of  a non-empty stack, can throw(StackEmptyException)
        if(S.empty()) {
            throw std::out_of_range("Stack Empty Exception");
        }
        S.erase(S.end()-1);
        return 0;
    }
    
    int& operator[](int i) { //overload []
        return S[i];
    }
    
    int get_size() const {
        return(S.size());
    }
};

#endif /* vectorStack_h */
