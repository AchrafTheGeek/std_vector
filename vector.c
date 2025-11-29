#include <stdio.h>

#define INITIAL_CAPACITY 4

typedef struct { 
	int *data;
	size_t size;
	size_t capacity;
} vector;

void vector_init(vector *v) {
	v->size = 0;
	v->capacity = INITIAL_CAPACITY;
	v->data = malloc(sizeof(vector) * INITIAL_CAPACITY);
	if (v->data == NULL) {
		perror("Error: Could not allocate memory for the vector.\n");
		return;
	}
}

int vector_capacity_check(vector *v) {
	if (v->size < v->capacity) {
		return 0;
	}

	size_t new_cap = v->capacity * 2;

	int *temp_data = realloc(v->data, v->capacity * sizeof(int));
	if (!temp_data) {
		perror("Error: Could not reallocate memory for the vector.\n");
		return -1;
	}

	v->data = temp_data;
	v->capacity = temp_cap;
	return 0;
}

void list_vector(vector *v) {
	if (!v->size) {
		printf("Info: The vector is empty.\n");
		return;
	}

	for (int i = 0; i < v->size; ++i) {
		printf("%d\n", v->data[i]);
	}
}

void vector_push(vector *v, int value) {
	if (vector_capacity_check(v)) {
		perror("Error: Could not push the value to the vector");
		return;
	}
	
	v->data[size] = value;
}


int main(void) {
	vector *v;
	vector_init(v);
	
	int choice;


	do {
		printf("\n--- std vector in C ---\n");
		printf("1- List the values inside the vector.\n");

		if (scanf("%d", &choice) != 1) {
			printf("Error: Invalid inpout. Please enter a valid choice.\n");
			continue;
		}
	
		switch (choice) {
			case 1:
				list_vector(v);
				break;
			case 2:
				vector_push(v);
			case 3:
			case 4:
			case 5:
			case 6:
				printf("Exiting application. Have a nice day.\n");
				exit(0);
			default:
				printf("Error: Unkown command. Please enter a valid choice.\n");
				break;
		}
	} while(choice != 6);


	return 0;
}
