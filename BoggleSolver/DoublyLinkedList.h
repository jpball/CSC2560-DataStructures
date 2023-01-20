#pragma once
#include "DoublyLinkedListException.h"

template < class T >
class DoublyLinkedList
{
public:
    DoublyLinkedList();
    ~DoublyLinkedList();
    void insertAtFront(const T& elem);
    void insertAtRear(const T& elem);
    bool removeFromFront(T& elem);
    bool removeFromRear(T& elem);
    bool remove();
    bool remove(const T& elem);
    int size();
    bool first(T& elem);
    bool last(T& elem);
    bool next(T& elem);
    bool previous(T& elem);
    bool isEmpty();
    bool find(const T& elem);
    T& at(int pos);
    T& operator[](int pos);
    
private:
    struct Node
    {
        T data;
        Node* p_next;
        Node* p_prev;
    };

    Node* p_head;
    Node* p_tail;
    Node* p_current;
    int numberOfNodes;
};
//--
template < class T >
DoublyLinkedList<T>::DoublyLinkedList()
{
    p_head = 0;
    p_tail = 0;
    p_current = 0;
    numberOfNodes = 0;
}
//--
template < class T >
DoublyLinkedList<T>::~DoublyLinkedList()
{
    while(!isEmpty())
    {
        Node* p_delete = p_head;
        p_head = p_head->p_next;
        delete p_delete;
        numberOfNodes--;
    }
    p_head = 0;
    p_tail = 0;
    p_current = 0;
}
//--
template < class T >
void DoublyLinkedList<T>::insertAtFront(const T& elem)
{
    Node* p_newNode = new Node;
    p_newNode->data = elem;
    p_newNode->p_prev = 0;
    
    if(!isEmpty()){
        p_newNode->p_next = p_head;
        p_head->p_prev = p_newNode;
        p_head = p_newNode;
        p_newNode = 0;
    }
    else{
        p_newNode->p_next = 0;
        p_head = p_newNode;
        p_tail = p_newNode;
        p_current = p_head;
        p_newNode = 0;
    }
    numberOfNodes++;
}

//--
template < class T >
void DoublyLinkedList<T>::insertAtRear(const T& elem)
{
    Node* p_newNode = new Node;
    
    p_newNode->data = elem;
    p_newNode->p_next = 0;
   
    if(!isEmpty()){
        p_tail->p_next = p_newNode;
        p_newNode->p_prev = p_tail;
        p_tail = p_newNode;
        p_newNode = 0;
    }
    else{
        p_newNode->p_prev = 0;
        p_head = p_newNode;
        p_tail = p_newNode;
        p_current = p_head;
        p_newNode = 0;
    }
    numberOfNodes++;
}
//--
template < class T >
bool DoublyLinkedList<T>::removeFromFront(T& elem) //true if an item is removed, elem holds that value
{
    bool retVal = false;
    if(!isEmpty()){
        retVal = true;
        
        elem = p_head->data;
        
        if(p_head == p_tail){
            delete p_head;
            p_head = 0;
            p_tail = 0;
        }
        else{
            Node* p_delete = p_head;
            p_head = p_delete->p_next;
            p_head->p_prev = 0;
            delete p_delete;
        }
        numberOfNodes--;
    }
    return retVal;
}

//--
template < class T >
bool DoublyLinkedList<T>::removeFromRear(T& elem) //true if an item is removed, elem holds that value
{
    bool retVal = false;
    if(!isEmpty()){
        retVal = true;
        
        elem = p_tail->data;
        
        if(p_head == p_tail){
            delete p_tail;
            p_head = 0;
            p_tail = 0;
        }
        else{
            Node* p_delete = p_tail;
            p_tail = p_delete->p_prev;
            p_tail->p_next = 0;
            delete p_delete;
        }
        numberOfNodes--;
    }
    return retVal;
}
//--
template < class T >
bool DoublyLinkedList<T>::remove() //remove the element that the current pointer points to
{
    bool retVal = false;
    if(p_current == p_head){
        T data;
        removeFromFront(data);
    }
    else if(p_current == p_tail){
        T data;
        removeFromRear(data);
    }
    else{
        Node* p_delete = p_current;
        p_current->p_prev->p_next = p_current->p_next;
        p_current->p_next->p_prev = p_current->p_prev;
        p_current = p_current->p_prev;
        delete p_delete;
        p_delete = 0;
        numberOfNodes--;
    }
    return retVal;
}
//--
template < class T >
bool DoublyLinkedList<T>::remove(const T& elem) //remove all occurrences of the element that is passed in.
{
    bool retVal = false;
    
    if(!isEmpty()){
        p_current = p_head;
        while(p_current != 0){
            if (p_current->data == elem){
                retVal = true;
                remove();
            }
            p_current = p_current->p_next;
        }
    }
    
    return retVal;
}


template < class T >
int DoublyLinkedList<T>::size()
{
    return numberOfNodes;
}


template < class T >
bool DoublyLinkedList<T>::first(T& elem)
{
    bool retVal = false;
    if(!isEmpty())
    {
        retVal = true;
        elem = p_head->data;
        p_current = p_head;
    }
    return retVal;
}
//--
template < class T >
bool DoublyLinkedList<T>::last(T& elem)
{
    bool retVal = false;
    if(!isEmpty())
    {
        retVal = true;
        elem = p_tail->data;
        p_current = p_tail;
    }
    return retVal;
}
//--
template < class T >
bool DoublyLinkedList<T>::next(T& elem)
{
    bool retVal = false;
    if(p_current && p_current->p_next != 0)
    {
        retVal = true;
        p_current = p_current->p_next;
        elem = p_current->data;
    }
    return retVal;
}

//--
template < class T >
bool DoublyLinkedList<T>::previous(T& elem)
{
    bool retVal = false;
    if(p_current && p_current->p_prev != 0)
    {
        retVal = true;
        elem = p_current->data;
        p_current = p_current->p_prev;
    }
    return retVal;
}
//--
template < class T >
bool DoublyLinkedList<T>::isEmpty()
{
    return numberOfNodes == 0;
}
//--
template < class T >
bool DoublyLinkedList<T>::find(const T& elem) //returns a true/false value indicating if an element is present in the list
{
    bool retVal = false;
    p_current = p_head;
    for(int i = 0; i < numberOfNodes; i++){
        if(p_current->data == elem){
            retVal = true;
            break;
        }
        p_current = p_current->p_next;
    }
    return retVal;
    
}
//--
template < class T >
T& DoublyLinkedList<T>::at(int pos)
{
    if(pos > numberOfNodes || pos < 0){
        DoublyLinkedListException exc;
        throw exc;
    }
    else{
        p_current = p_head;
        for (int i = 0; i < pos; i++){
            T hold;
            next(hold);
        }
        return p_current->data;
    }
}
//--
template < class T >
T& DoublyLinkedList<T>::operator[](int pos)
{
    return at(pos);
}
//--

