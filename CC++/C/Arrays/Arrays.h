/*
    Arrays.h contains Basic to Advanced Array Data Structures related definition and implementations in C Programming Language.
*/

#include<stdio.h>
#include<stdlib.h>

struct Array
{
    int *array;
    int size;
    int length;
};

// Displays all available elements from the array which is passed as parameter.
void Display(struct Array array)
{
    if(array.length > 0)
    {
        printf("\nElements are in given array: ");

        for(int i = 0; i < array.length; i++)
        {
            printf("%d ", array.array[i]);
        }

        printf("\n");
    }
    else
    {
        printf("\nEmpty Array\n");
    }
}

