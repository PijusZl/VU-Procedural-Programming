// 1 uzduotis, 7 variantas

#include <stdio.h>

int main()
{
    int G = 0;
    int total_count = 0, positive_count = 0, negative_sum = 0, negative_multiplication = 0;
    int number = 0;

    printf("Enter integer G: \n");
    int input_number;
    char c;

    while (1)
    {
        input_number = scanf("%d%c", &G, &c);

        // checks if G number is valid
        if ((input_number == 2) && (c == '\n'))
        {
            break;
        }
        else
        {
            printf("Sorry, try again \n");
            scanf("%s", &c);
        }
    }
    
    printf("Enter a number sequence (end by entering G): \n");

    while (1)
    {
        input_number = scanf("%d%c", &number, &c);

        if ((input_number == 2) && (c == '\n') && (number == G))
        {
            ++total_count;

            if (number > 0)
            {
                ++positive_count;
            }
            else if (number < 0)
            {
                negative_sum += number;

                if(negative_multiplication != 0)
                {
                    negative_multiplication *= number;
                }
                else
                {
                    negative_multiplication = number;
                }
            }

            break;
        }
        else if ((input_number == 2) && (c == '\n'))
        {
            ++total_count;

            if (number > 0)
            {
                ++positive_count;
            }
            else if (number < 0)
            {
                negative_sum += number;

                if(negative_multiplication != 0)
                {
                    negative_multiplication *= number;
                }
                else
                {
                    negative_multiplication = number;
                }
            }
        }
        else
        {
            printf("Sorry, try again \n");
            scanf("%s", &c);
        }
    }

    //printing results
    printf("Total count of integers: %d \n", total_count);
    printf("Total count of positive integers: %d \n", positive_count);
    
    if(negative_sum == 0)
    {
        printf("There are no negative integers \n");
    }
    else
    {
        printf("Negative integer sum: %d \n", negative_sum);
        printf("Negative integer multiplication: %d \n", negative_multiplication);
    }

    getchar();
    return 0;
}