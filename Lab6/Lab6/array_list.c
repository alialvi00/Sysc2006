/* SYSC 2006 Lab 6
 *
 * array_list.c
 *
 * Student Name: Ali Alvi
 * Student Number: 101114940
 *
 * Prototype of a dynamically allocated, fixed-capacity list that supports a 
 * subset of the operations provided by Python's list class.
 */ 

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "array_list.h"

/* Construct a new, empty list, and return a pointer to it
 * Parameter capacity is the # of elements that can be stored in the list.
 * Terminate the program via assert if capacity is <= 0.
 * Terminate the program via assert if memory for the list cannot be 
 * allocated from the heap.
 */
intlist_t *intlist_construct(int capacity)
{
    // Note - this is an incomplete function definition.
    // You must modify the function so that it correctly implements all 
    // of the requirements listed in the header comment. 

    assert(capacity > 0); //Make sure capacity is not <= 0
    
    intlist_t *list = malloc(sizeof(intlist_t));
    
    assert(list != NULL); //Make sure array was successfully allocated in the heap

    list->capacity = capacity;
    list->size = 0; //ArrayList is empty by default
    list->elems = malloc(capacity*sizeof(int));; //elems are stored in the array allocated
    return list; //return the arrayList
}

/* Destroy the list pointed to by parameter list, deallocating all memory 
 * that was allocated from the heap.
 * Terminate the program via assert if list is NULL.
 */
void intlist_destroy(intlist_t *list)
{
    assert(list != NULL);
    free(list->elems);  /* Return the array to the heap. */
    free(list);         /* Return the structure to the heap. */
}

/* Print the list pointed to by parameter list to the console.
 * Terminate the program via assert if list is NULL.
 */
void intlist_print(const intlist_t *list)
{
    assert(list != NULL);
    
    if(list->size==0){ //if list is empty
        printf("[]");
    }
    else{
        printf("["); //print first bracket
        for(int i=0; i<list->size-1;i++){
            printf("%d ",list->elems[i]); //print all elements except last
        }
        printf("%d]",list->elems[list->size-1]); //print last element with close bracket
    }
}

/* Insert element at the end of the list pointed to by list.
 * Return true if element is appended; otherwise return false
 * (which indicates that the list is full.)
 * Terminate the program via assert if list is NULL.
 */
_Bool intlist_append(intlist_t *list, int element)
{
    assert(list != NULL);
    
    if(list->size==list->capacity){ //if list is full
        return false;
    }
    else{
        list->elems[list->size] = element; //add element to the end of the list
        list->size += 1; //increase the size
        return true;
    }
}

/* Return the maximum number of integers that can be stored in the list 
 * pointed to by parameter list.
 * Terminate the program via assert if list is NULL.
 */
int intlist_capacity(const intlist_t *list)
{
    assert(list != NULL);
    
    return list->capacity; //return list capacity
}

/* Return the number of integers in the list pointed to by parameter list.
 * Terminate the program via assert if list is NULL.
 */
int intlist_size(const intlist_t *list)
{
    assert(list != NULL);
    
    return list->size; //return list size
}

/* Return the element located at the specified index, in the list
 * pointed to by parameter list. 
 * Terminate the program via assert if list is NULL, 
 * or if index is not in the range 0 .. intlist_size() - 1.
 */
int intlist_get(const intlist_t *list, int index)
{
    assert(list != NULL);
    assert(index >= 0 && index <= list->size-1); //make sure index is within range
    
    return list->elems[index];
}

/* Store element at the specified index, in the list pointed to by 
 * parameter list. Return the integer that was previously 
 * stored at that index.
 * Terminate the program via assert if list is NULL, 
 * or if index is not in the range 0 .. intlist_size() - 1.
 */
int intlist_set(intlist_t *list, int index, int element)
{
    assert(list != NULL);
    assert(index >= 0 && index <= list->size-1); //make sure index is within range
    
    int prevElement = intlist_get(list, index); //uses get method to get the previous element stored at this index, nothing specified so I decided to use the method
    list->elems[index] = element; //set new element at the location
    return prevElement; //return previous element
}

/* Empty the list pointed to by parameter list.
 * Memory allocated to the list is not freed, so the emptied list can 
 * continue to be used.
 * Terminate the program via assert if list is NULL.
 */
void intlist_removeall(intlist_t *list)
{
    assert(list != NULL);
    
    for(int i=0; i<list->size;i++){
        list->elems[i] = 0;
    }
    list->size=0;
}
