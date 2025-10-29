#include <stdio.h>
#include <stdlib.h>

typedef struct queue{

    int data;
    struct queue *next;
}queue;

queue *enqueue(queue *head,int val){
    queue *newNode = malloc(sizeof(queue));
    newNode->data = val;
    newNode->next = NULL;
    if(head == NULL){
        head = newNode;
    }
    else{
        queue *temp = head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = newNode;
    }
    return head; // Always return updated head
}

queue *dequeue(queue *head){
    if(head == NULL){
        printf("Queue is empty");
        return NULL;
    }
    queue* temp = head;

    head = head->next;
    free(temp);

    return head;
}


void display(queue *head){
    queue* temp = head;

    if(head == NULL){
        printf("Queue is empty");
    }

    while(temp!=NULL){
        printf("%d ",temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main(){
    queue* head = NULL;

    head = enqueue(head,22);
    head = enqueue(head,25);
    head = enqueue(head,26);
    head = dequeue(head);
    display(head);

    return 0;
}
