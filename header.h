

typedef struct Node{
    char *node_word;
    int count;
    struct Node *next;
} Node;

void check_word(Node **ptr_array, char *word);

void add_node(Node **ptr_array, char *word);