#include <stdlib.h>
#include <iostream>
#include "LinkedList.h"
/*
 * Contains two classes: LinkNode and LinkedList.
 * LinkNode are the nodes in the LinkedList.
 * LinkedList is a partial implementation of a singly linked list.
 * Only the parts relevant for my Hash Table.
 */

using namespace Linked;

/*
 * LinkNode Class Implementation
 */

// Constructor. data becomes thisData
template <class T>
LinkNode<T>::LinkNode(T data) {
    thisData = data;
    next = nullptr;
}

// Sets the next link to be ptr
template <class T>
void LinkNode<T>::setNext(LinkNode<T>* ptr) {
    next = ptr;
}

// Returns the next LinkNode
template <class T>
LinkNode<T>* LinkNode<T>::getNext() {
    return next; 
}

// Returns the data stored at this link
template <class T>
T LinkNode<T>::getData() {
    return thisData;
}

/*
 * LinkedListIterator Implementation
 */

// Constructor for LinkedListIterator
template <class T>
LinkedListIterator<T>::LinkedListIterator(LinkNode<T>* link) {
    ptr = link;
}

// Gets the next piece of data.
template <class T>
T LinkedListIterator<T>::getNext() {
    T data = ptr->getData();
    ptr = ptr->getNext();
    return data;
}

// Checks if there is a next object
template <class T>
bool LinkedListIterator<T>::hasNext() {
    return (ptr != nullptr);
}
