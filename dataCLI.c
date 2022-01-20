// A CLI that can store data in different data structures

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "linked_list.h"
#include "array.h"



int main(void)
{
    int choice;
    printf("This is a program to save integers in different data structures.\n");
    printf("1. Array\n"
            "2. Linked List\n"
            "3. Stack\n"
            "4. Queue\n"
            "5. Binary Search Tree\n"
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
            break;
        case 4:
            break;
        case 5:
            break;
    }    
}

