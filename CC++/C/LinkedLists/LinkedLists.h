#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *next;
}
*firstNode = NULL, *secondNode = NULL;

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

