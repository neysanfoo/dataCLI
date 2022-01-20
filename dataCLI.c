// A CLI that can store data in different data structures

#include <stdio.h>
#include <stdlib.h>
#include "print.h"
#include "linked_list.c"


int main(void)
{
    int choice;
    printf("This is a program to save integers in different data structures.\n");
    printf("Please choose a data structure: \n"
            "1. Array\n"
            "2. Linked List\n"
            "3. Stack\n"
            "4. Queue\n"
            "5. Binary Search Tree\n");
    scanf("%d", &choice);
    printf("Your choice: %d\n",choice);

}

