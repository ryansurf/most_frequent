// HW1 for CSE 101
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "header.h"

/* "argc" refers to the number of args passed, and argv[] is a ptr
array which pts to each arg passed to the program. Used for txt input and outputs */ 
int main(int argc, char *argv[]){
    // checks for right amount of args passed in cmd line 
    if(argc == 3){
        ;
    }else{
        printf("Incorrect Input\n");
        exit(1);
    }

    // first step: loop through every line in txt file in main 
    /* FILE is data type. read_file is a pointer to a memory address that contains our text. 
    We open the txt file in read mode */
    FILE *read_file = fopen(argv[1], "r");
    FILE *output_file = fopen(argv[2], "w");
    // check for error when opeing the file 
    if (read_file == NULL){
        printf("Unable to open the file\n");
        // exit(1) indicates the program terminated execution with an error 
        exit(1);
    }
    // create our array of pointers linked lists, 100 possible word lengths
    Node *pointer_array[100];
    // initializing every index to point to NULL in array 
    int i;
    for(i = 0; i < 100; i++){
        pointer_array[i] = NULL;
    }


    // each line of txt file will be stored in line 
    char line[100];
    int count = 0;
    // loops through every line in txt file 
    while(fgets(line, sizeof(line), read_file)){
        // ADD OTHER FUNCTION IN HERE??
        // HERE IS WHERE WE LOOK AT EACH LINE IN TEXT FILE
        // word size gets the length of the word so we can index out array of pts 
        int word_size = strlen(line) - 1;
        search_word(pointer_array, word_size, line);
        count += 1;

        // this add whatever is in "line" to the output file 
    }


    return 0;
}


