#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"

// driver
int main() {

    LinkedList<int> *ll = new LinkedList<int>(9);
    ll->addElement(8);
    ll->addElement(7);
    ll->addElement(88);

    printf("\nfound at: %d\n", ll->findElement(88));

    //ll->deleteElement(88);
    int hoo = ll->getHead()->getValue();
    int moo = ll->getHead()->getNext()->getValue();
    int foo = ll->getHead()->getNext()->getNext()->getValue(); 
    int joo = ll->getHead()->getNext()->getNext()->getNext()->getValue(); 
    printf("head: %d \nnext to head: %d\nanother fucker: %d\nyet another fucker: %d\n", hoo, moo, foo, joo);


    return 0;
}
