#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct queue{
    int size;
    int front;                      //Remove(dequeue) at front index.
    int rear;                       //Insert(enqueue) at rear index.
    int* arr;
};

void enqueue(struct queue* q, int val){
    if(q->rear==q->size-1){                 //queue full condition.
        printf("Queue Overload.\n");
    }
    else{
        q->rear++;
        q->arr[q->rear] = val;
    }
}

int dequeue(struct queue* q){
    if(q->rear == q->front){                //queue empty condition.
        printf("Queue Empty.\n");
        return -1;
    }
    else{
        q->front++;
        return q->arr[q->front];
    }
}

int main(){

    struct queue* q;
    q->size = 3;
    q->front = q->rear = -1;
    q->arr = (int* ) malloc(sizeof(int) * q->size);

    enqueue(q,8);
    enqueue(q,3);
    enqueue(q,5);
    
    printf("%d dequeued.\n",dequeue(q));        // 8
    printf("%d dequeued.\n",dequeue(q));        // 3
    printf("%d dequeued.\n",dequeue(q));        // 5

    //Queue and dequeue executed for same no. of times(equal to q->size): q->front and q->rear both will point to q->size-1.
    //So, both queue is empty and is full conditions will be satisfied if enqueue and dequeue both executed for 'size' no. of times. 
    //This is because, we don't consider the elements previous to front index to be in our queue.
    enqueue(q,9);               //Queue overload.
    printf("%d dequeued.\n",dequeue(q));        // -1 is return value for empty queue assuming that -1 is not present in our queue.
                              //So linear queue is empty and full at same time when front reaches to rear which is equal to size-1.
//So we can not insert enqueue even after dequeueing all the elements in queue for linear queue.So, we need circular queue.
    return 0;
}