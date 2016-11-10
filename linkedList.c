# include <stdlib.h>
# include <stdio.h>

# include "llNode.h"
# include "linkedList.h"

void printLinkedList(struct linkedList *llist) {
    struct llNode *currNode = llist->root;
    while(currNode) {
        printf("%d ",currNode->val);
        currNode = currNode->next;
    } 
    printf("\n");
}

void addLlNodeAt(struct linkedList *llist, int val, int i) {
    llist->size += 1;
    struct llNode *newNode = malloc(sizeof(struct llNode));
    newNode->val = val;

    if(i == 0){
        newNode->next = llist->root;
        llist->root = newNode;
        return;
    }

    struct llNode *currNode = llist->root;
    while(currNode->next) {
        if(i == 1) {
            struct llNode *temp = currNode->next;
            currNode->next = newNode;
            newNode->next = temp;
            return;
        }

        i--;
        currNode = currNode->next;
    }
    currNode->next = newNode;
}

void addLlNodeLast(struct linkedList *llist, int val) {
    addLlNodeAt(llist, val, llist->size);
}

void addLlNodeFirst(struct linkedList *llist, int val) {
    addLlNodeAt(llist, val, 0);
}

void removeLlNodeAt(struct linkedList *llist, int i) {
    if(!llist->root) {
        return;
    }

    if(!llist->root->next) {
        free(llist->root);
        llist->root = NULL;
        return;
    }

    if(i == 0) {
        struct llNode *temp = llist->root->next;
        free(llist->root);
        llist->root = temp;
        return;
    }

    struct llNode *currNode = llist->root;
    while(currNode->next->next) {
        if(i == 1) {
            struct llNode *temp = currNode->next;
            currNode->next = currNode->next->next;
            free(temp);
            return;
        }
        i--;
        currNode = currNode->next;
    }
    free(currNode->next);
    currNode->next = NULL;
}

void removeLlNodeLast(struct linkedList *llist) {
    removeLlNodeAt(llist, llist->size-1);
}

void removeLlNodeFirst(struct linkedList *llist) {
    removeLlNodeAt(llist, 0);
}
