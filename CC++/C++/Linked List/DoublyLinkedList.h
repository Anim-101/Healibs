#include<iostream>

using namespace std;

class DoublyLinkedList
{
private:
    DoublyLinkedList *previous;
    int data;
    DoublyLinkedLisst *next;

public:
    DoublyLinkedList()
    {
        this.previous = NULL;
        this.data = 0;
        this.next = NULL;
    }

    ~DoublyLinkedList()
    {
        free(this)
    }

    void createNodes(int *array, int numberOfNodes);
    void Display(DoublyLinkedList *pointNode);
    int Length(DoublyLinkedList *pointNode);
}
*firstNode = NULL, *lastNode = NULL, *Head = NULL;


// Creating Doubly Linked List's Nodes
void DoublyLinkedList::createNodes(int *array, int numberOfNodes)
{
    DoublyLinkedList *tempNode = NULL;

    firstNode = new DoublyLinkedList();

    firstNode->next = firstNode->previous = NULL;

    firstNode->data = array[0];

    for(int i = 1; i <= numberOfNodes; i++)
    {
        tempNode = new DoublyLinkedList();

        tempNode->data = array[i];

        tempNode->next = lastNode->next;

        tempNode->previous = lastNode;

        lastNode->next = tempNode;

        lastNode = tempNode;
    }
}

// Creating Display Function
void DoublyLinkedList::Display(DoublyLinkedList *pointNode)
{
    while(pointNode)
    {
        cout << pointNode->data << " ";

        pointNode = pointNode->next;
    }

    cout << endl;
}

