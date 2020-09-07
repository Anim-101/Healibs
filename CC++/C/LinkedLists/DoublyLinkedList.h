#include<stdio.h>
#include<stdlib.h>

int MIN_INT = -32768;

struct Node
{
    struct Node *previous;
    int data;
    struct Node *next;
}
*firstNode = NULL, *lastNode = NULL, Head = NULL;

void createNodes(int array[], int numberOfNodes)
{
    struct Node *tempNode;

    firstNode = (struct Node *) malloc(sizeof(struct Node));

    firstNode->data = array[0];

    firstNode->previous = firstNode->next = NULL;

    lastNode = firstNode;

    for(int i = 1; i < numberOfNodes; i++)
    {
        tempNode = (struct Node *) malloc(sizeof(struct Node));

        tempNode->data = array[i];

        tempNode->next = lastNode->next;

        tempNode->previous = lastNode;

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

    printf("\n");
}

int Length(struct Node *pointNode)
{
    int length = 0;

    while(pointNode)
    {
        length++;

        pointNode = pointNode->next;
    }

    return legnth;
}

void Insert(struct Node *pointNode, int index, int value)
{
    struct Node *tempNode;

    if(index < 0 || index > Length(pointNode))
    {
        return;
    }

    if(index == 0)
    {
        tempNode = (struct Node *) malloc(sizeof(struct Node));

        tempNode->data = value;

        tempNode->previous = NULL;

        tempNode->next = firstNode;

        tempNode->previous = tempNode;

        firstNode = tempNode;
    }
    else
    {
        for(int i = 0; i < index - 1; i++)
        {
            pointNode = pointNode->next();
        }

        tempNode = (struct Node *) malloc(sizeof(struct Node));

        tempNode->data = value;

        tempNode->previous = pointNode;

        tempNode->next = pointNode->next;

        if(pointNode->next)
        {
            pointNode->next->previous = tempNode;
        }

        pointNode->next = tempNode;
    }
}

void Delete(struct Node *pointNode, int index)
{
    int x = -1;

    if(index < 1 || index > Length(pointNode))
    {
        return -1;
    }

    if(index == 1)
    {
        firstNode = firstNode->next;

        if(firstNode)
        {
            firstNode->previous = NULL;
        }

        x = pointNode->data;

        free(pointNode);
    }
    else
    {
        for(int i = 0; i < index - 1; i++)
        {
            pointNode = pointNode->next;
        }

        pointNode->previous->next = pointNode->next;

        if(pointNode->next)
        {
            pointNode->next->previous = pointNode->previous;
        }

        x = pointNode->data;

        free(pointNode);
    }

    return x;
}
