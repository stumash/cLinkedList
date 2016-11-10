# ifndef LINKED_LIST_H
# define LINKED_LIST_H

# include <stdlib.h>

# include "llNode.h"

struct linkedList
{
    int size;
    struct llNode *root;
};

/*
 * Print all the elements of the linked list, space delimited
 */
void printLinkedList(struct linkedList *llist);

/*
 * Add node at index i.  If index i is too big, add the node
 * to the back of the linked list.
 */
void addLlNodeAt(struct linkedList *llist, int val, int i);

/*
 * Add node to end of linked list.
 */
void addLlNodeLast(struct linkedList *llist, int val);

/*
 * Add node to front of linked list.
 */
void addLlNodeFirst(struct linkedList *llist, int val);

/*
 * Remove the node at index i. If index i is too big, remove
 * the last element of the linked list. Do nothing if the
 * linked list is empty.
 */
void removeLlNodeAt(struct linkedList *llist, int i);

/*
 * Remove the last node in the linked list. Do nothing if
 * the linked list is empty.
 */
void removeLlNodeLast(struct linkedList *llist);

/*
 * Remove the first node in the linked list.  Do nothing
 * if the linked list is empty.
 */
void removeLlNodeFirst(struct linkedList *llist);

# endif
