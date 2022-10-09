#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"


int main(){


    //opens the txt file for reading
    FILE *read_text = fopen("test.txt", "r");
    if(read_text == NULL){
        printf("Cannot open file!\n");
        exit(1);
    }

    // declare our array of pointers 
    Node *ptr_array[100];
    for(int i = 0; i < 100; i++){
        ptr_array[i] = NULL;
    }

    // stores the current line of file 
    char word[100];


    // loops through every word in txt file 
    while(fgets(word, sizeof(word), read_text) != NULL){
        char *temp_word = strdup(word);
        check_word(ptr_array, temp_word);
    }

    for(int i = 0; i < 10; i++){
        if(ptr_array[i] != NULL){
            Node *temp = ptr_array[i];
            while(temp != NULL){
                printf("WORD: %s\n", temp->node_word);
                printf("COUNT: %d\n", temp->count);
                temp = temp->next;
            }
            printf("\n\n\n\n");
        }
    }
  

    return 0;
}