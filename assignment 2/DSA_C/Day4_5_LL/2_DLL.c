#include <stdio.h>
#include <stdlib.h>

// Define a structure for a doubly linked list node
typedef struct Test
{
    int data;
    struct Test *prev, *next;
} Node;

// Global pointers to the first and last nodes of the linked list
Node *first, *last;

// Function prototypes
Node *createNode(int);
void addAtBeg(int);
void addAtEnd(int);
void disp();
void printForward();
void printReverse();

int main()
{
    first = last = NULL; // Initialize the global pointers to NULL
    int i;
    for (i = 0; i < 10; i += 2)
    {
        addAtBeg(100 + i);     // Add nodes with data values 100, 102, ..., at the beginning of the list
        addAtEnd(200 + i + 1); // Add nodes with data values 201, 203, ..., at the end of the list
    }
    disp(); // Display the linked list
}

// Function to create a new node with the given data
Node *createNode(int num)
{
    Node *New = malloc(sizeof(Node)); // Allocate memory for the new node
    if (New != NULL)
    {
        New->data = num;              // Set the data of the new node
        New->prev = New->next = NULL; // Initialize the previous and next pointers to NULL
    }
    return New; // Return a pointer to the new node
}

// Function to add a node with the given data at the beginning of the list
void addAtBeg(int num)
{
    Node *New = createNode(num); // Create a new node with the given data
    if (first == NULL)
    {
        first = last = New; // If the list is empty, set both first and last pointers to the new node
    }
    else
    {
        first->prev = New; // Set the previous pointer of the current first node to the new node
        New->next = first; // Set the next pointer of the new node to the current first node
        first = New;       // Update the first pointer to point to the new node
    }
}

// Function to add a node with the given data at the end of the list
void addAtEnd(int num)
{
    Node *New = createNode(num); // Create a new node with the given data
    if (first == NULL)
    {
        first = last = New; // If the list is empty, set both first and last pointers to the new node
    }
    else
    {
        New->prev = last; // Set the previous pointer of the new node to the current last node
        last->next = New; // Set the next pointer of the current last node to the new node
        last = New;       // Update the last pointer to point to the new node
    }
}

// Function to display the linked list
void disp()
{
    printf("Forward: ");
    printForward(); // Print the list in forward order
    printf("Reverse: ");
    printReverse(); // Print the list in reverse order
    printf("\n-------------------------------\n");
}

// Function to print the linked list in forward order
void printForward()
{
    Node *temp = first; // Start from the first node
    while (temp != NULL)
    {
        printf("%d ", temp->data); // Print the data of the current node
        temp = temp->next;         // Move to the next node
    }
    printf("\n");
}

// Function to print the linked list in reverse order
void printReverse()
{
    Node *temp = last; // Start from the last node
    while (temp != NULL)
    {
        printf("%d ", temp->data); // Print the data of the current node
        temp = temp->prev;         // Move to the previous node
    }
    printf("\n");
}
