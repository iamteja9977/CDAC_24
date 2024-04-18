#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Structure to represent an employee
struct Employee {
	int id;
	struct Employee *next; // Pointer for storing next address.
};

typedef struct Employee Node; // Typedef for struct Employee as Node

// Function prototypes
Node* createNode(int);
void addAtBeg(Node**, int);
void addAtEnd(Node**, int);
void addAtPos(Node**, int, int);
void deleteAtPos(Node**, int);
void disp(Node*);

// Main function
int main() {

	// Head of linked list:
	Node *first = NULL; // local variable
	// Notice how we are passing head of linked list to every function,
	// this helps eliminate a global variable which was head of LL.
	// It also helps us use the same functions for multiple different linked lists
	// with different head pointers.
	//
	// Apart from that we are also passing Node data in parameters.
	//
	// If you notice, we are passing address of head pointer
	// this is because all function arguments are pass by value in C/C++
	// therefore in order to change that exact head pointer,
	// we have to pass a pointer to that pointer.
	
	// Adding nodes at the beginning and end of the linked list
	addAtBeg(&first, 1001);
	addAtEnd(&first, 1002);
	addAtEnd(&first, 1003);
	disp(first);
	
	// Adding nodes at specified positions in the linked list
	addAtPos(&first, 1004, 2);
	addAtPos(&first, 1005, 3);
	addAtPos(&first, 1010, 5);
	disp(first);
	
	// Deleting nodes at specific positions in the linked list
	deleteAtPos(&first, 2);
	disp(first);
	deleteAtPos(&first, 4);
	disp(first);

	return 0;
}

// Function to create a new node
Node* createNode(int data){
	Node* ptr = malloc(sizeof(struct Employee)); // Allocate memory for a new node
	if(ptr != NULL){
		ptr->id = data; // Assign data to the node
		ptr->next = NULL; // Initialize next pointer as NULL
	}
	return ptr; // Return the pointer to the new node
}

// Function to add a new node at the beginning of the linked list
void addAtBeg(Node** first, int data){
	Node* New = createNode(data); // Create a new node
	if(*first == NULL){
		*first = New; // If the list is empty, set the new node as the first node
	}
	else{
		New->next = *first; // Make the new node point to the current first node
		*first = New; // Update the first node to point to the new node
	}
}

// Function to add a new node at the end of the linked list
void addAtEnd(Node** first, int data){
	Node* New = createNode(data); // Create a new node
	if(*first == NULL){
		*first = New; // If the list is empty, set the new node as the first node
	}
	else{
		Node* temp = *first;
		// Traverse to the last node
		while(temp->next != NULL){
			temp = temp->next;
		}
		temp->next = New; // Make the last node point to the new node
	}
}

// Function to add a new node at a specified position in the linked list
void addAtPos(Node** first, int data, int pos){
	Node* New = createNode(data); // Create a new node
	if(*first == NULL){
		*first = New; // If the list is empty, set the new node as the first node
	}
	else{
		int cnt = 1;
		Node* temp = *first;
		// Traverse to the node before the specified position
		while(temp->next != NULL && cnt < pos-1){
			temp = temp->next;
			cnt++;
		}
		New->next = temp->next; // Make the new node point to the node at the specified position
		temp->next = New; // Make the node before the specified position point to the new node
	}
}

// Function to delete a node at a specified position in the linked list
void deleteAtPos(Node** first, int pos){
	if(*first == NULL){
		printf("List is empty... Nothing to do\n");
		return;
	}
	Node* temp = *first;
	if(pos == 1){
		*first = (*first)->next; // If deleting the first node, update the first pointer
	}
	else{
		int cnt = 1;
		Node* prev = NULL;
		// Traverse to the node at the specified position
		while(temp!=NULL && cnt < pos){
			prev = temp;
			temp = temp->next;
			cnt++;
		}
		if(temp == NULL){
			printf("%d: No such position\n", pos); // If specified position doesn't exist
			return;
		}
		prev->next = temp->next; // Make the previous node point to the next node
	}
	free(temp); // Free the memory allocated for the deleted node
}

// Function to display the linked list
void disp(Node* temp){
	while(temp != NULL){
		printf("Id: %d\n", temp->id); // Print the id of each node
		temp = temp->next; // Move to the next node
	}
	printf("------------------------------------------\n"); // Separator
}

