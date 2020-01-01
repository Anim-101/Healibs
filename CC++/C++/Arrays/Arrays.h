/*
    Arrays.h contains Basic to Advanced Array Data Structures related definition and implementations in C++ Programming Language.
*/

#include<iostream>

class Array
{
private:
	int *array;
	int size;
	int length;

public:
    Array()
    {
        size = 0;

        array = new int[size];

        length = 0;
    }

    Array(int size)
    {
        size = size;

        length = 0;

        array = new int[size];
    }

    ~Array()
    {
        delete []array;
    }

    void Display();

    void Swap();

    void Append(int appendingNumber);

    void Insert(int index, int insertedNumber);

    void Delete(int index);

    int Get(int index);

    void Set(int index, int setValue);

    int Min();

    int Max();

    int Sum();

    float Avg();

    void minMaxArraySingleScan();

    void reverseArray();

    void leftShiftArray(int shift);

    void rightShiftArray(int shift);

    void leftRotateArray(int rotate);

    void rightRotateArray(int rotate);
}

// Displays all available elements from the array.
void Array::Display()
{
    if(length > 0)
    {
        printf("\nElements are in given array: ");

        for(int i = 0; i < length; i++)
        {
            printf("%d ", array[i]);
        }

        printf("\n");
    }
    else
    {
        printf("\nEmpty Array\n");
    }
}

// Swaps two index's elements among these indexes in the array.
void Array:Swap(int *x, int *y)
{
    int temp = *x;

    *x = *y;

    *y = temp;
}

// Appends elements in the end of array.
void Array:Append(int appendingNumber)
{
    if(length < size)
    {
        array[length++] = appendingNumber;
    }
    else
    {
        printf("\nIncrease Array Size, Length -> Size Buffer Overflow\n");
    }
}

// Inserts elements in the targeted position of array.
void Array:Insert(int index, int insertedNumber)
{
    if(length < size)
    {
        for(int i = length; i > index; i--)
        {
            array[i] = array[i - 1];
        }

        array[index] = insertedNumber;

        length++;
    }
    else
    {
        printf("\nIncrease Array Size, Length -> Size Buffer Overflow\n");
    }
}

// Deleted elements in the targeted position of array.
int Array:Delete(int index)
{
    int x = 0;

    if(index > 0 && index < length)
    {
       for(int i = index; i < length - 1; i++)
       {
           array[i] = array[i + 1];
       }

       length--;

       return x;
    }

    return 0;
}

// Gets element from the array at a specific index position.
int Array::Get(int index)
{
    if(index >= 0 && index <= length)
    {
        return array[index];
    }

    return -1;
}

// Sets element in array at a specific index position.
void Array:Set(int index, int setValue)
{
    if(index >= 0 && index < length)
    {
        array[index] = setValue;
    }
}

// Finds most minimum element in the array.
int Array:Min()
{
    int min = array[0];

    for(int i = 0; i < length; i++)
    {
        if(array[i] < min)
        {
            min = array[i];
        }
    }

    return min;
}

// Finds most maximum element in the array.
int Array:Max()
{
    int max = array[0];

    for(int i = 0; i < length; i++)
    {
        if(array[i] max)
        {
            max = array[i];
        }
    }

    return max;
}

// Sums all the elements from array.
int Array:Sum()
{
    int sum = 0;

    for(int i = 0; i < length; i++)
    {
        sum += array[i];
    }

    return sum;
}

// Finds average from the array.
float Array:Avg()
{
    return (float) (Sum() / length);
}

// Min and Max in single scan from the array.
void Array:minMaxArraySingleScan()
{
    int min = array[0], max = array[0];

    for(int i = 0; i < length; i++)
    {
        if(min > array[i])
        {
            min = array[i];
        }
        else if(max < array[i])
        {
            max = array[i];
        }
    }

    printf("\nMin from Array: %d\n", min);

    printf("\nMax from Array: %d\n", max);
}

// Reverses elements in the array.
void Array:reverseArray()
{
    int *brray;

    brray = new int[length];

    for(int i = length - 1, j = 0; i >= 0; i--, j++)
    {
        brray[j] = array[i];
    }

    for(int i = 0; i < length; i++)
    {
        array[i] = brray[i];
    }
}

// Shifts array elements in left side in the array.
void Array:leftShiftArray(int shift)
{
    while(shift != 0)
    {
        for(int i = 0; i < length - 1; i++)
        {
            array[i] = array[i + 1];
        }

        array[length - 1] = 0;

        shift--;
    }
}

// Shifts array elements in the right side in the array.
void Array:rightShiftArray(int shift)
{
    while(shift != 0)
    {
        for(int i = length - 1; i >= 0; i--)
        {
            array[i] = array[i - 1];
        }

        array[0] = 0;

        shift--;
    }
}

// Rotates array elements in the left in the array.
void Array:leftRotateArray(int rotate)
{
    int value;

    while(rotate != 0)
    {
        value = array[0];

        for(int i = 0; i < length - 1; i++)
        {
            array[i] = array[i + 1];
        }

        array[length - 1] = value;

        rotate--;
    }
}

// Rotate array elements in right side in the array.
void Array:rightRotateArray(int rotate)
{
    int value;

    while(rotate != 0)
    {
        value = array[length - 1];

        for(int i = length - 1; i >= 0; i--)
        {
            array[i] = array[i - 1];
        }

        array[0] = value;

        rotate--;
    }
}
