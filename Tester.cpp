#include "LinkedList.h"
#include <iostream>

using namespace Linked;
using std::cout;

int main() {
    LinkedList<int>* list = new LinkedList<int>();
    list->add(10);
    LinkedListIterator<int>* iter = list->getNewIterator();
    while (iter->hasNext()) {
        cout << ((int)iter->getNext());
    }
    delete list;
    return 0;
}