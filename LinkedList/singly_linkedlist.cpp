#include <stdio.h>
#include <stdlib.h>

// <--- SINGLY LINKEDLIST --->

typedef struct Node{
    int data;
    struct Node *next;
}node;

node *insertionAtFront(node *head,int val){
    // memory allocation to newNode
    node *newNode;
    newNode = (node*)malloc(sizeof(node));
    
    // Check allocation
    if(newNode == NULL){
        printf("Memory Allocation failed!");
        return head;
    }
    newNode->data = val;
    
    // if linked list is empty
    if(head == NULL){
        newNode->next = NULL;
        head = newNode;
    }
    // when linkedlist have multiple nodes
    else{
        newNode->next = head;
        head = newNode; 
    }

    return head;
}

node *insertionAtEnd(node *head,int val){
    // memory allocation to newNode
    node *newNode;
    newNode = (node*)malloc(sizeof(node));

    // Check allocation
    if(newNode == NULL){
        printf("Memory Allocation failed!");
        return head;
    }

    newNode->data = val;
    newNode->next = NULL;

    // if Linkedlist is empty
    if(head == NULL){
        head = newNode;
    }
    else{
        // traverse to last node;
        node *temp = head;
        while (temp->next != NULL){
            temp = temp->next;
        }
        // link last node to newnode;
        temp ->next = newNode;
    }
    // return updated head;
    return head;
}

node *insertAtPosition(node *head,int val,int loc){
    node *newNode;
    newNode = (node*)malloc(sizeof(node));

    // Check allocation
    if(newNode == NULL){
        printf("Memory Allocation failed!");
        return head;
    }
    
    newNode->data = val;
    newNode->next = NULL;
    
    // if Linkedlist is empty
    if(head == NULL){
        if(loc != 1){
            printf("Invalid position! Node not inserted.\n");
            free(newNode);
            return head;
        }
        head = newNode;
        return head;
    }
    

    if(loc == 1){
        newNode->next = head;
        head = newNode;
        return head;
    }
    
    // traverse to (loc-1)th node
    node*temp = head;
    for(int i = 1;i<loc-1 && temp!= NULL;i++){
        temp = temp->next;
    }


    // if location is valid
    if(temp == NULL){
        printf("Invalid location! Node not interested!");
        free(newNode);
        return head;
    }

    // inserting node between temp and temp->next;
    newNode->next= temp->next;
    temp->next = newNode;
    return head;
}

node *deleteAtFront(node *head){
    if(head == NULL){
        printf("LinkedList is empty");
    }
    node *temp = head;

    // only one node exist
    if(head->next == NULL)
    {
        head = NULL;
        free(temp);
        return head;
    }

    // more then one node
    head = head->next; // move head to next node
    free(temp); // free the old first node
    return head;
}

node *deleteAtEnd(node *head){
    if(head == NULL){
        printf("LinkedList is empty");
    }
    node *temp = head;

    // only one node exist
    if(temp->next == NULL)
    {
        head = NULL;
        free(temp);
        return head;
    }

    while(temp->next->next != NULL){ // go to second-last node
        temp = temp->next;
    }

    // temp->next is the last node
    free(temp->next);
    temp->next = NULL; // update second-last node to be last
    return head;
}

node *deleteAtPosition(node *head,int loc){

    if(head == NULL){
        printf("List is empty");
        return NULL;
    }

    // deleting the first node
    if(loc == 1){
        node* temp = head;
        head = head->next;
        free(temp);
        return head;
    }
    
    // traverse to the (loc-1)th node
    node* temp = head;
    for(int i =1;i<loc-1;i++){
        temp = temp->next;
    }

    // check if location is valid
    if(temp == NULL && temp->next == NULL){
        printf("Invalid position! Node not deleted.");
        return head;
    }

    // delete the node at location
    node *del = temp->next;
    temp->next = del->next;
    free(del);
    return head;
}

int main(){
    node * head = NULL;

    head = insertionAtFront(head,24);
    head = insertionAtFront(head,28);
    head = insertionAtEnd(head,23);
    head = insertionAtEnd(head,64);

    // head = deleteAtFront(head);
    // head = deleteAtEnd(head);
    // head = deleteAtPosition(head,3);


    // head = insertAtPosition(head,43,3);
    

    // for printing linkedlist
    node *temp = head;
    while(temp != NULL){
        printf("%d -> ",temp->data);
        temp = temp->next;

    }
    printf("NULL\n");

    return 0;
}
