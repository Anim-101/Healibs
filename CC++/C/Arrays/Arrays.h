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

// Swaps two index's elements among these indexes in the array.
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

        array->length++;
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
    return (float) (Sum(array) / array.length);
}

// Min and Max in single scan from the array.
void minMaxArraySingleScan(struct Array array)
{
    int min = array.array[0], max = array.array[0];

    for(int i = 0; i < array.length; i++)
    {
        if(min > array.array[i])
        {
            min = array.array[i];
        }
        else if(max < array.array[i])
        {
            max = array.array[i];
        }
    }

    printf("\nMin from Array: %d\n", min);

    printf("\nMax from Array: %d\n", max);
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

    for(i = 0; i < arrayOne->length; i++)
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

// Linear Search for key from array.
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

// Linear search Transposition version for key from the array.
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

// Linear Search Move To Front version for key from the array.
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

// Merges two arrays into one new array and returns the array.
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

// Finds whether given array is sorted or not.
int isSorted(struct Array array)
{
    for(int i = 0; i < array.length - 1; i++)
    {
        if(array.array[i] > array.array[i + 1])
        {
            return 0;
        }
    }

    return 1;
}

// Rearranges negatives and positives numbers in the array.
void negativePositive(struct Array *array)
{
    int i = 0;

    int j = array->length - 1;

    while(i < j)
    {
        while(array->array[i] < 0)
        {
            i++;
        }

        while(array->array[j] >= 0)
        {
            j--;
        }

        if(i < j)
        {
            Swap(&array->array[i], &array->array[j]);
        }
    }
}

// Finds duplicate elements in sorted array.
void duplicateElementsSorted(struct Array array)
{
    int lastDuplicate = 0;

    printf("\nDuplicate Elements in Lists are: ");

    for(int i = 0; i < array.length; i++)
    {
        if(array.array[i] == array.array[i + 1] && array.array[i] != lastDuplicate)
        {
            printf("%d ", array.array[i]);

            lastDuplicate = array.array[i];
        }
    }

    printf("\n");
}

// Finds duplicate elements in unsorted array.
void duplicateElementsUnSorted(struct Array array)
{
    int count = 0;

    for(int i = 0; i < array.length; i++)
    {
        count = 1;

        if(array.array[i] != -1)
        {
            for(int j = i + 1; j < array.length; j++)
            {
                if(array.array[i] == array.array[j])
                {
                    count++;

                    array.array[j] = -1;
                }
            }

            if(count > 1)
            {
                printf("\n%d has appeared %d times in given array list\n", array.array[i], count);
            }
        }
    }
}

// Finds duplicate elements using hash in unsorted array.
void duplicateElementsUnSortedHash(struct Array array)
{
    struct Array hashArray;

    int max = array.array[0];

    for(int i = 0; i < array.length; i++)
    {
        if(max < array.array[i])
        {
            max = array.array[i];
        }
    }

    hashArray.size = max + 1;

    hashArray.length = max + 1;

    for(int i = 0; i <= hashArray.length; i++)
    {
        hashArray.array[i] = 0;
    }

    for(int i = 0; i < array.length; i++)
    {
        hashArray.array[array.array[i]]++;
    }

    for(int i = 0; i <= hashArray.length; i++)
    {
        if(hashArray.array[i] > 1)
        {
            printf("\n%d has appeared %d times in given array list\n", i, hashArray.array[i]);
        }
    }
}

// Counts duplicate elements in the array.
void countDuplicateElements(struct Array array)
{
    int j = 0;

    for(int i = 0; i < array.length; i++)
    {
        if(array.array[i] == array.array[i + 1])
        {
            j = i + 1;

            while(array.array[j] == array.array[i])
            {
                j++;
            }

            printf("\n%d is appearing %d times in list\n", array.array[i], j - i);

            i = j - 1;
        }
    }
}
