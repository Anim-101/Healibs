/*
    Arrays.h contains Basic to Advanced Array Data Structures related definition and implementations in C++ Programming Language.
*/

#include<iostream>

using namespace std;

class Array
{
private:
	int *array;
	int size;
	int length;

public:
    Array()
    {
        size = 1;

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

    Array unSortedUnion(Array arrayOne, Array arrayTwo);

    Array sortedUnion(Array arrayOne, Array arrayTwo);

    Array unSortedIntersection(Array arrayOne, Array arrayTwo);

    Array sortedIntersection(Array arrayOne, Array arrayTwo);

    Array unSortedDifference(Array arrayOne, Array arrayTwo);

    Array sortedDifference(Array arrayOne, Array arrayTwo);

    int linearSearch(int key);

    int linearSearchTransposition(int key);

    int linearSearchMoveToFront(int key);

    Array Merge(Array arrayOne, Array arrayTwo);

    int isSorted();

    void duplicateElementsSorted();

    void duplicateElementsUnSorted();

    void duplicateElementsUnSortedHash();

    void countDuplicateElements();

}

// Displays all available elements from the array.
void Array::Display()
{
    if(this.length > 0)
    {

        cout << "\nElements are in given array: ";

        for(int i = 0; i < length; i++)
        {
            printf("%d ", array[i]);
        }

        cout << endl;
    }
    else
    {
        cout << "\nEmpty Array\n";
    }

}

// Swaps two index's elements among these indexes in the array.

void Array::Swap(int *x, int *y)
{
    int temp = *x;

    *x = *y;

    *y = temp;
}

// Appends elements in the end of array.
void Array::Append(int appendingNumber)
{
    if(this.length < this.size)
    {
        this.array[length++] = appendingNumber;
    }
    else
    {
        cout << "\nIncrease Array Size, Length -> Size Buffer Overflow\n";
    }
}

// Inserts elements in the targeted position of array.
void Array:Insert(int index, int insertedNumber)
{
    if(this.length < this.size)
    {
        for(int i = this.length; i > index; i--)
        {
            this.array[i] = this.array[i - 1];
        }

        this.array[index] = insertedNumber;

        this.length++;
    }
    else
    {
        cout << "\nIncrease Array Size, Length -> Size Buffer Overflow\n";
    }
}

// Deleted elements in the targeted position of array.
int Array::Delete(int index)
{
    int x = 0;

    if(index > 0 && index < this.length)
    {
       for(int i = index; i < this.length - 1; i++)
       {
           this.array[i] = this.array[i + 1];
       }

       this.length--;

       return x;
    }

    return 0;
}

// Gets element from the array at a specific index position.
int Array::Get(int index)
{
    if(index >= 0 && index <= this.length)
    {
        return this.array[index];
    }

    return -1;
}

// Sets element in array at a specific index position.
void Array::Set(int index, int setValue)
{
    if(index >= 0 && index < this.length)
    {
        this.array[index] = setValue;
    }
}

// Finds most minimum element in the array.
int Array::Min()
{
    int min = this.array[0];

    for(int i = 0; i < length; i++)
    {
        if(this.array[i] < min)
        {
            min = this.array[i];
        }
    }

    return min;
}

// Finds most maximum element in the array.
int Array::Max()
{
    int max = this.array[0];

    for(int i = 0; i < length; i++)
    {
        if(this.array[i] max)
        {
            max = this.array[i];

        }
    }

    return max;
}

// Sums all the elements from array.
int Array::Sum()
{
    int sum = 0;

    for(int i = 0; i < length; i++)
    {
        sum += this.array[i];
    }

    return sum;
}

// Finds average from the array.
float Array::Avg()
{
    return (float) (this.Sum() / this.length);
}

// Min and Max in single scan from the array.
void Array::minMaxArraySingleScan()
{
    int min = this.array[0], max = this.array[0];

    for(int i = 0; i < length; i++)
    {
        if(min > this.array[i])
        {
            min = this.array[i];
        }
        else if(max < this.array[i])
        {
            max = this.array[i];
        }
    }

    cout << "\nMin from Array: " << min << "\n";

    cout << "\nMax from Array: " << max << "\n";
}

// Reverses elements in the array.
void Array::reverseArray()
{
    Array brray = new Array();

    for(int i = this.length - 1, j = 0; i >= 0; i--, j++)
    {
        brray.array[j] = this.array[i];
    }

    for(int i = 0; i < this.length; i++)
    {
        this.array[i] = brray.array[i];
    }
}

// Shifts array elements in left side in the array.
void Array::leftShiftArray(int shift)
{
    while(shift != 0)
    {
        for(int i = 0; i < this.length - 1; i++)
        {
            this.array[i] = this.array[i + 1];
        }

        this.array[this.length - 1] = 0;

        shift--;
    }
}

// Shifts array elements in the right side in the array.
void Array::rightShiftArray(int shift)
{
    while(shift != 0)
    {
        for(int i = this.length - 1; i >= 0; i--)
        {
            this.array[i] = this.array[i - 1];
        }

        this.array[0] = 0;

        shift--;
    }
}

// Rotates array elements in the left in the array.
void Array::leftRotateArray(int rotate)
{
    int value;

    while(rotate != 0)
    {
        value = this.array[0];

        for(int i = 0; i < this.length - 1; i++)
        {
            this.array[i] = this.array[i + 1];
        }

        this.array[length - 1] = value;

        rotate--;
    }
}

// Rotate array elements in right side in the array.

void Array::rightRotateArray(int rotate)
{
    int value;

    while(rotate != 0)
    {
        value = this.array[this.length - 1];

        for(int i = this.length - 1; i >= 0; i--)
        {
            this.array[i] = this.array[i - 1];
        }

        this.array[0] = value;

        rotate--;
    }
}

// Union operation between two unsorted arrays.
Array Array::unSortedUnion(Array arrayOne, Array arrayTwo)
{
    int i = 0, j = 0, k = 0;

    Array array = new Array();

    for(i = 0; i < arrayOne.length; i++)
    {
        array.array[i] = arrayOne.array[i];
    }

    int l = i;

    while(j < arrayTwo.length)
    {
        k = 0;

        while(k < i)
        {
            if(array.array[k] == arrayTwo.array[j])
            {
                break;
            }

            k++;
        }

        if(k == i)
        {
            array.array[l++] = arrayTwo->array[j];
        }

        j++;
    }

    array.length = l;

    array.size = l;

    return array;
}

// Union operation between two sorted arrays.
Array Array::sortedUnion(Array arrayOne, Array arrayTwo)
{
    int i = 0, j = 0, k = 0;

    Array array = new Array();

    while(i < arrayOne.length && arrayTwo.length)
    {
        if(arrayOne.array[i] < arrayTwo.array[j])
        {
            array.array[k++] = arrayOne.array[i++];
        }
        else if(array.array[j] < array.array[i])
        {
            array.array[k++] = arrayTwo.array[i];
        }
        else
        {
            array.array[k++] = arrayOne.array[i++];

            j++;
        }
    }

    for(; i < arrayOne.length; i++)
    {
        array.array[k++] = arrayOne.array[i];
    }

    for(; j < arrayTwo.length; j++)
    {
        array.array[k++] = arrayOne.array[j];
    }

    array.length = k;

    array.size = k;

    return array;
}

// Intersection operation between two unsorted arrays.
Array Array::unSortedIntersection(Array arrayOne, Array arrayTwo)
{
    int i = 0, j = 0, k = 0;

    Array array = new Array();

    while(i < arrayOne.length)
    {
        j = 0;

        while(j < arrayTwo.length)
        {
            if(arrayOne.array[i] == arrayTwo->array[j])
            {
                array.array[k++] = arrayOne.array[j];
            }

            j++;
        }

        i++;
    }

    array.length = k;

    array.size = k;

    return array;
}

// Intersection operation between two sorted arrays.
Array Array::sortedIntersection(Array arrayOne, Array arrayTwo)
{
    int i = 0, j = 0, k = 0;

    Array array = new Array();

    while(i < arrayOne.length && j < arrayTwo.length)
    {
        if(arrayOne.array[i] < arrayTwo.array[j])
        {
            i++;
        }
        else if(arrayTwo.array[j] < arrayOne.array[i])
        {
            j++;
        }
        else if(arrayOne.array[i] == arrayTwo.array[j])
        {
            array.array[k++] = arrayOne.array[i++];
        }
    }

    array.length = k;

    array.size = k;

    return array;
}

// Difference operation between two unsorted arrays.
Array Array::unSortedDifference(Array arrayOne, Array arrayTwo)
{
    int i = 0, j = 0, k = 0;

    Array array = new Array();

    while(i < arrayOne.length)
    {
        j = 0;

        while(j < arrayTwo.length)
        {
            if(arrayOne.array[i] == arrayTwo.array[j])
            {
                break;
            }

            j++;
        }

        if(j == arrayTwo.length)
        {
            array.array[k++] = arrayOne.array[i];
        }

        i++;
    }

    array.length = k;

    array.size = k;

    return array;
}

// Difference operation between two sorted arrays.
Array Array::sortedDifference(Array arrayOne, Array arrayTwo)
{
    int i = 0, j = 0, k = 0;

    Array array = new Array();

    while(i < arrayOne.length && j < arrayTwo.length)
    {
        if(arrayOne.array[i] < arrayTwo.array[j])
        {
            array.array[k++] = arrayOne.array[i++];
        }
        else if(arrayTwo.array[j] < arrayOne.array[i])
        {
            j++;
        }
        else
        {
            i++;
        }
    }

    for(; i < arrayOne.length; i++)
    {
        array.array[k++] = arrayOne.array[i];
    }

    array.length = k;

    array.size = k;

    return array;
}

// Linear Search for key from array.
int Array::LlinearSearch(int key)
{
    for(int i = 0; i < length; i++)
    {
        if(key == array[i])
        {
            return i;
        }
    }

    return -1;
}
// Linear Search Transposition version for key from the array.
int Array::linearSearchTransposition(int key)
{
    for(int i = 0; i < this.length; i++)
    {
        if(key == this.array[i])
        {
            Swap(&this.array[i], &this.array[i - 1]);

            return i;
        }
    }

    return -1;
}

// Linear Search Move To Front version for key from the array.
int Array::linearSearchMoveToFront(int key)
{
    for(int i = 0; i < length; i++)
    {
        if(key == this.array[i])
        {
            Swap(&this.array[i], &this.array[0]);

            return i;
        }
    }

    return -1;
}

// Merges to arrays into one new array and returns the array.
Array Array::Merge(Array arrayOne, Array arrayTwo)
{
    int i = 0, j - 0, k = 0;

    Array array = new Array();

    while(i < arrayOne.length && j < arrayTwo.length)
    {
        if(arrayOne.array[i] < arrayTwo->array[j])
        {
            array.array[k++] = arrayOne.array[i++];
        }
        else
        {
            array.array[k++] = arrayTwo.array[j++];
        }
    }

    for(; i < arrayOne.length; i++)
    {
        array.array[k++] = arrayOne.array[i];
    }

    for(; j < arrayTwo.length; i++)
    {
        array.array[k++] = arrayTwo.array[j];
    }

    array.length = k;

    array.size = k;

    return array;
}

// Finds whether given array is sorted or not.
int Array::isSorted()
{
    for(int i = 0; i < this.length - 1; i++)
    {
        if(this.array[i] > this.array[i + 1])
        {
            return 0;
        }
    }

    return 1;
}

// Rearranges negatives and positives numbers in the array.
void Array::negativePositive()
{
    int i = 0;

    int j = length - 1;

    while(i < j)
    {
        while(this.array[i] < 0)
        {
            i++;
        }

        while(this.array[j] >= 0)
        {
            j--;
        }

        if(i < j)
        {
            Swap(&this.array[i], &this.array[j]);
        }
    }
}

// Finds duplicates elements in sorted
void Array::duplicateElementsSorted()
{
    int lastDuplicate = 0;

    cout << "\nDuplicate Elements in Lists are: ";

    for(int i = 0; i < this.length; i++)
    {
        if(this.array[i] == this.array[i + 1] && this.array[i] != lastDuplicate)
        {
            cout << this.array[i] << " ";

            lastDuplicate = this.array[i];
        }
    }

    cout << "\n";
}

// Finds duplicate elements in unsorted array.
void Array::duplicateElementsUnSorted()
{
    int count = 0;

    for(int i = 0; i < this.length; i++)
    {
        count = 1;

        if(this.array[i] != -1)
        {
            for(int j = i + 1; i < this.length; j++)
            {
                count++;

                this.array[j] = -1;
            }

            if(count > 1)
            {
                cout << "\n" << this.array[i] << " has appeared " << count << " times in given array list\n";
            }
        }
    }
}

// Finds duplicate elements using hash in unsorted array.
void Array::duplicateElementsUnSortedHash()
{
    Array hashArray = new Array();

    int max = this.array[0];

    for(int i = 0; i < this.length; i++)
    {
        if(max < this.array[i])
        {
            max = this.array[i];
        }
    }

    hashArray.size = max + 1;

    hashArray.length = max + 1;

    for(int i = 0; i <= hashArray.length; i++)
    {
        hashArray.array[i] = 0;
    }

    for(int j = 0; j <= this.length; i++)
    {
        hashArray.array[this.array[i]]++;
    }

    for(int i = 0; i <= hashArray.length; i++)
    {
        if(hashArray.array[i] > 1)
        {
            cout << "\n " << i << " has appeared " << hashArray.array[i] << " times in given array list\n";
        }
    }
}

// Counts duplicate elements in the array
void Array::countDuplicateElements()
{
    int j = 0;

    for(int i = 0; i < this.length; i++)
    {
        if(this.array[i] == this.array[i + 1])
        {
            j = i + 1;

            while(this.array[j] == this.array[i])
            {
                j++;
            }

            cout << "\n " << this.array[i] << " has appeared " << j - i << " times in list\n";

            i = j - 1;
        }
    }
}
