#include<stdio.h>

struct Employee{
	int id;
	// make sure your char array is big enough
	// if its exactly same size as name
	// there will be no null terminator
	// and it will print garbage value
	// till it finds a null character.
	char name[25];
	double salary;
};

int main(){
	struct Employee var = {1001, "Teja", 1098723.34};
	printf("ID: %d\tName: %s\tSal:%.2lf\n", var.id, var.name, var.salary);
}
