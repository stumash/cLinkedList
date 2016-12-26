# include <stdio.h>
# include <stdlib.h>

# include "linkedList.h"

node *buildExampleLinkedList(void)
{
    node *head = NULL;

    for (int i = 5; i >= 0; i--)
    {
        node *newNode = (node *)malloc(sizeof(node));
        newNode->val = i;
        newNode->next = head;
        head = newNode;
    }

    return head;
}

node *removeNode(node **head, int val)
{
    // It's really important to understand that pp is not a pointer
    // to a node.  It's a pointer to a pointer to a node.  In
    // other words, it contains the address of a pointer to a node.
    node **pp = head;

    // While pp contains the address to a non-null pointer AND 
    // the non-null pointer doesn't point to the desired node.
    while (*pp && ((*pp)->val) != val)
    {
        // Here's the hard part to really understand. First we
        // dereference pp and get a pointer to a node.  Then, we
        // use the -> operator to get that node's pointer to the
        // next node.  Finally, we assign the address of that
        // pointer to pp.
        pp = &((*pp)->next);
        // note that we can't have done the following:
        // node *t = ((*pp)->next); pp = &t;
        // By using the temp variable t, &t is no longer the
        // location in memory of the pointer-to-next of some node.
        // Instead it's just the location in memory of t, the
        // temp node pointer.  So later, when we delete the desired
        // node using '*pp = (*pp)->next' we'll only be overwriting
        // the value of t and not the value of the
        // pointer-to-next of the node before the node to remove.
    }

    // If the list was empty or did not contain the desired val.
    if (*pp == NULL)
        return NULL;

    node *result = *pp;

    // Go to the place where the pointer is stored an overwrite
    // it to point to the next node.
    *pp = (*pp)->next;
    
    return result;
}

void printLinkedList(node *head)
{
    while (head)
    {
        printf("%d -> ",head->val);
        head = head->next;
    }
    printf("NULL\n");
}
