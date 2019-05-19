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


/*
 * LinkedList Implementation
 */

// Default constructor for LinkedList.
template <class T>
LinkedList<T>::LinkedList() {
    size = 0;
    head = nullptr;
    tail = nullptr;
}

// Adds a link to the end of the list
template <class T>
void LinkedList<T>::add(T data) {
    LinkNode<T>* next = new LinkNode<T>(data);
    if (tail == nullptr) {
        head = tail = next;
    }
    else {
        tail->setNext(next);
        tail = next;
    }
    size++;
}

// Gets the data at a specified location.
template <class T>
T LinkedList<T>::get(int index) {
    LinkNode<T>* temp = nullptr;
    int i = 0;
    if (index < 0 || index >= size) {
        return nullptr;
    }
    for (temp = head, i = 0; i != index; i++, temp = temp->getNext()) {
        // Intentionally empty...
    }
    return temp->getData();
}

// Returns the head LinkNode.
template <class T>
LinkNode<T> LinkedList<T>::getHead() {
    return head;
}

// Checks if the same data is already in the linked list
template <class T>
bool LinkedList<T>::contains(T data) {
    LinkNode<T>* link;
    for (link = head; link != nullptr; link = link->getNext()) {
        if (link->getData() == data) {
            return true;
        }
    }
    return false;
}

// Removes the first occurence of a node with relevant data.
// If a node is removed, return true. Else return false;
template <class T>
bool LinkedList<T>::remove(T data) {
    LinkNode<T>* trail;
    LinkNode<T>* lead;
    for (trail = head; trail != nullptr; trail = lead) {
        lead = head->getNext();
        if (head != nullptr && (head->getData() == data)) {
            trail->setNext(lead->getNext());
            delete lead;
            size--;
            return true;
        }
    }
    return false;
}

// Creates and returns an instance of LinkedListIterator for this LinkedList
template <class T>
LinkedListIterator<T>* LinkedList<T>::getNewIterator() {
    LinkedListIterator<T>* iter = new LinkedListIterator<T>(head);
    return iter;
}

int main() {
    LinkedList<int>* list = new LinkedList<int>();
    list->add(10);
    list->add(10);
    list->add(100);
    list->add(5550);
    list->add(10);
    LinkedListIterator<int>* iter = list->getNewIterator();
    while (iter->hasNext()) {
        std::cout << ((int)iter->getNext()) << "\n";
    }
    delete list;
    return 0;
}
