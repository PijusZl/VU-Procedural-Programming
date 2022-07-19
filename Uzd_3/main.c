// 3 uzduotis, 2 variantas
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* getInput();                                           // gets input from user
FILE* openFile(char *mode);                                 // gets valid file's name and opens/creates a file
char* readFromFile(FILE *file, int *cnt);                   // read words from file
void printToFile(FILE *file, char **data, unsigned *size);  // print results to file

int main()
{
    printf("Enter reading file name:\n");
    FILE *rf = openFile("r");

    printf("Enter writing file name:\n");
    FILE *wf = openFile("w");

    unsigned dataSize = 16, index = 0;
    char **data = malloc(dataSize * sizeof(char *));
    char *buffer;
    int count = 0;

    if(data == NULL)    //checks if error allocating memory
    {
        printf("Error allocating memory\n");
        exit(0);
    }

    while(feof(rf) == 0)
    {
        buffer = readFromFile(rf, &count);

        if(buffer != NULL)
        {
            if(index == dataSize)
            {
                dataSize *= 2;
                data = realloc(data, dataSize * sizeof(char *));

                if(data == NULL) 
                {
                    printf("Error allocating memory\n");
                    exit(0);
                }
            }

            data[index] = calloc(strlen(buffer)+1, 1);

            if(data[index] == NULL)
            {
                printf("Error allocating memory\n");
                exit(0);
            }

            strcpy(data[index], buffer);
            ++index;
        }
    }

    printToFile(wf, data, &index);

    for(int i = 0; i < dataSize; i++)   // free dynamic array
    {
        free(data[i]);
    }
    free(data);

    fclose(wf);

    return 0;
}

char* getInput()
{
    char c = 0;
    int i = 0;
    char *str = malloc(255 * sizeof(char));

    if(str == NULL) 
    {
        printf("Error allocating memory\n");
        exit(0);
    }

    while(1)
    {
        c = getchar();
        if(c != '\n')
        {
            str[i] = c;
            i++;
        }
        else
        {
            str[i] = '\0';
            break;
        }
    }

    return str;
}

FILE* openFile(char *mode)
{
    FILE *file;
    char *name;

    while(1)
    {
        name = getInput();
        file = fopen(name, mode);

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

char* readFromFile(FILE *file, int *cnt)
{
    char c = 0;
    int size = 0;

    char *word;
    char characters[256] = {};
    char reverse[256] = {};
    
    c = fgetc(file);
    ++*cnt;

    while(1)
    {
        if((c == ' ') || (c == '\n') || (feof(file) != 0) || (*cnt == 255))
        {
            if(c == '\n')
            {
                *cnt = 0;
            }
            else if(*cnt == 255)
            {
                while((c != '\n') && !feof(file))
                {
                    c = fgetc(file);
                }

                *cnt = 0;
            }

            if(size > 0)
            {
                for(int j = 0; j < size; j++)
                {
                    reverse[j] = characters[size - j - 1];
                }

                if(strcmp(characters, reverse) == 0)    // checks if word is same as reversed
                {
                    word = characters;
                    return word;
                }
            }
            return NULL;
        }
        else
        {
            characters[size] = c;
            size++;
        }
        c = fgetc(file);
        ++*cnt;
    }
}

void printToFile(FILE *file, char **data, unsigned *size)
{
    for(int i = 0; i < *size; i++)
    {
        fprintf(file, "%s ", data[i]);
    }

    fclose(file);
}