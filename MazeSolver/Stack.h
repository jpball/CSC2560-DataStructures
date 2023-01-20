#pragma once
#include "DoublyLinkedList.h"
#include "StackUnderFlow.h"

template <class T>
class Stack{
public:
    Stack();
    ~Stack();
    void push(const T& elem);
    T pop();
    T top();
    int size();
    bool isEmpty();
private:
    int elementsInStack;
    DoublyLinkedList<T> list;
};

template <class T>
Stack<T>::Stack(){
    elementsInStack = 0;
}

template <class T>
Stack<T>::~Stack(){
}

template <class T>
void Stack<T>::push(const T& elem){
    list.insertAtFront(elem);
    elementsInStack++;
}

template <class T>
T Stack<T>::pop(){
    T data;
    
    list.removeFromFront(data); // Removes that last element of the list and provides a tempor
    
    elementsInStack--;
    
    return data;
}

template <class T>
T Stack<T>::top(){
    if (!isEmpty()) {
        T data;
        list.last(data);
        return data;
    }
    else{
        StackUnderFlow exc;
        throw exc;
    }
}

template <class T>
int Stack<T>::size(){
    return elementsInStack;
}

template <class T>
bool Stack<T>::isEmpty(){
    return elementsInStack == 0;
}



