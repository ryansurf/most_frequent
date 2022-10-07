#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"


/* search for node in LL. If the word not in, add it to LL using add_node(). If it is found,
increment it's count by 1 */
void search_word(Node **pointer_array, int index, char *word){
    // should take the head of the ll 
    Node *current = pointer_array[index];
        // loop through linked list and look for word 
    if(current == NULL){
        current = malloc(sizeof(Node));
        current->node_word = word;
        current->counter = 1;
        current->next = NULL;
        pointer_array[index] = current;
        return;
    }else{
        //If CURRENT is not NULL, we walk through linked list until we find a matching word.
        // If we dont, we add new node 
        while(current != NULL){
            // compare checks if the strings are equal(return 0) 
            int compare = strncmp(current->node_word, word, index);
            if(compare == 0){
                current->counter++; 
                break;
            }else{
                current = current->next;
            }
        }
        //If we got to this point, it means the word is not in the LL. We must add it
        //add_node(pointer_array, index, word);
        }
}



// Adds a node to a LL at the specified index of the array at the beginning of LL
void add_node(Node **pointer_array, int index, char *word){
    //Now we add the new variable
    Node *currentNode = malloc(sizeof(Node));
    currentNode->counter = 1;
    currentNode->node_word = word;
    currentNode->next = pointer_array[index];
    pointer_array[index] = currentNode;
}



// prints all our linked lists in the array 
void print_lists(Node **pointer_array){
    for(int i = 0; i < 100; i++){
        if(pointer_array[i] == NULL){
            continue;
        }else{
            Node* current = pointer_array[i];
            while(current->next != NULL){
                current = current->next;
            }
    }
}
}


