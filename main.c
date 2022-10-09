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
    FILE *read_text = fopen("shakespeare-cleaned5.txt", "r");
    FILE *read_input = fopen(argv[1], "r");
    FILE *out_file = fopen(argv[2], "w");
    //opens txt file for writing
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
   
    // bubble word every ll of array 
    for(int i = 0; i < 100; i++){
        bubble_word(ptr_array, i);
        if(i == 6){
            Node *temp = ptr_array[i];
            while(temp != NULL){
                printf("%s->", temp->node_word);
                temp = temp->next;
            }
        }
    }


    // read from input file, assign LENGTH and RANK
    char line[50];
    while(fgets(line, sizeof(line), read_input) != NULL){
        char *temp_line = strdup(line);
        //get LENGTH and INPUT
        char *token = strtok(temp_line, " ");
        char *length;
        char *rank;
        int count = 0;

        while(token != NULL){
            if(count == 0){
                length = token;
            }else{
                rank = token;
            }
            token = strtok(NULL, " ");
            count++;
        }

        char *remaining1;
        long length_int;
        length_int = strtol(length, &remaining1, 10);

        char *remaining2;
        long rank_int;
        rank_int = strtol(rank, &remaining2, 10);

        // NOW we have length and rank
         char *output = find_rank_length(ptr_array, length_int, rank_int - 1);
         fprintf(out_file, "%s\n", output);

    }


  

    return 0;
}