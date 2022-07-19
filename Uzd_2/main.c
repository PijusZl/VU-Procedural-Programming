// 2 uzduotis, 10 variantas
#include <stdio.h>
#include <stdlib.h>

void reading_input(int *N, int sqc[]);      // reads number sequence from user and put it in an araay
int get_valid_integer();                    // takes input from the user and checks if it is an integer
void sorting_sequence(int *N, int sqc[]);   // sorts numbers in array to be first negative numbers and then positive numbers
void printing(int *N, int sqc[]);           // prints sorted array

int main()
{
    int n;              // defines how many numbers can be in array
    int sequence[n];

    reading_input(&n, sequence);
    sorting_sequence(&n, sequence);
    printing(&n, sequence);

    return 0;
}

void reading_input(int *N, int sqc[])
{
    int input;

    printf("Enter integer N (amount of numbers in sequence): \n");

    // takes input N and checks if number is valid
    input = get_valid_integer();

    while((input < 0) || (input > 255))
    {
        printf("Invalid input, try again \n");
        input = get_valid_integer();
    }

    *N = input;
 
    printf("\nEnter a %d number sequence:\n", *N);

    // takes input from user and then puts it in to array
    for(int i = 0; i < *N; ++i)
    {
        input = get_valid_integer();
        sqc[i] = input;
    }
}

int get_valid_integer()
{
    int input_count, integer;
    char c;

    while(1)
    {
        input_count = scanf("%d", &integer);
        c = getchar();

        // checks if number is valid
        if ((input_count == 1) && (c == '\n') && (integer < 0))
        {
            while(c != '\n')
            {
                    c = getchar();
            }
            break;
        }
        else if ((input_count == 1) && (c == '\n'))
        {
            break;
        }
        else
        {
            printf("Invalid input, try again \n");
            if(c != '\n')
            {
                while(c != '\n')
                {
                    c = getchar();
                }
            }
        }
    }

    return integer;
}

void sorting_sequence(int *N, int sqc[])
{
    int index = 0;
    int temp;

    // sorts array to be first negative numbers and then positive numbers while keeping exact positions
    while(index < *N)
    {
        if((sqc[index] >= 0) && (sqc[index + 1] < 0) && ((index + 1) < *N) && (index == 0))
        {
            temp = sqc[index];
            sqc[index] = sqc[index + 1];
            sqc[index + 1] = temp;
            ++index;
        }
        else if((sqc[index] >= 0) && (sqc[index + 1] < 0) && ((index + 1) < *N))
        {
            temp = sqc[index];
            sqc[index] = sqc[index + 1];
            sqc[index + 1] = temp;
            // if numbers are sorted then index go back by 1
            --index;
        }
        else
        {
            ++index;
        }
    }
}

void printing(int *N, int sqc[])
{
    printf("\nNew sorted number sequence is:\n");

    for(int i = 0; i < *N; i++)
    {
        printf("%d ", sqc[i]);
    }
}