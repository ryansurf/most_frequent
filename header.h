// linked list Node definition 
typedef struct node{
    // the word 
    char *node_word;
    // word count 
    int counter;
    // next node 
    struct node *next;
} Node;

void search_word(Node **pointer_array, int index, char *word);

void print_lists(Node **pointer_array);

void add_node(Node **pointer_array, int index, char *word);