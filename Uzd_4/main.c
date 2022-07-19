// 4 uzduotis, 5 variantas
#include "source.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

void openMenu(List **head);
FILE* openFile();
char* getFileName();

int main()
{
    List *head = NULL;

    printf("This program creates a singly linked list from integers in a given file and can reverse the created list.");
    openMenu(&head);

    return 0;
}

void openMenu(List **head)
{
    int optionNumber;

    while(1)
    {
        printf ("\nChoose an option what you want this program to do by entering a number:\n");
        printf ("To create a list from a file: [0]\n");
        printf ("To print the created list: [1]\n");
        printf ("To reverse the list: [2]\n");
        printf ("To exit the program: [3]\n");

        getValidInteger(&optionNumber);

        switch(optionNumber)
        {
            case 0:
                printf ("To create a list, enter file name:\n");
                FILE *filePointer = openFile();
                readFromFile(&filePointer, head);
                goto repeat;
            case 1:
                printf("Printing the list:\n");
                printList(*head);
                goto repeat;
            case 2:
                reverseList(head);
                printf("The list is reversed\n");
                goto repeat;
            case 3:
                printf ("Exiting the program...\n");
                fclose(filePointer);
                exit(0);
        }

        repeat: ;
    }
}

FILE* openFile()
{
    FILE *file;
    char *name;

    while(1)
    {
        name = getFileName();
        file = fopen(name, "r");

        if(file != NULL)
        {
            break;
        }
        else
        {
            printf("Error while trying to open the file\n");
            printf("Please, enter a valid file:\n");
        }
    }

    return file;
}

char* getFileName()
{
    char character;
    int index = 0;
    char *name = malloc(255 * sizeof(char));

    assert(name != NULL);

    while(1)
    {
        character = getchar();
        if(character != '\n')
        {
            name[index] = character;
            ++index;
        }
        else
        {
            name[index] = '\0';
            break;
        }
    }

    return name;
}