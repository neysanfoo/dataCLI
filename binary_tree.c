#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct BTNode
{
    int data;
    struct BTNode *left;
    struct BTNode *right;
} BTNode;

BTNode *GetNewNode(BTNode *root, int data);
BTNode *InsertBTNode(BTNode *root, int data);
void PrintBTPreorder(BTNode *root);
void PrintBTInorder(BTNode *root);
void padding ( char ch, int n );
void printTree(BTNode *root, int depth);
void PrintBTPostorder(BTNode *root);
bool Search(BTNode *root, int target);
int FindMin(BTNode *root);
int FindMax(BTNode *root);
int FindHeight(BTNode *root);
BTNode *DeleteBTNode(BTNode *root, int data);
void PromptBT();

int BTMain(void)
{
    BTNode *root = NULL;
    int choice;
    int data;
    int n;
    PromptBT();
    while (true)
    {
        scanf("%d", &choice);    
        switch(choice)
        {
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                root = InsertBTNode(root,data);
                printTree(root,0);
                break;
            case 2:
                printf("Enter data: ");
                scanf("%d", &data);
                root = DeleteBTNode(root,data);
                printTree(root,0);
                break;
            case 3:
                PrintBTPreorder(root);
                printf("\n");
                break;
            case 4:
                PrintBTInorder(root);
                printf("\n");
                break;        
            case 5:
                PrintBTPostorder(root);
                printf("\n");
                break;
            case 6:
                printTree(root,0);
                break;
            case 7:
                printf("Enter data: ");
                scanf("%d", &data);
                if (Search(root,data))
                {
                    printf("Found\n");
                }
                else
                {
                    printf("Not Found\n");
                }
                break;
            case 8:
                printf("%d\n", FindMin(root));
                break;
            case 9:
                printf("%d\n", FindMax(root));
                break;
            case 10:
                printf("%d\n", FindHeight(root));
                break;
            case 11:
                return 0;
                break;
        }
        printf("Please choose another action: ");
    }
}


void padding ( char ch, int n )
{
    int i;

    for ( i = 0; i < n; i++ )
        putchar ( ch );
}

void printTree(BTNode *root, int depth)
{
    int i;

    if ( root == NULL ) {
        padding ( '\t', depth );
        puts ( "~" );
    }
    else {
        printTree ( root->right, depth + 1 );
        padding ( '\t', depth );
        printf ( "%d\n", root -> data );
        printTree( root->left, depth + 1 );
    }
    
}



void PrintBTPreorder(BTNode *root) // <root><left><right>
{
    printf("%d ", root -> data);
    if (root -> left)
    {
        PrintBTPreorder(root -> left);
    }
    if (root -> right)
    {
        PrintBTPreorder(root -> right);
    }
}

void PrintBTInorder(BTNode *root) // <left><root>right>
{
    if (root -> left)
    {
        PrintBTInorder(root -> left);
    }
    printf("%d ", root -> data);
    if (root -> right)
    {
        PrintBTInorder(root -> right);
    }
}
void PrintBTPostorder(BTNode *root) // <left>right><root>
{
    if (root -> left)
    {
        PrintBTPostorder(root -> left);
    }
    if (root -> right)
    {
        PrintBTPostorder(root -> right);
    }
    printf("%d ", root -> data);
}
BTNode *GetNewNode(BTNode *root, int data)
{
    BTNode *newNode = malloc(sizeof(BTNode));
    newNode -> data = data;
    newNode -> left = NULL;
    newNode -> right = NULL;
    return newNode;
}
BTNode *InsertBTNode(BTNode *root, int data)
{
    if (root == NULL)
    {
        root = GetNewNode(root,data);
        return root;
    }
    else if (data <= root -> data )
    {
        root -> left = InsertBTNode(root -> left, data);
    }
    else
    {
        root -> right = InsertBTNode(root -> right, data);
    }
    return root;
}

bool Search(BTNode *root, int target)
{
    if (root == NULL)
    {
        return false;
    }
    else if (target == root -> data)
    {
        return true;
    }
    else if (target <= root -> data)
    {
        return Search(root -> left ,target);
    }
    else 
    {
        return Search(root -> right, target);
    }
}

int FindMin(BTNode *root)
{
    if (root == NULL)
    {
        printf("Error! Tree is Empty.\n");
        return -1;
    }
    while (root -> left != NULL)
    {
        root = root -> left;
    }
    return root -> data;
}

int FindMax(BTNode *root)
{
    if (root == NULL)
    {
        printf("Error! Tree is Empty.\n");
        return -1;
    }
    while (root -> right != NULL)
    {
        root = root -> right;
    }
    return root -> data;
}

int FindHeight(BTNode *root)
{
    // Find height of BST
    if (root == NULL)
    {
        return 0;
    }
    int leftHeight = FindHeight(root -> left);
    int rightHeight = FindHeight(root -> right);
    if (leftHeight > rightHeight)
    {
        return (leftHeight + 1);
    }
    else
    {
        return (rightHeight + 1);
    }
}


BTNode *DeleteBTNode(BTNode *root, int data)
{
    //Delete node from BST
    if (root == NULL)
    {
        return root;
    }
    else if (data < root -> data)
    {
        root -> left = DeleteBTNode(root -> left, data);
    }
    else if (data > root -> data)
    {
        root -> right = DeleteBTNode(root -> right, data);
    }
    else
    {
        if (root -> left == NULL && root -> right == NULL)
        {
            free(root);
            root = NULL;
        }
        else if (root -> left == NULL)
        {
            BTNode *temp = root;
            root = root -> right;
            free(temp);
        }
        else if (root -> right == NULL)
        {
            BTNode *temp = root;
            root = root -> left;
            free(temp);
        }
        else
        {
            int minValue = FindMin(root -> right);
            root -> data = minValue;
            root -> right = DeleteBTNode(root -> right, minValue);
        }
    }
    return root;
}

void PromptBT()
{
    printf("1. Insert\n"
            "2. Delete\n"
            "3. Print Preorder\n"
            "4. Print Inorder\n"
            "5. Print Postorder\n"
            "6. Print List\n"
            "7. Search\n"
            "8. Find Min\n"
            "9. Find Max\n"
            "10. Find Height\n"
            "11. Exit\n"
            "Please choose an action: ");
}