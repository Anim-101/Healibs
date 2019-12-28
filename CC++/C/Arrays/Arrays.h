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

// Appends elements in the end of array which is passed as parameter.
void Append(struct Array *array, int appendingNumber)
{
    if(array->length < array->size)
    {
        array->array[array->length++] = appendingNumber;
    }
    else
    {
        printf("\nIncrease Array Size, Length -> Size Buffer Overflow\n");
    }
}

// Inserts elements in the targeted position of array which is passed as parameter.
void Insert(struct Arra *array, int index, int insertedNumber)
{
    if(array->length < array->size)
    {
        for(int i = array->length; i > index; i--)
        {
            array->array[i] = array->array[i - 1];
        }

        array->array[index] = insertedNumber;

        array->length--;
    }
    else
    {
        printf("\nIncrease Array Size, Length -> Size Buffer Overflow\n");
    }
}

// Deletes elements in the targeted position of array which is passed as parameter.
int Delete(struct Array *array, int index)
{
    int x = 0;

    if(index > 0 && index < array->length)
    {
        x = array->array[index];

        for(int i = index; i < array->length - 1; i++)
        {
            array->array[i] = array->array[i + 1];
        }

        array->length--;

        return x;
    }

    return 0;
}

// Reverses elements in the array which is passed as parameter.
void reverseArray(struct Array *array)
{
    int *brray;

    brray = (int *) malloc(array->length * sizeof(int));

    for(int i = array->length - 1, j = 0; i >= 0; i--, j++)
    {
        brray[j] = array->array[i];
    }

    for(int i = 0; i < array->lenght; i++)
    {
        array->array[i] = brray[i];
    }
}


// Shifts array elements in left side in the array which is passed as parameter.
void leftShiftArray(struct Array *array, int shift)
{
    while(shift != 0)
    {
        for(int i = 0; i < array->length - 1; i++)
        {
            array->array[i] = array->array[i + 1];
        }

        array->array[array->length - 1] = 0;

        shift--;
    }
}

// Shifts array elements in right side in the array which is passed as parameter.
void rightShiftArray(struct Array *array, int shift)
{
    while(shift != 0)
    {
        for(int i = array->length - 1; i >= 0; i--)
        {
            array->array[i] = array->array[i - 1];
        }

        array->array[0] = 0;

        shift--;
    }
}
