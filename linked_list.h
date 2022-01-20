typedef struct LinkedListNode
{
    int data;
    struct LinkedListNode *next;
} LinkedListNode;

int LinkedListMain(void);
void printList(LinkedListNode *head);
void PromptList();
bool IsEmptyList(LinkedListNode *head);
LinkedListNode *InsertAtStart(LinkedListNode *head, int data);
LinkedListNode *InsertAtEnd(LinkedListNode *head, int data);
LinkedListNode *InsertAtN(LinkedListNode *head, int n, int data);
LinkedListNode *DeleteAtN(LinkedListNode *head, int n);