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

// swap which will be used in bubble sort function 
void swap(Node *node1, Node *node2){
    int temp_count = node1->count;
    char *temp_word = node1->node_word;
    node1->count = node2->count;
    node1->node_word = node2->node_word;
    node2->count = temp_count;
    node2->node_word = temp_word;
}

void bubble_word(Node **ptr_array, int index){
    // check if array is null 
    if(ptr_array == NULL){
        return;
    }
    // keep track of amount of swaps 
    int swaps = 0;
    int length = get_length(ptr_array, index);
    for(int i = 0; i < length; i++){
        Node *current = ptr_array[index];
        //Sort by occurence
        while(current->next != NULL){
            // for lexograpgic
            if(current->count < current->next->count){
                swap(current, current->next);
                swaps++;
            }
            current = current->next;
        }
        // sort by lexograpgic of same occurence 
    }
    for(int i = 0; i < length; i++){
        Node *current = ptr_array[index];
        while(current->next != NULL){
            if(strcmp(current->node_word, current->next->node_word) > 0 && current->count == current->next->count){
                swap(current, current->next);
             }
             current = current->next;
        }
    }
    
}

// gets length of linked list 
int get_length(Node **ptr_array, int index){
    int length = 0;
    Node *temp = ptr_array[index];
    while(temp != NULL){
        length++;
        temp = temp->next;
    }
    return length;
}

// walks through linked list to find rank
char *find_rank_length(Node **ptr_array, int length, int rank){
    int count = 0;
    Node *temp = ptr_array[length];

    while(temp != NULL){
        if(count == rank){
            char *ret = strdup(temp->node_word);
            return ret;
        }
        count++;
        temp = temp->next;
    }
    char *ret = "-";
    return ret;
}
