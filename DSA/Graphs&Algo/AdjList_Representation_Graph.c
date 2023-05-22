
#include<stdio.h>
#include<stdlib.h>

//LINKED LIST Representation of Graph.

#define Nodecount 4             //No semicolon for define.

struct node{
    int VertexNumber;               //Represents Node number.
    struct node* next;
};

struct Headarr{         //struct that makes one head node pointer that will point to vertex(index) numbers when we create an array of this struct object.
    struct node* head;
};

struct Headarr* adjList[Nodecount] = { 0 };             //initialising the head node array which we will update in main.

//Every edge will be connection between source and destination passed here.
//Source represents the node connection begins from,i.e., the index of array of head node pointers.
//Ex:-if there's an edge for 0 to 1 and an edge from 1 to 2, all 3 are connected to each other if graph is undirected.
//So, first for index 0 linked list will be: 0->1->3;   args passed (0,1) and (0,3)
//For index 1(Node vertex 1) linked list will be: 1->0->3.     args passed (1,0) and (1,3)
//For every index we pass args for all the edges connected to the Vertex(node) which is equal to array's index.
void addEdge(int s, int d){                     //s and d are source and destination passed in integer form.     
    struct node* source, *dest;
    if(adjList[s] == NULL){        //Source node not yet added to adjacency list.
        source = (struct node*) malloc(sizeof(struct node));
        source->VertexNumber = s;
        source->next = NULL;
        adjList[s]->head = source;      //Point head to source.
    }
    //Source node added or not adding destination node is necessary so add dest node without else.
    dest = (struct node*) malloc(sizeof(struct node));
    dest->VertexNumber = d;
    dest->next = NULL;
    
    struct node* temp = adjList[s]->head;           //Traversing through adjlist's, head with source index.
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = dest;          //Once source node is added to adjList[s], if() won't execute and the dest node will be added at last.

}

void printList(){
    printf("Hello\n.");
    for(int i = 1; i<Nodecount; ++i){
        struct node* p = adjList[i]->head;
        printf("Adjacency list for %d vertex\n",i);

        while(p!=NULL){
            printf("%d",p->VertexNumber);
            p=p->next;
        }
        printf("\n");
    }
}

void print(){
    printf("Excuse\n");
}

void main(){
    
    for(int i = 0; i<Nodecount; i++){                                   //Initialising array of head nodes.
        adjList[i] = (struct Headarr*)malloc(sizeof(struct Headarr));       //Allocating space for 1 node in adjacency list array.
        adjList[i]->head = NULL;                                            
    }
    
    //Undirected graph                                    0
    //                                                  /   \
    //                                                 1     2
    addEdge(0,1);
    addEdge(1,2);
    addEdge(1,0);
    addEdge(2,0);
    addEdge(2,1);
    addEdge(0,2);

    printList();
    print();
}