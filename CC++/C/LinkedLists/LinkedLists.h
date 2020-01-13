#include<stdio.h>
#include<stdlib.h>

int MIN_INT = -32768;

struct Node
{
    int data;
    struct Node *next;
}
*firstNode = NULL, *secondNode = NULL, *Head = NULL;

void createNodes(int array [], int numberOfNodes)
{
    if(numberOfNodes <= 0)
    {
        printf("\nDon't Prank with This Library\n");
    }
    else
    {
        struct Node *tempNode, *lastNode;

        firstNode = (struct Node *) malloc(sizeof(struct Node));

        firstNode->data = array[0];

        firstNode->next = NULL;

        lastNode = firstNode;

        for(int i = 0; i < numberOfNodes; i++)
        {
            tempNode = (struct Node *) malloc(sizeof(struct Node));

            tempNode->data = array[i];

            tempNode->next = NULL;

            lastNode->next = tempNode;

            lastNode = tempNode;
        }
    }
}

void createCircularNodes(int array [], int numberOfNodes)
{
    struct Node *tempNode, *lastNode;

    Head = (struct Node *) malloc(sizeof(struct Node));

    Head->data = array[0];

    Head->next = Head;

    lastNode = Head;

    for(int i = 1; i < numberOfNodes; i++)
    {
        tempNode = (struct Node *) malloc(sizeof(struct Node));

        tempNode->data = array[i];

        tempNode->next = lastNode->next;

        lastNode->next = tempNode;

        lastNode = tempNode;
    }
}

void Display(struct Node *pointNode)
{
    while(pointNode)
    {
        printf("%d ", pointNode->data);

        pointNode = pointNode->next;
    }
}

void recursiveDisplay(struct Node *pointNode)
{
    if(pointNode == NULL)
    {
        return;
    }
    else
    {
        printf("%d ", pointNode->data);

        recursiveDisplay(pointNode->next);
    }
}

void displayCircularList(struct Node *pointNode)
{
    do
    {
        printf("%d ", pointNode->data);

        pointNode = pointNode->next;
    }
    while(pointNode != Head)
}

void recursiveDisplayCircularList(struct Node *pointNode)
{
    static int flag = 0;

    if(pointNode != Head || flag == 0)
    {
        flag = 1;

        printf("%d ", pointNode->data);

        recursiveDisplayCircularList(pointNode->next);
    }

    flag = 0;
}

int Count(struct Node *pointNode)
{
    int count = 0;

    while(pointNode)
    {
        count++;

        pointNode = pointNode->next;
    }

    return count;
}

int recursiveCount(struct Node *pointNode)
{
    if(pointNode == NULL)
    {
        return 0;
    }
    else
    {
        return recursiveCount(pointNode->next) + 1;
    }
}

int maxElement(struct Node *pointNode)
{
    int max = pointNode->data;

    while(pointNode)
    {
        if(pointNode->data > max)
        {
            max = pointNode->data;
        }

        pointNode = pointNode->next;
    }

    return max;
}

int maxElementRecursive(struct Node *pointNode)
{
    int x = 0;

    if(pointNode == NULL)
    {
        return MIN_INT;
    }
    else
    {
        x = maxElementRecursive(pointNode->next);

        if(x > pointNode->data)
        {
            return x;
        }
        else
        {
            return pointNode->data;
        }
    }
}

int minElement(struct Node *pointNode)
{
    int min = pointNode->data;

    while(pointNode)
    {
        if(pointNode->data < min)
        {
            min = pointNode->data;
        }

        pointNode = pointNode->next;
    }

    return min;
}

int addElements(struct Node *pointNode)
{
    int sum = 0;

    while(pointNode)
    {
        sum = sum + pointNode->data;

        pointNode = pointNode->next;
    }

    return sum;
}

int addElementsRecursive(struct Node *pointNode)
{
    if(pointNode == NULL)
    {
        return 0;
    }
    else
    {
        return addElementRecursive(pointNode->next) + pointNode->data;
    }
}

int isSorted(struct Node *pointNode)
{
    int x = -32768;

    while(pointNode)
    {
        if(x > pointNode->data)
        {
            return 0;
        }

        x = pointNode->data;

        pointNode = pointNode->next;
    }

    return 1;
}

int isLoop(struct Node *pointNodeLoop)
{
    struct Node *pointNode, *tempNode;

    pointNode = tempNode = pointNodeLoop;

    while(pointNode && tempNode && pointNode != tempNode)
    {
        pointNode = pointNode->next;

        tempNode = tempNode->next;

        tempNode = tempNode != NULL ? tempNode->next : NULL;
    }

    if(pointNode == tempNode)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void Insert(int index, int data)
{
    struct Node *tempNode, *pointNode;

    if(index == 0)
    {
        tempNode = (struct Node *) malloc(sizeof(struct Node));

        tempNode->data = data;

        tempNode->next = firstNode;
    }
    else
    {
        pointNode = firstNode;

        for(int i = 0; i < index - 1 && pointNode; i++)
        {
            pointNode = pointNode->next;
        }

        if(pointNode)
        {
            tempNode = (struct Node *) malloc(sizeof(struct Node));

            tempNode->data = data;

            tempNode->next = pointNode->next;

            pointNode->next = tempNode;
        }
        else
        {
            printf("\nCan't Insert, Invalid Position in Memory Heap\n");
        }
    }
}

void createByInsert(struct Node *pointNode, int index, int setValue)
{
    struct Node *tempNode;

    if((index < 0) || (index > Count(firstNode)))
    {
        printf("Index Overflow");
    }
    else
    {
        tempNode = (struct Node *) malloc(sizeof(struct Node));

        tempNode->data = setValue;

        if(index == 0)
        {
            tempNode->next = firstNode;

            firstNode = tempNode;
        }
        else
        {
            for(int i = 0; i < index - 1; i++)
            {
                pointNode = pointNode->next;
            }

            tempNode->next = pointNode->next;

            pointNode->next = tempNode;
        }
    }
}

void sortedInsert(struct Node *pointNode, int setValue)
{
    struct Node *tempNode, *lastNode = NULL;

    tempNode = (struct Node *) malloc(sizeof(struct Node));

    tempNode->data = setValue;

    tempNode->next = NULL;

    if(firstNode == NULL)
    {
        firstNode = tempNode;
    }
    else
    {
        while(pointNode && pointNode->data < setValue)
        {
            lastNode = pointNode;

            pointNode = pointNode->next;
        }

        if(pointNode == firstNode)
        {
            tempNode->next = firstNode;

            firstNode = tempNode;
        }
        else
        {
            tempNode->next = lastNode->next;

            lastNode->next = tempNode;
        }
    }
}

void insertNodeAtLast(int setValue)
{
    struct Node *tempNode, *lastNode = NULL;

    tempNode = (struct Node *) malloc(sizeof(struct Node));

    tempNode->data = setValue;

    tempNode->next = NULL;

    if(firstNode == NULL)
    {
        firstNode = tempNode;

        lastNode = tempNode;
    }
    else
    {
        lastNode->next = tempNode;

        lastNode = tempNode;
    }
}

int Delete(struct Node *pointNode, int index)
{
    struct Node *tempNode = NULL;

    int value;

    if((index < 0) || (index > Count(pointNode)))
    {
        printf("Index Overflow");

        return -1;
    }
    else
    {
        if(index == 1)
        {
            tempNode = firstNode;

            value = firstNode->data;

            firstNode = firstNode->next;

            free(tempNode);

            return value;
        }
        else
        {
            for(int i = 0; i < index - 1; i++)
            {
                tempNode = pointNode;

                pointNode = pointNode->next;
            }

            tempNode->next = pointNode->next;

            value = pointNode->next;

            free(pointNode);

            return value;
        }
    }
}

void removeDuplicate(struct Node *pointNode)
{
    struct Node *lastNode;

    lastNode = pointNode->next;

    while(lastNode != NULL)
    {
        if(pointNode->data != lastNode->data)
        {
            pointNode = lastNode;

            lastNode = lastNode->next;
        }
        else
        {
            pointNode->next = lastNode->next;

            free(lastNode);

            lastNode = pointNode->next;
        }
    }
}

void reverseListUsingSlidingPointers(struct Node *pointNode)
{
    struct Node *tempNode = NULL, *lastNode = NULL;

    while(pointNode != NULL)
    {
        lastNode = tempNode;

        tempNode = pointNode;

        pointNode = pointNode->next;

        tempNode->next = lastNode;
    }

    firstNode = tempNode;
}

void reverseUsingArray(struct Node *pointNode)
{
    int *array, i = 0;

    array = (int *) malloc(sizeof(int) * Count(pointNode));

    struct Node *tempNode = pointNode;

    while(tempNode != NULL)
    {
        array[i] = tempNode->next;

        tempNode = tempNode->next;

        i++;
    }

    tempNode = pointNode;

    i--;

    while(tempNode != NULL)
    {
        array[i] = tempNode->data;

        tempNode = tempNode->next;

        i++;
    }

    tempNode = pointNode;

    i--;

    while(tempNode != NULL)
    {
        tempNode->data = array[i];

        tempNode = tempNode->next;

        i--;
    }
}

struct Node *linearSearch(struct Node *pointNode, int key)
{
    while(pointNode != NULL)
    {
        if(key == pointNode->data)
        {
            return pointNode;
        }

        pointNode = pointNode->next;
    }

    return NULL;
}

struct Node *moveToFrontLinearSearch(struct Node *pointNode, int key)
{
    struct Node *pointPreviousPointNode;

    while(pointNode != NULL)
    {
        if(key == pointNode->data)
        {
            previousPointNode->next = pointNode->next;

            pointNode->next = firstNode;

            firstNode = pointNode;

            return pointNode;
        }

        previousPointNode = pointNode;

        pointNode = pointNode->next;
    }

    return NULL;
}

struct mergeTwoSortedLists(struct Node *pointNodeFirst, struct Node *pointNodeSecond)
{
    struct Node *tempNode, *lastNode;

    if(pointNodeFirst->data < pointNodeSecond->data)
    {
        tempNode = lastNode = pointNodeFirst;

        pointNodeFirst = pointNodeFirst->next;

        tempNode->next = NULL;
    }
    else
    {
        tempNode = lastNode = pointNodeSecond;

        pointNodeSecond = pointNodeSecond->next;

        tempNode->next = NULL;
    }

    while(pointNodeFirst && pointNodeSecond)
    {
        if(pointNodeFirst->data < pointNodeSecond->data)
        {
            lastNode->next = pointNodeFirst;

            lastNode = pointNodeFirst;

            pointNodeFirst = pointNodeFirst->next;

            lastNode->next = NULL;
        }
        else
        {
            lastNode->next = pointNodeSecond;

            lastNode = pointNodeSecond;

            pointNodeSecond = pointNodeSecond->next;

            lastNode->next = NULL;
        }
    }

    if(pointNodeFirst)
    {
        lastNode->next = pointNodeFirst;
    }

    if(pointNodeSecond)
    {
        lastNode->next = pointNodeSecond;
    }

    pointNodeFirst = NULL;

    pointNodeSecond = NULL;

    firstNode = tempNode;
}
