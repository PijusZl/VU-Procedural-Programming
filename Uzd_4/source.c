#include "source.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

void getValidInteger(int *optionNumber)
{
    int input_count;
    char character;

    while(1)
    {
        input_count = scanf("%d%c", optionNumber, &character);

        if ((input_count == 2) && (character == '\n') && (*optionNumber <= 3) && (*optionNumber >= 0))
        {
            break;
        }
        else if ((input_count == 2) && (character == '\n'))
        {
            printf("A number must be between 0 and 3. Try again \n");
        }
        else
        {
            printf("Invalid input, try again \n");
            while(character != '\n')
            {
                character = getchar();
            }
        }
    }
}

void readFromFile(FILE **filePointer, List **head)
{
    int number;
    char *string = calloc(255, sizeof(char)), *text;;
    char *word;


    while (fgets(string, 255, *filePointer) != NULL)
    {
        word = strtok(string, " \n");

        if (word != NULL)
        {
            if (strspn(word, "0123456789") == strlen(word))
            {
                number = atoi(word);
                assert(number > INT_MIN);
                assert(number < INT_MAX);

                makeNewListElement(head, number);
            }
            else if (word[0] == '-')
            {
                if (strspn(word, "-0123456789") == strlen(word))
                {
                    number = atoi(word);
                    assert(number > INT_MIN);
                    assert(number < INT_MAX);

                    makeNewListElement(head, number);
                }
            }
        }
            
        do
        {
            word = strtok(NULL, " \n");

            if(word != NULL)
            {
                if (strspn(word, "0123456789") == strlen(word))
                {
                    number = atoi(word);
                    assert(number > INT_MIN);
                    assert(number < INT_MAX);

                    makeNewListElement(head, number);
                }
                else if (word[0] == '-')
                {
                    if (strspn(word, "-0123456789") == strlen(word))
                    {
                        number = atoi(word);
                        assert(number > INT_MIN);
                        assert(number < INT_MAX);

                        makeNewListElement(head, number);
                    }
                }
            }

        } while (word != NULL);
    }
}

void makeNewListElement(List **head, int number)
{   
    List *newElement = (List*) malloc(sizeof(List));
    List *currentElement = *head;

    assert(newElement != NULL);

    newElement->element = number;
    newElement->next = NULL;

    while((currentElement != NULL) && (currentElement->next != NULL))
    {
        currentElement = currentElement->next;
    }

    if (currentElement != NULL)
    {
        currentElement->next = newElement;
    }
    else
    {
        *head = newElement;
    }
}

void reverseList(List **head)
{
    List *previousElement = NULL;
    List *currentElement = *head;
    List *nextElement = NULL;

    while (currentElement != NULL)
    {
        nextElement = currentElement->next;
        currentElement->next = previousElement;
        previousElement = currentElement;
        currentElement = nextElement;
    }

    *head = previousElement;
}

void printList(List *head)
{
    if (head == NULL)
    {
        return;
    }

    printf("%d ", head->element);

    printList(head->next);
}