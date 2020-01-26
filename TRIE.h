#define LETTERS 26

typedef enum {FALSE=0, TRUE=1} boolean;

typedef struct Node
{  
    boolean isWord;
    unsigned int freq;//frequncy of word
    struct Node* options[LETTERS];
} Node;

void insert(Node* root,char* word);//insert a word

void searchT(Node* root,boolean reserve,char word[],int count);//prints all words and freq

void del(Node* root);//realses all used memory of given TRIE