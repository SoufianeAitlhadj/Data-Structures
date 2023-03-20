#include <stdio.h>
#include <stdlib.h>

#define MagicFactor  1.5

// Notice that the stack is nothing but a "List" that removes and adds from the last position
// i.e, Last In First Out (LIFO)


typedef struct {
    int *data;
    size_t size;
    size_t capacity;
} Stack;

// Our main add() function to add element in the "stack"
void add(Stack *stack, int value) {
    if (stack->size == stack->capacity) {
        stack->capacity *= MagicFactor;
        int *temp = realloc(stack->data, stack->capacity * sizeof(int));
        if (temp == NULL) {
            printf("Error: Could not allocate memory\n");
            exit(1);
        }
        stack->data = temp;
    }
    stack->data[stack->size] = value;
    stack->size++;
}


// Our remove() function to remove elements from the last position
int remove(Stack* stack) {
    if (stack->size == 0) {
        return -1;
    } else {
        int last_element = stack->data[stack->size - 1];
        stack->size--;
        return last_element;
    }
}
