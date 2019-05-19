#include "LinkedList.h"
#include <iostream>

using namespace Linked;
using std::cout;

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

template class LinkedList<int>;
template class LinkNode<int>;
template class LinkedListIterator<int>;
