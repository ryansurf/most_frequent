

typedef struct Node{
    char *node_word;
    int count;
    struct Node *next;
} Node;

void check_word(Node **ptr_array, char *word);

void add_node(Node **ptr_array, char *word);

void swap(Node *node1, Node *node2);

int get_length(Node **ptr_array, int index);

void bubble_word(Node **ptr_array, int index);

char *find_rank_lenght(Node **ptr_array, int length, int rank);