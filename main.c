#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"


int main(int argc, char *argv[]){

    // not valid cmd line args 
    if(argc !=  3){
        printf("Invalid Input\n");
        exit(1);
    }

    //opens the txt file for reading
    FILE *read_text = fopen(argv[1], "r");
    //opens txt file for writing
    FILE *write_text = fopen(argv[2], "w");
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
                temp = temp->next;
            }
            int x = get_length(ptr_array, i);
            bubble_word(ptr_array, i);
            //print ll to make sure i swapped right
            char *output;
            output = *find_rank_lenght(ptr_array, length, rank);
        }
    }
  

    return 0;
}