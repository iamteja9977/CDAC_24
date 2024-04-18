#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Employee
{
    int id;
    char name[25];
    double salary;
    struct Employee *ptr; // Pointer for storing address
                          // it allows each Employee struct to contain a pointer to another Employee struct, forming a linked list-like structure.
    // This pointer can be used to create a linked list of employees, where each employee node points to the next employee node.
};

// using typedef:
typedef struct Employee Node;
// the typedef keyword to create an alias Node for the struct Employee
// This alias allows us to refer to struct Employee using the shorter name Node.

Node *createNode()
{
    // Yet Another way to allocate space for a struct and assign values to struct
    // by using a struct pointer.
    Node *ptr = malloc(sizeof(struct Employee));
    if (ptr != NULL)
    {
        printf("Enter id, name, salary:");
        scanf("%d,%[^,],%lf", &ptr->id, ptr->name, &ptr->salary);

        // pointing the pointer ptr (next Node pointer) to itself.
        ptr->ptr = ptr;
        // using arrow operator to print variables from a struct pointer
        printf("ID: %d\tName: %s\tSal:%.2lf\n", ptr->id, ptr->name, ptr->salary);
    }
    return ptr;
}

int main()
{
    Node *ptr = createNode();
}
