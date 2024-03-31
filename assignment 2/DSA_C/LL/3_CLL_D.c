
// Instructor's code for circular doubldy linked list.
// Please note that in printForward() and printReverse(),
// we have to check for empty lists as well
// otherwise you may get segfault.
#include <stdio.h>
#include <stdlib.h>

// Define the structure for the linked list node
typedef struct Test
{
    int data;
    struct Test *prev, *next;
} Node;

Node *first, *last;

// Function prototypes
Node *createNode(int);
void addAtBeg(int);
void addAtEnd(int);
void disp();
void printForward();
void printReverse();
void deleteAtData(int);

int main()
{
    first = last = NULL; // Initialize pointers
    int i;
    // Insert elements into the linked list
    for (i = 0; i < 10; i += 2)
    {
        addAtBeg(100 + i);    // Add even numbers at the beginning
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
    Node *New = malloc(sizeof(Node)); // Allocate memory
    if (New != NULL)
    {
        New->data = num; // Set data
        New->prev = New->next = NULL; // Set pointers
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
    }
    else
    {
        first->prev = New;
        New->next = first;
        first = New;
        first->prev = last;
        last->next = first;
    }
}

// Function to add a node with given data at the end of the list
void addAtEnd(int num)
{
    Node *New = createNode(num); // Create a new node
    if (first == NULL)
    {
        first = last = New; // If list is empty, set new node as both first and last
    }
    else
    {
        New->prev = last;
        last->next = New;
        last = New;
        last->next = first;
        first->prev = last;
    }
}

// Function to display the list
void disp()
{
    printf("Forward: ");
    printForward(); // Print the list in forward order
    printf("Reverse: ");
    printReverse(); // Print the list in reverse order
    printf("\n-------------------------------\n");
}

// Function to print the list in forward order
void printForward()
{
    Node *temp = first; // Initialize temporary pointer
    if (temp != NULL)
    {
        do
        {
            printf("%d ", temp->data); // Print data
            temp = temp->next; // Move to the next node
        } while (temp != first); // Continue until we reach the first node again
    }
    else
    {
        printf("Empty List");
    }
    printf("\n");
}

// Function to print the list in reverse order
void printReverse()
{
    Node *temp = last; // Initialize temporary pointer
    if (temp != NULL)
    {
        do
        {
            printf("%d ", temp->data); // Print data
            temp = temp->prev; // Move to the previous node
        } while (temp != last); // Continue until we reach the last node again
    }
    else
    {
        printf("Empty List");
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
    Node *temp = first;
    Node *temp_prev = NULL;

    // Traverse through the list to find the node with given data
    do
    {
        if (temp->data == data)
        {
            // Adjust pointers to remove the node
            if (temp == first)
            {
                first = first->next; // Move first pointer to the next node
                last->next = first; // Update last node's next pointer
                if (first != NULL) // Update the new first node's prev pointer
                    first->prev = last;
                else
                    last = NULL; // If the list becomes empty
                free(temp); // Free memory
                return;
            }
            else if (temp == last)
            {
                last = temp_prev; // Update last pointer to the previous node
                last->next = first; // Update new last node's next pointer
                first->prev = last; // Update first node's prev pointer
                free(temp); // Free memory
                return;
            }
            else
            {
                temp_prev->next = temp->next; // Update previous node's next pointer
                temp->next->prev = temp_prev; // Update next node's prev pointer
                free(temp); // Free memory
                return;
            }
        }
        temp_prev = temp; // Move to the next node
        temp = temp->next;
    } while (temp != first); // Continue until we reach the first node again

    // If the data is not found
}

// void deleteAtData(int data)
// {
//     if (first == NULL)
//     {
//         printf("Nothing to delete! Returning...\n");
//         return;
//     }
//     Node *temp = first->next;
//     Node *temp_prev = first;

//     while (temp != first && temp->data != data)
//     {
//         temp_prev = temp;
//         temp = temp->next;
//     }
//     if (temp == first && temp->data != data)
//     {
//         printf("That data does not exist! Returning...\n");
//         return;
//     }
//     else if (temp == first)
//     {
//         temp->next->prev = last;
//         last->next = temp->next;
//         first = temp->next;
//         temp->next = NULL;
//         temp->prev = NULL;
//     }
//     else if (temp == last)
//     {
//         temp_prev->next = first;
//         first->prev = temp_prev;
//         last = temp_prev;
//         temp->next = NULL;
//         temp->prev = NULL;
//     }
//     else
//     {
//         temp->next->prev = temp_prev;
//         temp_prev->next = temp->next;
//         temp->next = NULL;
//         temp->prev = NULL;
//     }
//     free(temp);
// }
