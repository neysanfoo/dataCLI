#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX_SIZE 100
int array_end = 0;

void PromptArray();
void printArray(int arr[]);
void ArrayInsertAtEnd(int arr[], int data);
void ArrayInsertAtStart(int arr[], int data);
void ArrayInsertAtN(int arr[], int n, int data);
void ArrayDeleteAtN(int arr[], int n);

int ArrayMain(void)
{
    int arr[MAX_SIZE];
    int choice;
    int data;
    int n;
    PromptArray();
    while (true)
    {
        scanf("%d", &choice);    
        switch(choice)
        {
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                ArrayInsertAtEnd(arr, data);
                printArray(arr);
                break;
            case 2:
                printf("Enter data: ");
                scanf("%d", &data);
                ArrayInsertAtStart(arr, data);
                printArray(arr);
                break;
            case 3:
                printf("Enter position (0 Indexed): ");
                scanf("%d", &n);
                printf("Enter data: ");
                scanf("%d", &data);
                ArrayInsertAtN(arr, n, data);
                printArray(arr);
                break;
            case 4:
                printf("Enter position (0 Indexed): ");
                scanf("%d", &n);
                ArrayDeleteAtN(arr,n);
                printArray(arr);
                break;        
            case 5:
                printArray(arr);
                break;
            case 6:
                return 0;
                break;
        }
        printf("Please choose another action: ");
    }
}

void printArray(int arr[])
{
    if (array_end <1)
    {
        printf("Empty Array\n");
        return;
    }
    printf("[");
    for (int i = 0; i<array_end; i++)
    {
        printf("%d, ",arr[i]);
    }
    printf("\b\b]");
    printf("\n");
}

void ArrayInsertAtEnd(int arr[], int data)
{
    arr[array_end] = data;
    array_end++;
}

void ArrayInsertAtStart(int arr[], int data)
{
    array_end++;
    for (int i = array_end-1; i > 0; i--)
    {
        arr[i] = arr[i-1];
    }
    arr[0] = data;
}

void ArrayInsertAtN(int arr[], int n, int data)
{
    array_end++;
    for (int i = array_end-1; i>n; i--)
    {
        arr[i] = arr[i-1];
    }
    arr[n] = data;
}

void ArrayDeleteAtN(int arr[], int n)
{
    for (int i = n; i<array_end;i++)
    {
        arr[i] = arr[i+1];
    }
    array_end--;
}

void PromptArray()
{
    printf("1. Insert at end\n"
            "2. Insert at start\n"
            "3. Insert at Nth position\n"
            "4. Delete at Nth position\n"
            "5. Print Array\n"
            "6. Exit\n"
            "Please choose an action: ");
}