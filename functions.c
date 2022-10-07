#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"


/* search for node in LL. If the word not in, add it to LL. If it is found,
increment it's count by 1 */
void search_word(Node **pointer_array, int index, char *word){
    // should take the head of the ll 
    Node *current = pointer_array[index];
    if(current == NULL){
        current = (Node*) malloc(sizeof(Node));
        current->node_word = word;
        current->counter = 1;
        current->next = NULL;
        pointer_array[index] = current;
        return;
    }else{
        // loop through linked list and look for word 
        while(current != NULL){
            // compare checks if the strings are equal(return 0) 
            printf("CURRENT NODE WORD: %s\n", current->node_word);
            printf("COMPARE WORD: %s\n\n", word);
            int compare = strncmp(current->node_word, word, index);
            if(compare == 0){
                current->counter++; 
                return;
            }else{
                printf("ELSE\n");
                current = current->next;
            }
        }
    }
    // allocate mem for a new node if word does not exist in LL 
    current->next = (Node*) malloc(sizeof(Node));
    current->next->counter = 0;
    current->next->node_word = word;
    current->next->next = NULL;
    
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


