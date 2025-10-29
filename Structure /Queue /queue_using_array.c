#include <stdio.h>

#define SIZE 5
// enqueue

typedef struct array_queue
{
    int data;
} krish;

void enqueue(int queue[], int value, int *rear, int *front)
{
    if ((*rear) == SIZE - 1)
    {
        printf("Queue is overflowed!");
    }
    else
    {
        if ((*rear) == -1)
        {
            (*front) = 0, (*rear) = 0;
            queue[(*rear)] = value;
        }
        else
        {
            (*rear)++;
            queue[(*rear)] = value;
        }
    }
}

void dequeue(int queue[], int *rear, int *front)
{
    if ((*rear) == -1)
    {
        printf("Queue is empty!");
    }
    else
    {
        (*front)++;
    }
}

void display(int queue[],int rear, int front){
    if(front == -1){
        printf("Queue is empty");
    }
    else{
        for(int i = front;i<=rear;i++){
            printf("%d ",queue[i]);
        }
        printf("\n");
        
    }

}

int  size(int queue[], int *rear, int *front)
{
    int size = 0;
    if(*front == -1){
        printf("Queue is empty");
    }
    else{
        for(int i = *front;i<=*rear;i++){
            size++;
        }
        
    }
    return size;
}

// top

// size

// empty

int main()
{
    int queue[SIZE];
    int front = -1;
    int rear = -1;

    enqueue(queue, 12, &rear, &front);
    enqueue(queue, 420, &rear, &front);
    enqueue(queue, 98, &rear, &front);
    // enqueue(queue, 67, &rear, &front);



    // dequeue(queue,&rear,&front);

    display(queue,rear,front);

    printf("Size: %d",size(queue,&rear,&front));

    return 0;
}
