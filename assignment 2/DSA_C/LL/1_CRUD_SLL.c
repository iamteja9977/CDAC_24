#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure named Employee to hold employee details
struct Employee
{
    int id;               // Employee ID
    char name[25];        // Employee name
    double salary;        // Employee salary
    struct Employee *ptr; // Pointer to the next employee node
};

// Define an alias 'Node' for struct Employee using typedef
typedef struct Employee Node;

// Declare a global variable 'first' to store the head of the linked list
Node *first = NULL;

// Function to create a new employee node
Node *createNode()
{
    // Allocate memory for a new employee node
    Node *ptr = malloc(sizeof(struct Employee));
    if (ptr != NULL)
    {
        // Prompt the user to enter employee details
        printf("Enter id, name, salary:");
        // Read employee details from the user input
        scanf("%d, %[^,], %lf", &ptr->id, ptr->name, &ptr->salary);
        // Initialize the pointer to the next employee node as NULL
        ptr->ptr = NULL;
        // Print the entered employee details
        printf("ID: %d\tName: %s\tSal: %.2lf\n", ptr->id, ptr->name, ptr->salary);
        printf("\n");
    }
    // Return a pointer to the created employee node
    return ptr;
}

// Function to add a new employee node at the beginning of the linked list
void addAtBeg()
{
    // Create a new employee node
    Node *New = createNode();
    if (first == NULL)
    {                // If the list is empty
        first = New; // Set the new node as the first node
    }
    else
    {
        // Make the new node point to the current first node
        New->ptr = first;
        // Update the first node to point to the new node
        first = New;
    }
}

// Function to add a node at the end of the list
void addAtEnd()
{
    // Create a new employee node
    Node *New = createNode();
    if (first == NULL)
    {                // If the list is empty
        first = New; // Set the new node as the first node
    }
    else
    {
        Node *temp = first;
        // Traverse the list to find the last node
        while (temp->ptr != NULL)
        {
            temp = temp->ptr;
        }
        // Make the last node point to the new node
        temp->ptr = New;
    }
}

// Function to add a new employee node at a specific position in the linked list
void addAtPosition(int position)
{
    if (position < 0)
    { // If the position is invalid
        printf("Invalid position\n");
        return;
    }
    if (position == 0)
    { // If adding at the beginning
        addAtBeg();
        return;
    }
    // Create a new employee node
    Node *New = createNode();
    Node *temp = first;
    int currentPosition = 0; // Initialize currentPosition

    if (first == NULL)
    {
        first = New;
    }
    else
    {
        while (temp->ptr != NULL && currentPosition < position - 1)
        {
            temp = temp->ptr;
            currentPosition++;
        }
        New->ptr = temp->ptr;
        temp->ptr = New;
    }
}

void deleteAtPosition(int position)
{
    if (first == NULL)
    { // If the list is empty
        printf("List is empty\n");
        return;
    }
    if (position == 1)
    { // If deleting the first node
        Node *temp = first;
        // Update the first node to point to the next node
        first = first->ptr;
        // Free the memory allocated for the deleted node
        free(temp);
        return;
    }
    Node *temp_prev = NULL;
    Node *temp = first;
    int currentPosition = 1;
    // Traverse the list to find the node before the one to be deleted
    while (temp->ptr != NULL && currentPosition < position)
    {
        temp_prev = temp;
        temp = temp->ptr;
        currentPosition++;
    }
    if (temp == NULL)
    { // If the specified position is invalid
        printf("Invalid position\n");
        return;
    }
    // Make the previous node point to the node after the one to be deleted
    temp_prev->ptr = temp->ptr;
    // Free the memory allocated for the deleted node
    free(temp);
}


    // Function to display the employee details in the linked list
    void displayList()
    {
        Node *temp = first;
        printf("\n\nList:\n");
        // Traverse the list and print each employee detail
        while (temp != NULL)
        {
            printf("ID: %d, Name: %s, Salary: %.2lf\n", temp->id, temp->name, temp->salary);
            temp = temp->ptr;
        }
        printf("\n");
    }

    // Main function
    int main()
    {
        // Add nodes at the beginning of the list
        addAtBeg();
        addAtBeg();
        addAtBeg();
        printf(" \nAfter  3 employees details addAtBeg the list is :");
        displayList();

        // Add nodes at the end of the list
        addAtEnd();
        addAtEnd();
        printf(" \nAfter addAtEnd the list is :");
        displayList();

        // Add nodes at specific positions in the list
        addAtPosition(2);
        addAtPosition(4);
        printf(" \nAfter addAtPosition the list is :");
        displayList();

        // Delete nodes at specific positions in the list
        deleteAtPosition(1);
        deleteAtPosition(3);
        printf(" \nAfter Deletion the list is :");
        displayList();

        return 0;
    }
