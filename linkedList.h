# ifndef LINKEDLIST_H
# define LINKEDLIST_H

# include <stdlib.h>

typedef struct linkedList_node
{
    int val;
    struct linkedList_node *next;
} node;

// Build a simple example Linked List. It will look
// like this:
// |0| -> |1| -> |2| -> |3| -> |4| -> |5|
// @return: the head node of the linked list
node *buildExampleLinkedList(void);

// Remove the first node containing the value val.
// @param node **head: pointer to pointer to head node
// @param int val: value to be removed from linked list
// @return: the node removed from the linked list
node *removeNode(node **head, int val);

// Print all the elements of the linked list
void printLinkedList(node *head);

# endif
