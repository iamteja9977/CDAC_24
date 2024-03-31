#include<stdio.h>

struct Employee{
	int id;	
	char name[25];
	double salary;
};

int main(){
	struct Employee var = {1001, "Teja", 1098723.34};
	
	struct Employee *ptr = &var;
	
	printf("ID: %d\tName: %s\tSal:%.2lf\n", var.id, var.name, var.salary);

	// using struct pointer to print variables:
	printf("ID: %d\tName: %s\tSal:%.2lf\n", (*ptr).id, (*ptr).name, (*ptr).salary);
    
	// using arrow operator to print variables from a struct pointer
	printf("ID: %d\tName: %s\tSal:%.2lf\n", ptr->id, ptr->name, ptr->salary);

}
