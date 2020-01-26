#include "TRIE.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//assumes a word ends with \0
//make all capital letters small and clears spaces and commas
void unCAP(char* word){
    while (*word != '\0')
    {   
        if('A' <= *word && *word <= 'Z'){
            *word = 'a' + *word - 'A';
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
    for(size_t i = 0; i < LETTERS; i++)root -> options[i] = NULL;
    return root;    
}

void insert(Node* root,char* word){
    unCAP(word);
    while (*word != '\0'){
        if((root) -> options[*(word)-'a'] == NULL){
            (root) -> options[*(word)-'a'] = getNewTRIE(*(word));
            root = ((root) -> options[*(word)-'a']);
        }
        else{
            root = ((root) -> options[*(word)-'a']);
        }
        word += 1;
    }
    if((root)->isWord){
        (root) -> freq+=1;
    }
    else{
        (root) -> isWord = TRUE;
        (root) -> freq = 1;
    }
}
void searchT(Node* root,boolean r,char word[],int count){
    if(root == NULL){
        return;
    }
    if(root->isWord){
        for(int i=0;i<count;i++)
        printf("%c",word[i]);
        printf("\t%d\n",root->freq);
    }
    if(!r){
        for(size_t i = 0; i < LETTERS; i++){
            if(root->options[i]!=NULL){
                word[count]= (char)('a'+i);
                searchT(root -> options[i],r,word,count+1);
            }
        }
    }
    else
    {
        for(size_t i = 0; i < LETTERS; i++){
            if(root->options[(LETTERS-(i+1))]!=NULL){
                word[count]= (char)('a'+(LETTERS-(i+1)));
                searchT(root -> options[(LETTERS-(i+1))],r,word,count+1);
            }
        }
    }
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


int main(int n,char* args[]){
    boolean reverse = FALSE;
    if(n==2 && strcmp(args[0],"r")){
        reverse = TRUE;
    }
    Node* root = getNewTRIE('0');
    char word[50] = {'0'};
    while(fscanf(stdin," %49s",word) == 1){
        insert(root,word);
    }
    fclose(stdin);
    *word = '\0';
    searchT(root,reverse,word,0);
    del(root);
    return 0;
}