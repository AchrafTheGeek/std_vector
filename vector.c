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

void vector_push(vector *v) {
	
}


int main(void) {

	return 0;
}
