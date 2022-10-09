#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"

void check_word(Node **ptr_array, char *word){
    // REMEMBER TO MALLOC 
    int index = strlen(word) - 1;
    // if word of length "index" has no LL yet, declare its head 
    if(ptr_array[index] == NULL){
        Node *head = malloc(sizeof(Node));
        head->count = 1;
        head->node_word = word;
        head->next = NULL;
        ptr_array[index] = head;
    }
    else{
        // check if word is already in Linked list, and increment count if it is 
        Node *current = ptr_array[index];
        while(current != NULL){
            if(strncmp(current->node_word, word, index) == 0){
                current->count++;
                return;
            }
            current = current->next;
        }
        // call function to add new node because word not in linked list
        add_node(ptr_array, word);
    }

}

void add_node(Node **ptr_array, char *word){
    int index = strlen(word) - 1;

    //Initialize the new node
    Node *new_node = malloc(sizeof(Node));
    new_node->count = 1;
    new_node->node_word = word;
    new_node->next = ptr_array[index];
    // insert at beginning of linked list 
    ptr_array[index] = new_node;
    
}