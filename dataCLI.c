// A CLI that can store data in different data structures

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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
    while (head->next != NULL)
    {
        printf("%d --> ", head->data);
        head = head -> next;
    }
    printf("%d", head->data);
    printf("\n");
}


#include "linked_list.h"
#include "array.h"
#include "queue.h"
#include "stack.h"


int main(void)
{
    int choice;
    printf("This is a program to save integers in different data structures.\n");
    printf("1. Array\n"
            "2. Linked List\n"
            "3. Queue\n"
            "4. Stack\n"
            "5. Binary Search Tree\n"
            "6. Exit\n"
            "Please choose a data structure: ");
    scanf("%d", &choice);
    switch (choice)
    {
        case 1:
            ArrayMain();
            break;
        case 2:
            LinkedListMain();
            break;
        case 3:
            QueueMain();
            break;
        case 4:
            StackMain();
            break;
        case 5:
            break;
        case 6:
            return 0;
            break;
    }    
}

