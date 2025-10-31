#include <stdio.h>
#include <stdlib.h>

// <--- DOUBLY LINKEDLIST --->

typedef struct Node{
    int data;
    struct Node *next,*previous;
}node;

node *insertionAtFront(node *head,int val){
    // memory allocation to newNode
    node *newNode;
    newNode = (node*)malloc(sizeof(node));

    if(newNode == NULL){
        printf("Memory allocation failed!\n");
    }

    newNode->data = val;
    newNode->previous= NULL; // new head has no previous   
    newNode->next = head; // next points to old head
    
    // if link list is not empty, update previous of old head to newnode
    if(head != NULL){
        head->previous = newNode;
    }
    head = newNode; // update head

    return head;
}

node *insertionAtEnd(node *head,int val){
    // memory allocation to newNode
    node *newNode;
    newNode = malloc(sizeof(node));

    // Check allocation
    if(newNode == NULL){
        printf("Memory Allocation failed!");
        return head;
    }

    newNode->data = val;
    newNode->next = NULL;
    newNode->previous = NULL;

    // Linkedlist is empty
    if(head == NULL){
        head = newNode;
        return head;
    }

    // traverse to last node;
    node *temp = head;
    while (temp->next != NULL){
        temp = temp->next;
    }

    // link last node to newnode;
    temp ->next = newNode;
    newNode-> previous = temp;
    
    // return updated head;
    return head;
}

node *insertionAtPosition(node *head,int val,int loc){
    node *newNode;
    newNode = (node*)malloc(sizeof(node));

    // Check allocation
    if(newNode == NULL){
        printf("Memory Allocation failed!");
        return head;
    }
    
    newNode->data = val;
    newNode->next = NULL;
    newNode->previous = NULL;

    // Linkedlist is empty
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
        newNode->previous = NULL;
        if(head != NULL){
            head->previous = newNode;
        }
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
    newNode->previous = temp;
    if(temp->next !=NULL){
        temp ->next->previous = newNode;
    }
    temp->next =newNode;
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
    head->previous = NULL;
    head = head->next; // move head to next node
    free(temp); // free the old first node
    return head;
}

node *deleteAtEnd(node *head) {
    if (head == NULL) {
        printf("LinkedList is empty\n");
        return head;
    }

    node *temp = head;

    // only one node exists
    if (temp->next == NULL) {
        free(temp);
        head = NULL;
        return head;
    }

    // traverse to the last node
    while (temp->next != NULL) {
        temp = temp->next;
    }


    // unlink last node
    temp->previous->next = NULL;

    // delete last node
    free(temp);
    return head;
}


node *deleteAtPosition(node *head,int val,int loc){

    if(head == NULL){
        printf("List is empty");
        return NULL;
    }

    node *temp = head;

    // deleting the first node
    if(loc == 1){
        head = head->next;
        if(head!=NULL)
            head->previous = NULL; // update new head's previous link
        free(temp);
        return head;
    }
    
    // traverse to the (loc-1)th node
    for(int i =1;i<loc-1 ;i++){
        temp = temp->next;
    }

    // check if location is valid
    if(temp == NULL){
        printf("Invalid position! Node not deleted.");
        return head;
    }

    // link previous and next nodes
    if(temp->previous != NULL)
        temp->previous->next = temp->next;

    if(temp->next != NULL)
        temp->next->previous = temp->previous;

    free(temp);
    return head;
}

int main(){
    node * head = NULL;

    
    head = insertionAtFront(head,24);
    head = insertionAtFront(head,44);
    head = insertionAtEnd(head,93);
    head = insertionAtPosition(head,54,3);

    // head = deleteAtFront(head);
    // head = deleteAtEnd(head);
    // head = deleteAtPosition(head,3);


    head = insertionAtPosition(head,43,3);
    

    // for printing linkedlist
    node *temp = head;
    while(temp != NULL){
        printf("%d -> ",temp->data);
        temp = temp->next;

    }
    printf("NULL\n");

    return 0;
}
