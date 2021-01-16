#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


typedef  struct tree {
   int data;
  struct  tree * left;
  struct tree * right;
}Tree;

void insert (Tree ** head_refernce,int key){

    if(*head_refernce==0){
        *head_refernce =  (Tree*)malloc(sizeof(Tree));
        (*head_refernce)->data=key;
        (*head_refernce)->left =0;
        (*head_refernce)->right =0;
    }
    else if ( key < (*head_refernce)->data){
        insert(&(*head_refernce)->left,key);
    }
    else if ( key > (*head_refernce)->data){
        insert(&(*head_refernce)->right,key);
    }
}

Tree* Search(Tree * head_refernce,int key){


    if(head_refernce == 0)
        return NULL;
    if(head_refernce->data == key)
        return head_refernce;

    if (key < head_refernce ->data)
       return Search(head_refernce->left , key);

    if (key > head_refernce ->data)
       return Search(head_refernce->right , key);

}

void print (Tree * head_refernce){

    printf("\n");
    if(head_refernce == 0)
        printf("There is not tree...\n");

    else {
        printf("There is a tree with value: %d\n",(head_refernce)->data);
        print((head_refernce)->left);
        print((head_refernce)->right);
    }
}
int main() {
    printf("Hello, World!\n");

    Tree * test;
    test =0;

    insert(&test,1);
    insert(&test,2);
    insert(&test,3);
    insert(&test,4);
    insert(&test,5);

    print(test);

    Tree* result = Search(test,7);

    if(result!=NULL)
    printf("Is there a node with this data %d " , result->data);
    else
        printf("There is no node with this value.");
    return 0;
}
