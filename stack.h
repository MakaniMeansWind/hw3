#ifndef STACK_H
#define STACK_H

#include <vector>
#include <stdexcept>

// Use inheritance from std::vector (choose public/private) as appropriate
template <typename T>
class Stack 
{
public:
    Stack();
    ~Stack();
    bool empty() const;
    size_t size() const;
    void push(const T& item);
    void pop();  // throws std::underflow_error if empty
    const T& top() const; // throws std::underflow_error if empty
    // Add other members only if necessary

private: 
    std::vector<T> stackVector;

};

template<typename T>
Stack<T>::Stack()
{



}

template<typename T>
Stack<T>::~Stack()
{


}

template<typename T>
bool Stack<T>::empty() const
{

    return Stack<T>::size() == 0;

}

template<typename T>
size_t Stack<T>::size() const
{

    return stackVector.size();

}

template<typename T>
void Stack<T>::push(const T& item)
{

    stackVector.push_back(item);

}

template<typename T>
void Stack<T>::pop()
{

    if(Stack<T>::empty())
    {

        throw std::underflow_error("Stack is currently empty.");

    }

    else
    {

        stackVector.pop_back();

    }

}

template<typename T>
const T& Stack<T>::top() const
{

    if(Stack<T>::empty())
    {

        throw std::underflow_error("Stack is currently empty.");

    }

    else
    {

        return stackVector[Stack<T>::size() - 1];

    }

}

#endif