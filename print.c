#include <stdio.h>
#include <stdlib.h>

typedef struct LinkedListNode
{
    int data;
    struct LinkedListNode *next;
} LinkedListNode;

void printList(LinkedListNode *head)
{
    if (head == NULL)
    {
        printf("Empty list\n");
        return;
    }
    printf("(%p, %p) --> ", &head, head);
    while (head->next != NULL)
    {
        printf("(%p, %d, %p) --> ", head, head->data, head->next);
        head = head -> next;
    }
    printf("(%p, %d, %p)", head, head->data, head->next);
    printf("\n");
}