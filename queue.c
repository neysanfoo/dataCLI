#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct LinkedListNode
{
    int data;
    struct LinkedListNode *next;
} LinkedListNode;

void Enqueue(LinkedListNode **head, LinkedListNode **tail, int data);
void Dequeue(LinkedListNode **head, LinkedListNode **tail);
bool isEmpty(LinkedListNode *head);
void printList(LinkedListNode *head);
void PromptQueue();

int QueueMain(void)
{
    LinkedListNode *head = NULL;
    LinkedListNode *tail = NULL;
    int choice;
    int data;
    int n;
    PromptQueue();
    while (true)
    {
        scanf("%d", &choice);    
        switch(choice)
        {
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                Enqueue(&head, &tail, data);
                printList(head);
                break;
            case 2:
                Dequeue(&head, &tail);
                printList(head);
                break;
            case 3:
                printList(head);
                break;
            case 4:
                return 0;
                break;
        }
        printf("Please choose another action: ");
    }
    return 0;
}

void Enqueue(LinkedListNode **head, LinkedListNode **tail, int data)
{
    LinkedListNode *temp = malloc(sizeof(LinkedListNode));
    temp -> data = data;
    temp -> next = NULL;
    if (isEmpty(*head))
    {
        *head = temp;
        *tail = temp;
        return;
    }
    (*tail) -> next = temp;
    *tail = (*tail) -> next;
    return;
}

void Dequeue(LinkedListNode **head, LinkedListNode **tail)
{
    if (isEmpty(*head))
    {
        return;
    }
    LinkedListNode *temp = *head;
    *head = (*head) -> next;
    free(temp);
}

bool isEmpty(LinkedListNode *head)
{
    if (head == NULL)
    {
        return true;
    }
    return false;
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

void PromptQueue()
{
    printf("1. Enqueue\n"
            "2. Dequeue\n"
            "3. Print List\n"
            "4. Exit\n"
            "Please choose an action: ");
}
