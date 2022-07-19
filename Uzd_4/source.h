#ifndef HEADER_FILE
#define HEADER_FILE 
#include <stdio.h>

typedef struct LinkedList
{
    int element;
    struct LinkedList *next;
} List;

void getValidInteger(int *optionNumber);
void readFromFile(FILE **filePointer, List **head);
void makeNewListElement(List **head, int number);
void reverseList(List **head);
void printList(List *head);

#endif 