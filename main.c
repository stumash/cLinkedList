# include <stdio.h>
# include <stdlib.h>

# include "linkedList.h"

int main(void) 
{
    struct linkedList *myLl = malloc(sizeof(struct linkedList));

    addLlNodeLast(myLl, 5);
    addLlNodeLast(myLl, 7);
    addLlNodeLast(myLl, 122);
    printLinkedList(myLl);

    removeLlNodeLast(myLl);
    printLinkedList(myLl);

    addLlNodeAt(myLl,40,1);
    printLinkedList(myLl);

    removeLlNodeFirst(myLl);
    printLinkedList(myLl);
}
