#define LETTERS 26

typedef enum {FALSE=0, TRUE=1} boolean;

typedef struct Node
{
    char letter;    
    boolean isWord;
    unsigned int freq;//frequncy of word
    struct Node* options[LETTERS];
} Node;

boolean insert(Node** root,char* word);//insert a word

int search(Node* root,char* word);//looks for given word and and returns number of occurrences 

void del(Node** root);//realses all used memory of given TRIE