/* This is my implementation of std::vector from C++
 * a dynamicly resizing array that grows with the data its provided
 * Author: Achraf Khadraoui
 */


#include <stdio.h>
#include <stdlib.h>

#define INITIAL_CAPACITY 4

typedef struct { 
	int *data;
	size_t size;
	size_t capacity;
} vector;

void vector_init(vector *v) {
	v->size = 0;
	v->capacity = INITIAL_CAPACITY;
	v->data = malloc(sizeof(int) * v->capacity);
	if (v->data == NULL) {
		perror("Error: Could not allocate memory for the vector.\n");
		exit(EXIT_FAILURE);
	}
}

int vector_capacity_check(vector *v) {
	if (v->size < v->capacity) {
		return 0;
	}

	size_t new_cap = v->capacity * 2;

	int *new_array = realloc(v->data, new_cap * sizeof(int));
	if (!new_array) {
		perror("Error: Could not reallocate memory for the vector.\n");
		return -1;
	}
	
	v->data = new_array;
	v->capacity = new_cap;
	return 0;
}

void list_vector(vector *v) {
	if (!v->size) {
		printf("Info: The vector is empty.\n");
		return;
	}

	for (int i = 0; i < (int) v->size; ++i) {
		printf("vector size: %ld\n", v->size);
		printf("%d\n", v->data[i]);
	}
}

void vector_push(vector *v) {
	int value;

	printf("Enter value you want pushed to vector: ");
	if (scanf("%d", &value) != 1) {
		printf("Error: Invalid inpout. Please enter a valid integer value.\n");
		return;
	}

	if (vector_capacity_check(v)) {
		perror("Error: Could not augment the vector size.\n");
		return;
	}
	
	v->data[v->size] = value;
	v->size += 1;

	printf("Success: Value was pushed to the vector.\n");
}

void vector_pop(vector *v) {
	if (v->size == 0) {
		printf("Info: Vector is empty, can not delete anything.\n");
		return;
	}

	v->size -= 1;
	printf("Success: Last value of the vector has been popped.\n");
}

void vector_find(vector *v) {
	size_t index;

	printf("Enter the index you want the value of: ");
	if (scanf("%ld", &index) != 1) {
		printf("Error: Invalid inpout. Please enter a valid index.\n");
		return;
	}
	if (index > v->size) {
		printf("Error: Index outside of vector range.\n");	
		return;
	}
	printf("Index found: %d\n", v->data[index]);
}

void vector_set(vector *v) {
	size_t index;
	int value;
	// input checking 
	printf("Enter the index you want to set the value of: ");
	if (scanf("%ld", &index) != 1) {
		printf("Error: Invalid inpout. Please enter a valid index.\n");
		return;
	}

	printf("Enter the value you want: ");
	if (scanf("%d", &value) != 1) {
		printf("Error: Invalid inpout. Please enter a valid value.\n");
		return;
	}

	if (index > v->size) {
		printf("Error: Index outside of vector range.\n");
		return;
	}

	// set the value of the index
	v->data[index] = value;
	printf("Succes: Value set.\n");
}

void vector_delete(vector *v) {
	size_t index;

	printf("Enter the index you want to be deleted: ");
	if (scanf("%ld", &index) != 1) {
		printf("Error: Invalid inpout. Please enter a valid index.\n");
		return;
	}
	if (index > v->size) {
		printf("Error: Index outside of vector range.\n");
		return;
	}
	

	if (index == v->size) {
		v->size -= 1;
		return;
	} else {
		// reorginaze the array after delete
		for (int i = index; i < (int) v->size ; ++i) {
			v->data[i] = v->data[i + 1];
		}
	}
	v->size -= 1;


	printf("Success: Deleted the specified index.\n");
}

void vector_free(vector *v) {
	free(v->data);
	v->data = NULL;
	v->capacity = 0;
	v->size = 0;
}


int main(void) {
	vector v;
	vector_init(&v);
	
	int choice;


	do {
		printf("\n--- std vector in C ---\n");
		printf("Current Vector Size: %ld\n", v.size);
		printf("1- List the values inside the vector.\n");
		printf("2- Push value to the vector.\n");
		printf("3- Pop value from the vector.\n");
		printf("4- Delete value from the vector.\n"); printf("5- Find value in the vector.\n");
		printf("6- Exit application.\n");

		if (scanf("%d", &choice) != 1) {
			printf("Error: Invalid inpout. Please enter a valid choice.\n");
			continue;
		}
	
		switch (choice) {
			case 1:
				list_vector(&v);
				break;
			case 2:
				vector_push(&v);
				break;
			case 3:
				vector_pop(&v);
				break;
			case 4:
				vector_delete(&v);
				break;
			case 5:
				vector_find(&v);
				break;
			case 6:
				printf("Exiting application. Have a nice day.\n");
				break;
			default:
				printf("Error: Unkown command. Please enter a valid choice.\n");
				break;
		}
	} while(choice != 6);

	vector_free(&v);

	return 0;
}
