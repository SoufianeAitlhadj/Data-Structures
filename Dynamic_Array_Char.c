#include <stdio.h>
#include <stdlib.h>

/*
IMPORTANT NOTE:
In all the implementations of the three data structures, list, stack and the queue the functions 
that add elements check if the data structure is full, and if so,doubles the capacity of the 
data structure using the realloc() function to allocate a new, larger array for the data structures'
items. This allows it to dynamically resize itself as needed to accommodate new items.

Note that in practice, it may be more efficient to grow the data structure by a smaller factor 
(e.g., 1.5x or 1.25x) rather than doubling its size each time, to avoid wasting memory.

So, in my implmentations I will multiply the capacities of the data structures in by this 
Magic Number called MagicFactor =  1.5
*/

#define MagicFactor  1.5


typedef struct {
    char *data;
    size_t size;
    size_t capacity;
} List;


// this function is to initiate the "list"
void init_list(List *list) {
    list->data = malloc(sizeof(char));
    if (list->data == NULL) {
        printf("Error: Could not allocate memory\n");
        exit(1);
    }
    list->size = 0;
    list->capacity = 1;
}


// Our main append() function to add element in the "list"
void append(List *list, char value) {
    if (list->size == list->capacity) {
        list->capacity *= MagicFactor;
        char *temp = realloc(list->data, list->capacity * sizeof(int));
        if (temp == NULL) {
            printf("Error: Could not allocate memory\n");
            exit(1);
        }
        list->data = temp;
    }
    list->data[list->size] = value;
    list->size++;
}


// Our pop() function to remove elements from the last position
int pop(List* list) {
    if (list->size == 0) {
        return -1;
    } else {
        char last_element = list->data[list->size - 1];
        list->size--;
        return last_element;
    }
}


// This is extra function to print the so called "list" (i.e, our dynamic array) in a formatted way

void print_list(List *list) {
    printf("[");
    for (size_t i = 0; i < list->size; i++) {
        printf("%d", list->data[i]);
        if (i != list->size - 1) {
            printf(", ");
        }
    }
    printf("]\n");
}


