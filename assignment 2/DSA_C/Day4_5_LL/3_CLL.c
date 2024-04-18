#include <stdio.h>
#include <stdlib.h>

typedef struct Test
{
    int data;
    struct Test *next;
} Node;

Node *first, *last; // Global pointers to the first and last nodes of the list

// Function prototypes
Node *createNode(int);
void addAtBeg(int);
void addAtEnd(int);
void disp();
void printForward();
void deleteAtData(int);

int main()
{
    first = last = NULL;
    int i;
    for (i = 0; i < 10; i += 2)
    {
        addAtBeg(100 + i);
        addAtEnd(200 + i + 1);
    }
    disp();
    ///*
    deleteAtData(100);
    printf("After deleting 100\n");
    disp();
    deleteAtData(108);
    printf("After deleting 108\n");
    disp();
    deleteAtData(209);
    printf("After deleting 209\n");
    disp();
    deleteAtData(1000);
    printf("After deleting 1000\n");
    disp();

    //*/
}

Node *createNode(int num)
{
    Node *New = malloc(sizeof(Node));
    if (New != NULL)
    {
        New->data = num;
        New->next = NULL;
    }
    return New;
}

void addAtBeg(int num)
{
    Node *New = createNode(num);
    if (first == NULL)
    {
        first = last = New;
        New->next = New;
    }
    else
    {
        New->next = first;
        first = New;
        last->next = first;
    }
}

void addAtEnd(int num)
{
    Node *New = createNode(num);
    if (first == NULL)
    {
        first = last = New;
        New->next = New;
    }
    else
    {
        last->next = New;
        last = New;
        last->next = first; // Adjust the next pointer of the last node to point back to the first node
    }
}

void disp()
{
    printf("Printing the Linked List:\n");
    printForward();
    /*
    printf("Reverse: ");
    printReverse();
    */
    printf("\n-------------------------------\n");
}

void printForward()
{
    Node *temp = first;
    if (temp != NULL)
    {
        while (temp->next != first)
        {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("%d ", temp->data);
    }
    else
    {
        printf("Empty List");
    }
    printf("\n");
}

void deleteAtData(int data)
{
    if (first == NULL)
    {
        printf("Nothing to delete! Returning...\n");
        return;
    }
    Node *temp = first->next;
    Node *temp_prev = first;

    while (temp != first && temp->data != data)
    {
        temp_prev = temp;
        temp = temp->next;
    }
    if (temp == first && temp->data != data)
    {
        printf("That data does not exist! Returning...\n");
        return;
    }
    else if (temp == first)
    {
        last->next = temp->next;
        first = temp->next;
        temp->next = NULL;
    }
    else if (temp == last)
    {
        temp_prev->next = first;
        last = temp_prev;
        temp->next = NULL;
    }
    else
    {
        temp_prev->next = temp->next;
        temp->next = NULL;
    }
    free(temp);
}
