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

// Displays all available elements from the array.
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

// Swaps two index's elements among these indexes in the array
void Swap(int *x, int *y)
{
    int temp = *x;

    *x = *y;

    *y = temp;
}

// Appends elements in the end of array.
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

// Inserts elements in the targeted position of array.
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

// Deletes elements in the targeted position of array.
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

// Gets element from the array at a specific index position.
int Get(struct Array array, int index)
{
    if(index >= 0 && index <= array.length)
    {
        return array.array[index];
    }

    return - 1;
}

// Sets element in the array at a specific index position.
void Set(struct Array *array, int index, int setValue)
{
    if(index >= 0 && index < array->length)
    {
        array->array[index] = setValue;
    }
}

// Finds most minimum element in the array.
int Min(struct Array array)
{
    int min = array.array[0];

    for(int i = 0; i < array.length; i++)
    {
        if(array.array[i] < min)
        {
            min = array.array[i];
        }
    }

    return min;
}

// Finds most maximum element in the array.
int Max(struct Array array)
{
    int max = array.array[0];

    for(int i = 0; i < array.length; i++)
    {
        if(array.array[i] > max)
        {
            max = array.array[i];
        }
    }

    return max;
}

// Sums all the elements from array.
int Sum(struct Array array)
{
    int sum = 0;

    for(int i = 0; i < array.length; i++)
    {
        sum = sum + array.array[i];
    }

    return sum;
}

// Finds average from the array.
float Avg(struct Array array)
{
    return (float) (sum(array) / array.length);
}

// Reverses elements in the array.
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


// Shifts array elements in left side in the array.
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

// Shifts array elements in right side in the array.
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

// Rotates array elements in left side in the array.
void leftRotateArray(struct Array *array, int rotate)
{
    int value;

    while(rotate != 0)
    {
        value = array->array[0];

        for(int i = 0; i < array->length - 1; i++)
        {
            array->array[i] = array->array[i + 1];
        }

        array->array[array->length - 1] = value;

        rotate--;
    }
}

// Rotate array elements in right side in the array.
void rightRotateArray(struct Array *array, int rotate)
{
    int value;

    while(rotate != 0)
    {
        value = array->array[array->length - 1];

        for(int i = array->length - 1; i >= 0; i--)
        {
            array->array[i] = array->array[i - 1];
        }

        array->array[0] = value;

        rotate--;
    }
}

// Union operation between two unsorted arrays.
struct Array *unSortedUnion(struct Array *arrayOne, struct Array *arrayTwo)
{
    int i = 0, j = 0, k = 0;

    struct Array *array = (struct Array *) malloc(sizeof(struct Array));

    for(i = 0; i < arrayOne; i++)
    {
        array->array[i] = arrayOne->array[i];
    }

    int l = i;

    while(j < arrayTwo->length)
    {
        k = 0;

        while(k < i)
        {
            if(array->array[k] == arrayTwo->array[j])
            {
                break;
            }

            k++;
        }

        if(k == i)
        {
            array->array[l++] = arrayTwo->array[j];
        }

        j++;
    }

    array->length = l;

    array->size = l;

    return array;
}

// Union operation between two sorted arrays.
struct Array *sortedUnion(struct Array *arrayOne, struct Array *arrayTwo)
{
    int i = 0, j = 0, k = 0;

    struct Array *array = (struct Array *) malloc(sizeof(struct Array));

    while(i < arrayOne->length && j < arrayTwo->length)
    {
        if(arrayOne->array[i] < arrayTwo->array[j])
        {
            array->array[k++] = arrayOne->array[i++];
        }
        else if(arrayTwo->array[j] < arrayOne->array[i])
        {
            array->array[k++] = arrayTwo->array[j++];
        }
        else
        {
            array->array[k++] = arrayOne->array[i++];

            j++;
        }
    }

    for(; i < arrayOne->length; i++)
    {
        array->array[k++] = arrayOne->array[i];
    }

    for(; j < arrayTwo->length; j++)
    {
        array->array[k++] = arrayTwo->array[j];
    }

    array->length = k;

    array->size = k;

    return array;
}

// Intersection operation between two unsorted arrays.
struct Array *unsortedIntersection(struct Array *arrayOne, struct Array *arrayTwo)
{
    int i = 0, j = 0, k = 0;

    struct Array *array = (struct Array *) malloc(sizeof(struct Array));

    while(i < arrayOne->length)
    {
        j = 0;

        while(j < arrayTwo->length)
        {
            if(arrayOne->array[i] == arrayTwo->array[j])
            {
                array->array[k++] = arrayOne->array[j];
            }

            j++;
        }

        i++;
    }

    array->length = k;

    array->size = k;

    return array;
}

// Intersection operation between two sorted arrays.
struct Array *sortedIntersection(struct Array *arrayOne, struct Array *arrayTwo)
{
    int i = 0, j = 0, k = 0;

    struct Array *array = (struct Array *) malloc(sizeof(struct Array));

    while(i < arrayOne->length && j < arrayTwo->length)
    {
        if(arrayOne->array[i] < arrayTwo->array[j])
        {
            i++;
        }
        else if(arrayTwo->array[j] < arrayOne->array[i])
        {
            j++;
        }
        else if(arrayOne->array[i] == arrayTwo->array[j])
        {
            array->array[k++] = arrayOne->array[i++];

            j++;
        }
    }

    array->length = k;

    array->size = k;

    return array;
}

// Difference operation between two unsorted arrays.
struct Array *unsortedDifference(struct Array *arrayOne, struct Array *arrayTwo)
{
    int i = 0, j = 0, k = 0;

    struct Array *array = (struct Array *) malloc(sizeof(struct Array));

    while(i < arrayOne->length)
    {
        j = 0;

        while(j < arrayTwo->length)
        {
            if(arrayOne->array[i] == arrayTwo->array[j])
            {
                break;
            }

            j++;
        }

        if(j == arrayTwo->length)
        {
            array->array[k++] = arrayOne->array[i];
        }

        i++;
    }

    array->length = k;

    array->size = k;

    return array;
}

// Difference operation between two sorted arrays.
struct Array *sortedDifference(struct Array *arrayOne, struct Array *arrayTwo)
{
    int i = 0, j = 0, k = 0;

    struct Array *array = (struct Array *) malloc(sizeof(struct Array));

    while(i < arrayOne->length && j < arrayTwo->length)
    {
        if(arrayOne->array[i] < arrayTwo->array[j])
        {
            array->array[k++] = arrayOne->array[i++];
        }
        else if(arrayTwo->array[j] < arrayOne->array[i])
        {
            j++;
        }
        else
        {
            i++;
        }
    }

    for(; i < arrayOne->length; i++)
    {
        array->array[k++] = arrayOne->array[i];
    }

    array->length = k;

    array->size = k;

    return array;
}

int linearSearch(struct Array *array, int key)
{
    for(int i = 0; i < array->length; i++)
    {
        if(key == array->array[i])
        {
            return i;
        }
    }

    return -1;
}

int linearSearchTransposition(struct Array *array, int key)
{
    for(int i = 0; i < array->length; i++)
    {
        if(key == array->array[i])
        {
            Swap(&array->array[i], &array->array[i - 1]);

            return i;
        }
    }

    return -1;
}

int linearSearchMoveToFront(struct Array *array, int key)
{
    for(int i = 0; i < array->length; i++)
    {
        if(key == array->array[i])
        {
            Swap(&array->array[i], &array->array[0]);

            return i;
        }
    }

    return -1;
}

struct Array *Merge(struct Array *arrayOne, struct Array *arrayTwo)
{
    int i = 0, j = 0, k = 0;

    struct Array *array = (struct Array *) malloc(sizeof(struct Array));

    while(i < arrayOne->length && j < arrayTwo->array[j])
    {
        if(arrayOne->array[i] < arrayTwo->array[j])
        {
            array->array[k++] = arrayOne->array[i++];
        }
        else
        {
            array->array[k++] = arrayTwo->array[j++];
        }
    }

    for(i; i < arrayOne->length; i++)
    {
        array->array[k++] = arrayOne->array[i];
    }

    for(; j < arrayTwo->length; j++)
    {
        array->array[k++] = arrayTwo->array[j];
    }

    array->length = arrayOne->length + arrayTwo->length;

    array->size = array->length;

    return array;
}
