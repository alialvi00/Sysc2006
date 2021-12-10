/* SYSC 2006 Lab 11
 *
 * Student Name: Ali Alvi
 * Student Number: 101114940
 */

#include <assert.h>             // assert
#include <stdlib.h>             // malloc, free
#include <stdbool.h>
#include <stdio.h>              // printf

#include "sl_list.h"

/*************************************************************
 * Functions presented in lectures.
 *************************************************************/

/* Return a pointer to a new intnode_t (a node in a singly-linked list).

   Parameter value: the integer to be stored in the node.
   Parameter next: a pointer to the node that the new node should point to.
   This pointer should be NULL if the new node is the last node in the 
   linked list.
   Terminate (via assert) if memory for the node cannot be allocated.
 */
intnode_t *intnode_construct(int value, intnode_t *next)
{
    intnode_t *p = malloc(sizeof(intnode_t));
    assert(p != NULL);
    p->value = value;
    p->next = next;
    return p;
}
/* Parameter head points to the first node in a linked list, or is NULL
   if the linked list is empty. Insert a node containing the specified 
   integer value at the front of the linked list, and return a pointer to 
   the first node in the modified list.
 */
intnode_t *push(intnode_t *head, int value)
{
    return intnode_construct(value, head);
}

/* Parameter head points to the first node in the list.
   Return the length of a linked list (0 if the linked list is empty). 
 */
int length(intnode_t *head)
{
    int count = 0;
    for (intnode_t * current = head; current != NULL; current = current->next) {
        count += 1;
    }
    return count;
}

/* Parameter head points to the first node in a linked list.
   Print the linked list, using the format:
       value1 -> value2 -> value3 -> ... -> last_value
 */
void print_list(intnode_t *head)
{
    if (head == NULL) {
        printf("empty list");
        return;
    }

    intnode_t *current;

    /* Print every node in the linked list except the last one.

       Notice that the loop condition is:
       current->next != NULL
       and not:
       current != NULL

       During the last iteration, the value in the second-last node is
       printed, then current is updated to point to the last node. The
       condition current->next != NULL now evaluates to false, so the 
       loop exits, with current pointing to the last node (which has  
       not yet been printed.) 
     */
    for (current = head; current->next != NULL; current = current->next) {
        printf("%d -> ", current->value);
    }

    /* Print the last node. */
    printf("%d", current->value);
}


/*****************************************************************
 * Solutions to Lab 11
 *****************************************************************/

// Exercise 1

intnode_t *add(intnode_t *head, int elem, int index)
{
    int currentIndex = 0; //index for traversing through linked list
    
    if(length(head) == 0){ //if list is empty
        assert(index >= 0 && index <= length(head)); //make sure index is valid
        if(index == 0){ //if index is 0
            return push(head, elem); //add to the front of the linked list
        }
    }
    else{ //if list is not empty
        assert(index >= 0 && index <= length(head)); //make sure index is valid
        
        if(index == 0){ //if index is 0 add to the front of the list
            head = push(head, elem);
        }
        else if(index == length(head)){ // if index is the position of last node
            intnode_t *newNode = malloc(sizeof(intnode_t)); //make a new node
            assert(newNode != NULL);
            intnode_t *currentNode = head; //make a current node that points to head
            newNode->value = elem; //set the new node's value
            newNode->next = NULL; //set the new nodes next position as NULL by default
            
            while(currentNode->next != NULL){ //traverse till the end of the list
                currentNode = currentNode->next;
            }
            currentNode->next = newNode; //set currentnode's next node as new node
        }
        else if(index >= 0 && index <= length(head)){ //if index is not last position and is within the list
            intnode_t *currentNode = head; //create a currentNode that points to head
            
            while (currentIndex != index-1) { //traverse through the list until you reach the node that comes before index
                currentNode = currentNode->next;
                currentIndex++;
            }
            intnode_t *newNode = malloc(sizeof(intnode_t)); //create a new node
            assert(newNode != NULL);
            newNode->value = elem;
            newNode->next = NULL;
            
            newNode->next = currentNode->next; //set the next node of new node the same as next node of the previous node
            currentNode->next = newNode; //set the next node of the previous node as the new node
        }
    }
    return head; //return the head of the list
}

// Exercise 2

void every_other(intnode_t *head)
{
    if(head == NULL || length(head) == 1) //if list is empty
        return;
    
    intnode_t *otherNode = head; //create a pointer node to the first node
    intnode_t *evenNode = head->next; //create a pointer node to the second node which is also the node we have to remove
    
    while(otherNode != NULL && evenNode != NULL){ //while other and even node dont become NULL aka point to the last node
        otherNode->next = evenNode->next; //other node's next node should point to the even node's next node
        free(evenNode); //delete the even node
        otherNode = evenNode->next; //set the other node now as even node's next one
        
        if(otherNode != NULL) //if other node is not null aka didnt finish iterating the list
            evenNode = otherNode->next; //set the next node of other's as even node
        //if the next node of other node is null, while loop will exit and the job is done
    }
}
