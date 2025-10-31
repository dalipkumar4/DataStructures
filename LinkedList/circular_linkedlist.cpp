#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node * next;
}Node;

Node* pushFront(Node *head,int val){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = val;
    
    if(head == NULL){
        newNode->next = newNode;
        return newNode;
    }

    Node *temp = head;
    while(temp->next != head)
    {
        temp = temp->next;
    }
    
    newNode->next = head;
    temp->next = newNode;

    return newNode;
}
Node* pushBack(Node *head,int val){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = val;
    
    if(head == NULL){
        newNode->next = newNode;
        return newNode;
    }
    
    Node *temp = head;
    while (temp->next != head)
    {
        temp = temp->next;
    }
    
    temp->next = newNode;
    newNode->next = head;
    
    return head;
}

void printList(Node *head){

    if(head == NULL){
        printf("List is empty");
        return;
    }
    Node *temp = head;
    while (temp->next!= head)
    {
        printf("%d -> ",temp->data);
        temp = temp->next;
    }
    printf("(Back to head)\n");
    
}

int main(){
    Node *head = NULL; // start with empty list

    head = pushFront(head,10);
    head = pushFront(head,23);
    head = pushFront(head,43);
    head = pushBack(head ,334);
    printList(head);
    

    return 0;
}
