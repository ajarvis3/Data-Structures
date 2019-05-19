#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <stdlib.h>

// Header file for Linked List
namespace Linked {
    template <class T>
    class LinkNode {
    private:
        T thisData; // The data stored at this link
        LinkNode* next; // A pointer to the next LinkNode

    public:
        // Constructor. data becomes thisData
        LinkNode(T data);

        // Sets the next link to be ptr
        void setNext(LinkNode* ptr);

        // Returns the next LinkNode
        LinkNode* getNext();

        // Returns the data stored at this link
        T getData();
    };

    template <class T>
    class LinkedListIterator {
        private:
            LinkNode<T>* ptr;
        public:

            // Single argument constructor.
            LinkedListIterator(LinkNode<T>* link);

            // Gets the next piece of data.
            T getNext();

            // Checks if there is a next object
            bool hasNext();
    };

    template <class T>
    class LinkedList {
    private:
        LinkNode<T>* head;  // The head element of the linked list
        LinkNode<T>* tail;  // The tail element of the linked list
        int size;   // The size of the linked list

    public:
        // Default constructor.
        LinkedList() {
            size = 0;
            head = nullptr;
            tail = nullptr;
        }


        // Adds a link to the end of the list
        void add(T* data)  {
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
        T* get(int index) {
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
        LinkNode<T>* getHead() {
            return head;
        }

        // Checks if the same data is already in the linked list
        bool contains(T* data) {
            LinkNode<T>* link;
            for (link = head; link != nullptr; link = link->getNext()) {
                T* linkData = link->getData();
                if (linkData == data || *linkData == *data) {
                    return true;
                }
            }
            return false;
        }

        // Removes the first occurence of a node with relevant data.
        // If a node is removed, return true. Else return false;
        bool remove(T* data) {
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
        LinkedListIterator<T>* getNewIterator() {
            LinkedListIterator<T>* iter = new LinkedListIterator<T>(head);
            return iter;
        }

    };
}

#endif
