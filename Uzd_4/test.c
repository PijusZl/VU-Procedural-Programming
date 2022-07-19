// LSP 2110648, pijus.zlatkus@mif.stud.vu.lt, 4 uzduotis, 5 variantas
#include "source.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

void testMakeNewListElement(List **head);
void testReverseList(List **head);
void testPrintList(List *head);

int main()
{
    List *head = NULL;
    printf ("This program tests list functions\n");

    testMakeNewListElement(&head);
    testReverseList(&head);
    testPrintList(head);

    return 0;
}

void testMakeNewListElement(List **head)
{
    makeNewListElement(head, -7);
    assert((*head)->next == NULL);
    assert((*head)->element == -7);
    printf ("First element was inserted successfully\n");

    makeNewListElement(head, -42);
    assert((*head)->next != NULL);
    assert(((*head)->next)->next == NULL);
    assert(((*head)->next)->element == -42);
    printf ("Second element was inserted successfully\n");

    makeNewListElement(head, 2);
    assert(((*head)->next)->next != NULL);
    assert((((*head)->next)->next)->next == NULL);
    assert((((*head)->next)->next)->element == 2);
    printf ("Third element was inserted successfully\n");

    printf("Test with InsertNewListElement function passed successfully\n");
}

void testReverseList(List **head)
{
    reverseList(head);
    assert((*head)->next != NULL);
    assert((*head)->element == 2);
    printf ("First was reversed successfully\n");

    assert((*head)->next != NULL);
    assert(((*head)->next)->next != NULL);
    assert(((*head)->next)->element == -42);
    printf ("Second element was reversed successfully\n");

    assert(((*head)->next)->next != NULL);
    assert((((*head)->next)->next)->next == NULL);
    assert((((*head)->next)->next)->element == -7);
    printf ("Third element was reversed successfully\n");

    printf("Test with reverseList function passed successfully\n");
}

void testPrintList(List *head)
{
    printf("List is: ");
    printList(head);
    printf("\n");
}
