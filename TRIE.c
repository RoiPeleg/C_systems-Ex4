#include "TRIE.h"
#include <stdio.h>
#include <stdlib.h>


//assumes a word ends with \0
//make all capital letters small and clears spaces and commas
void unCAP(char* word){
    while (*word != '\0')
    {   
        if('A' <= *word && *word <= 'Z'){
            *word = *word + 'A';
        }
        if(*word == ' ' || *word == ',' || *word == '.')
        {
            *word = 0;
        }
        word = (word + 1);
    }
}


//creates a new TRIE node and retruns a pointer to it to create root c = 0 (0 indicates root).
Node* getNewTRIE(char c){
    Node* root = (Node *)malloc(sizeof(Node));
    if(root==NULL)exit(1);
    root -> isWord = FALSE;
    root -> freq = -1;
    root -> letter = c;
    for(size_t i = 0; i < LETTERS; i++)root -> options[i] = NULL;
    return root;    
}

void insert(Node* root,char* word){
    unCAP(word);
    printf(" %s\n",word);
    int ind = 0;
    while (root && *word != '\0'){
        if((root) -> options[*(word)-'a'] == NULL){
            (root) -> options[*(word)-'a'] = getNewTRIE(*(word));
            root = ((root) -> options[*(word)-'a']);
        }
        else{
            root = ((root) -> options[*(word)-'a']);
        }
        word += ind++;
    }
    if((root)->isWord){
        (root) -> freq++;
    }
    else{
        (root) -> isWord = TRUE;
        (root) -> freq = 1;
    }
}

int search(Node* root,char* word){
    return -1;
}

void del(Node* root){
    if(root == NULL){
        return;
    }
    for(size_t i = 0; i < LETTERS; i++){
        del((root) -> options[i]);
    }
    free(root);
}

void printNode(Node* n){
    if(n == NULL)return;
    printf("%c\n",n->letter);
    for(size_t i = 0; i < LETTERS; i++){
        printf(" %c",n ->options[i] ->letter);
    }
    printf("\n");
}
void print(Node* root){
    if(root == NULL){
        return;
    }
    //printNode(root);
    if(root->letter=='0'){
    printf("%c\n",root->letter);
    }
    for(size_t i = 0; i < LETTERS; i++){
        printf(" %c",root ->letter);
       // printNode((root) -> options[i]);
        print((root) -> options[i]);
    }
    printf("\n");
}
int main(int n, char* args[]){
    Node* root = getNewTRIE('0');
    char word[50];
    while(fscanf(stdin," %49s",word) == 1){
        insert(root,word);
    }
    print(root);
    fclose(stdin);
    del(root);
    return 0;
}