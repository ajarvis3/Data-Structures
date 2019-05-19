#ifndef LINKEDLIST_H
#define LINKEDLIST_H

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
        LinkedList();

        // Adds a link to the end of the list
        void add(T data);

        // Gets the data at a specified location.
        T get(int index);

        // Returns the head LinkNode.
        LinkNode<T> getHead();

        // Checks if the same data is already in the linked list
        bool contains(T data);

        // Removes the first occurence of a node with relevant data.
        // If a node is removed, return true. Else return false;
        bool remove(T data);

        // Creates and returns an instance of LinkedListIterator for this LinkedList
        LinkedListIterator<T>* getNewIterator();

    };
}

#endif
