#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ll long long int
struct Node{
    int val;
    Node *next;
};

void pushTail(Node** head_ref, int new_data){  
    /* 1. allocate node */
    //Node* new_node = new Node();
    Node* new_node = (Node *)malloc(sizeof(Node));  
    Node *last = *head_ref; /* used in step 5*/
    /* 2. put in the data */
    new_node->val = new_data;  
    /* 3. This new node is going to be  
    the last node, so make next of  
    it as NULL*/
    new_node->next = NULL;  
    /* 4. If the Linked List is empty, 
    then make the new node as head */
    if (*head_ref == NULL)  {  
        *head_ref = new_node;  
        return;  
    }  
    /* 5. Else traverse till the last node */
    while (last->next != NULL){
        last = last->next;  
    }  
    /* 6. Change the next of last node */
    last->next = new_node;  
    return;  
}
void printAll(struct Node *node){
    printf("Output: ");
    while(node != NULL){//while there's still some node
        printf("%d ",node->val);
        node = node->next;  
    } printf("\n");
}
Node *mergeNode(Node *l1,Node *l2){
    Node *tail = NULL;
    while (l1 != NULL && l2 != NULL){
        //merge
        if (l1->val < l2->val){
            pushTail(&tail,l1->val);
            l1=l1->next;
        }
        else {
            pushTail(&tail,l2->val);
            l2=l2->next;
        }
    }
    //masukin sisanya
    while(l1!=NULL){
        if (l1!=NULL){
            pushTail(&tail,l1->val);
            l1=l1->next;
        }
    }
    while(l2!=NULL){
        if (l2!=NULL){
            pushTail(&tail,l2->val);
            l2=l2->next;
        }
    }
    return tail;
}
int main(){
    Node *l1 = NULL;
    Node *l2 = NULL;
    int x=1,y=2;
    for(int i=0;i<5;i++){
        pushTail(&l1,x);
        x+=2;
        pushTail(&l2,y);
        y+=2;
    }
    Node *output = mergeNode(l1,l2);
    printAll(output);
    return 0;
}