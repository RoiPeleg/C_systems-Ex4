#include "TRIE.h"
#include <stdio.h>
#include <stdlib.h>


//assumes a word ends with \0
void unCAP(char* word){
    int i =0;
    while (*word != '\0')
    {
        if(65 <= *word && *word <= 90){
            *word = *word + 32;
        }
        word = (word + i++);
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

boolean insert(Node** root,char* word){
    unCAP(word);
    int ind = 0;
    while (*root && *word != '\0'){
        if((*root) -> options[*(word)-97] == NULL){
            (*root) -> options[*(word)-97] = getNewTRIE(*(word));
            *root = ((*root) -> options[*(word)-97]);
        }
        else{
            *root = ((*root) -> options[*(word)-97]);
        }
        word += ind++;
    }
    if((*root)->isWord){
        (*root) -> freq++;
    }
    else{
        (*root) -> isWord = TRUE;
        (*root) -> freq = 1;
    }
    return TRUE;
}

int search(Node* root,char* word){
    return -1;
}

void del(Node** root){
    if(*root == NULL){
        return;
    }
    for(size_t i = 0; i < LETTERS; i++){
        del(&(*root) -> options[i]);
    }
    free(*root);
}

int main(){
    //Node* root = getNewTRIE('0');
    //char c;
    char *word = 0;
    scanf("%s",word);
    printf("%s",word);
    while(word != NULL){
        scanf("%s",word);
        printf("%s",word);
        //insert(&(*root),word);
    }
    
    //del(root);
    return 0;
}