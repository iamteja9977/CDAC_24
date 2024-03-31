#include <stdio.h>
#include <stdlib.h>

// Define a structure for the linked list node
typedef struct Test
{
    int data;
    struct Test *next; // Pointer to the next node
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
    first = last = NULL; // Initialize pointers to NULL
    int i;
    // Insert elements in the linked list
    for (i = 0; i < 10; i += 2)
    {
        addAtBeg(100 + i);     // Add even numbers at the beginning
        addAtEnd(200 + i + 1); // Add odd numbers at the end
    }
    disp(); // Display the list

    // Test deletion operations
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

    return 0;
}

// Function to create a new node with given data
Node *createNode(int num)
{
    Node *New = malloc(sizeof(Node)); // Allocate memory for the new node
    if (New != NULL)
    {
        New->data = num;  // Set data of the new node
        New->next = NULL; // Set next pointer to NULL
    }
    return New;
}

// Function to add a node with given data at the beginning of the list
void addAtBeg(int num)
{
    Node *New = createNode(num); // Create a new node
    if (first == NULL)
    {
        first = last = New; // If list is empty, set new node as both first and last
        New->next = New;    // Make it circular
    }
    else
    {
        New->next = first;  // Set new node's next pointer to point to the current first node
        first = New;        // Update first pointer to point to the new node
        last->next = first; // Make the last node point to the new first node
    }
}

// Function to add a node with given data at the end of the list
void addAtEnd(int num)
{
    Node *New = createNode(num); // Create a new node
    if (first == NULL)
    {
        first = last = New; // If list is empty, set new node as both first and last
        New->next = New;    // Make it circular
    }
    else
    {
        last->next = New;   // Set current last node's next pointer to point to the new node
        last = New;         // Update last pointer to point to the new node
        last->next = first; // Make the new last node point to the first node to maintain circularity
    }
}

// Function to display the list
void disp()
{
    printf("Printing the Linked List:\n");
    printForward(); // Print the list in forward order
    printf("\n-------------------------------\n");
}

// Function to print the list in forward order
void printForward()
{
    Node *temp = first; // Initialize temporary pointer to traverse the list
    if (temp != NULL)
    {
        while (temp->next != first)
        {
            printf("%d ", temp->data); // Print data of the current node
            temp = temp->next;         // Move to the next node
        }
        printf("%d ", temp->data); // Print data of the last node
    }
    else
    {
        printf("Empty List"); // If list is empty
    }
    printf("\n");
}

// Function to delete the node with given data from the list
void deleteAtData(int data)
{
    if (first == NULL)
    {
        printf("Nothing to delete! Returning...\n");
        return;
    }
    Node *temp = first->next; // Initialize pointers to traverse the list
    Node *temp_prev = first;

    // Traverse through the list to find the node with given data
    while (temp != first && temp->data != data)
    {
        temp_prev = temp;
        temp = temp->next;
    }
    // If node with given data is not found
    if (temp == first && temp->data != data)
    {
        printf("That data does not exist! Returning...\n");
        return;
    }
    // Adjust pointers to remove the node
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
    free(temp); // Free memory allocated to the deleted node
}
