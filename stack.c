#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct LinkedListNode
{
    int data;
    struct LinkedListNode *next;
} LinkedListNode;

void printListAddress(LinkedListNode *head);
void Push(LinkedListNode **top, int data);
void Pop(LinkedListNode **top);
void PromptStack();
void printList(LinkedListNode *head);

int StackMain(void)
{
    LinkedListNode *top = NULL;
    int choice;
    int data;
    PromptStack();
    while (true)
    {
        scanf("%d", &choice);    
        switch(choice)
        {
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                Push(&top, data);
                printList(top);
                break;
            case 2:
                Pop(&top);
                printList(top);
                break;
            case 3:
                printList(top);
                break;
            case 4:
                return 0;
                break;
        }
        printf("Please choose another action: ");
    }
}

void Push(LinkedListNode **top, int data)
{
    LinkedListNode *temp = malloc(sizeof(LinkedListNode));
    temp -> next = NULL;
    temp -> data = data;
    if (*top == NULL)
    {
        *top = temp;
        return;
    }
    temp -> next = *top;
    *top = temp;
    return;
}


void Pop(LinkedListNode **top)
{
    if (*top == NULL)
    {
        return;
    }
    LinkedListNode *temp = *top;
    (*top) = (*top) -> next;
    free(temp);
    return;
}


void PromptStack()
{
    printf("1. Push\n"
            "2. Pop\n"
            "3. Print List\n"
            "4. Exit\n"
            "Please choose an action: ");
}

// void printList(LinkedListNode *head)
// {
//     if (head == NULL)
//     {
//         printf("Empty list\n");
//         return;
//     }
//     while (head->next != NULL)
//     {
//         printf("%d --> ", head->data);
//         head = head -> next;
//     }
//     printf("%d", head->data);
//     printf("\n");
// }