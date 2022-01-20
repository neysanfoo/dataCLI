#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct LinkedListNode
{
    int data;
    struct LinkedListNode *next;
} LinkedListNode;

#include "print.h"


void PromptList();
bool IsEmptyList(LinkedListNode *head);
LinkedListNode *InsertAtStart(LinkedListNode *head, int data);
LinkedListNode *InsertAtEnd(LinkedListNode *head, int data);
LinkedListNode *InsertAtN(LinkedListNode *head, int n, int data);
LinkedListNode *DeleteAtN(LinkedListNode *head, int n);


int main(void)
{
    LinkedListNode *head = NULL;
    int choice;
    int data;
    int n;
    PromptList();
    while (true)
    {
        scanf("%d", &choice);    
        switch(choice)
        {
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                head = InsertAtEnd(head,data);
                printList(head);
                break;
            case 2:
                printf("Enter data: ");
                scanf("%d", &data);
                head = InsertAtStart(head,data);
                printList(head);
                break;
            case 3:
                printf("Enter position (0 Indexed): ");
                scanf("%d", &n);
                printf("Enter data: ");
                scanf("%d", &data);
                head = InsertAtN(head,n,data);
                printList(head);
                break;
            case 4:
                printf("Enter position (0 Indexed): ");
                scanf("%d", &n);
                head = DeleteAtN(head,n);
                printList(head);
                break;        
            case 5:
                printList(head);
                break;
            case 6:
                return 0;
                break;
        }
        printf("Please choose another action: ");
    }

}

LinkedListNode *InsertAtStart(LinkedListNode *head, int data)
{
    LinkedListNode *temp = malloc(sizeof(LinkedListNode));
    temp -> data = data;
    if (head == NULL)
    {
        temp -> next = NULL;
        head = temp;
        return head;
    }
    temp -> next = head;
    head = temp;
    return head;
}

LinkedListNode *InsertAtEnd(LinkedListNode *head, int data)
{
    LinkedListNode *temp = malloc(sizeof(LinkedListNode));
    temp -> data = data;
    temp -> next = NULL;
    if (head == NULL)
    {
        head = temp;
        return head; 
    }
    LinkedListNode *temp2 = head; // To iterate to end of list
    while (temp2 -> next != NULL)
    {
        temp2 = temp2 -> next;
    }
    temp2 -> next = temp;
    return head;
}

LinkedListNode *InsertAtN(LinkedListNode *head, int n, int data) // Starting at Index 0
{
    if (n == 0)
    {
        return InsertAtStart(head,n);
    }
    LinkedListNode *temp = malloc(sizeof(LinkedListNode));
    temp -> data = data;
    LinkedListNode *temp2 = head;
    for (int i = 0; i<n-1; i++)
    {
        temp2 = temp2 -> next;
    }
    temp -> next = temp2 -> next;
    temp2 -> next = temp;
    return head;
}

LinkedListNode *DeleteAtN(LinkedListNode *head, int n)
{
    if (IsEmptyList(head))
    {
        return head;
    }
    LinkedListNode *temp = head;

    if (n == 0)
    {
        LinkedListNode *target = head;
        head = head -> next;
        free (target);
        return head;
    }

    for (int i = 0; i < n-1; i++)
    {
        temp = temp -> next;
    }
    LinkedListNode *target = temp -> next;
    temp -> next = target -> next;
    free(target);
    return head;
}

bool IsEmptyList(LinkedListNode *head)
{
    if (head == NULL) return true;
    return false;
}

void PromptList()
{
    printf("1. Insert at end\n"
            "2. Insert at start\n"
            "3. Insert at Nth position\n"
            "4. Delete at Nth position\n"
            "5. Print List\n"
            "6. Exit\n"
            "Please choose an action: ");
}