#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Cqueue{
    int size;
    int front;
    int rear;
    int* arr;
};

void enqueue(struct Cqueue* cq, int val){
    if((cq->rear+1)%cq->size == cq->front){
        printf("Queue is full.Cannot enqueue %d.\n",val);
    }
    else{
        cq->rear = (cq->rear+1)%cq->size;           //circular increment upto (size-1).
        cq->arr[cq->rear] = val;
        printf("%d enqueued.\n",val);
    }
}

int dequeue(struct Cqueue* cq){
    if(cq->rear == cq->front){              //Empty condition will be same for linear and circular.
        printf("Queue empty.\n");
        return -1;
    }
    else{
        cq->front = (cq->front+1)%cq->size;
        return cq->arr[cq->front];
    }
}

int main(){

    struct Cqueue* cq;
    cq->size = 3;
    cq->front = cq->rear = 0;                           //One Element(at front) will be always empty.
    cq->arr = (int*) malloc(sizeof(int) * cq->size);

// Unlike linear queue we can dequeue and create space for enqueuing to the queue again even after enqueueing for 'size' no. of times.

//Element at front will be empty, so we can enqueue only 'size-1' elements in our queue.
    enqueue(cq,2);
    enqueue(cq,8);
    enqueue(cq,34);    //This will not be enqueued as size is 3 and 2 elements are already enqueued with an empty element at front.

    printf("%d Dequeued.\n",dequeue(cq));            //q->front moved ahead to dequeue the element at index next to empty element/ 

    enqueue(cq,34);         //So, now we can access the index left behind q->front by "(q->r+1)%size" increment.

    return 0;
}