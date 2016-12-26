# include <stdio.h>
# include <stdlib.h>

# include "linkedList.h"

int main(void)
{
    node *head = buildExampleLinkedList();
    printLinkedList(head);

    node *n2 = removeNode(&head, 2);
    printLinkedList(head);

    node *n0 = removeNode(&head, 0);
    printLinkedList(head);
}
