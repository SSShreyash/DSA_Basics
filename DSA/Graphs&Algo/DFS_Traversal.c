#include<stdio.h>
#include<stdlib.h>

int visited[] = {0,0,0,0,0,0,0};        //This can't be initialised in function as it will get reset with every recursion.

void DFS(int G[7][7], int i){           //DFS implementation using function recursion as Stack.
    visited[i] = 1;                     //For every call visits the node i.
    printf("%d ", i);
    for(int j = 0; j<7; j++){
        if(G[i][j]==1 && visited[j] == 0){          //Look for edges while ignoring the visited nodes.
            
            DFS(G,j);                               //If recursive call halts the for loop before 7, 
                                                    //stacked up recursions will later execute the for loop for remaining edges.
                                                    //Printing only when DFS is called recursively, not when accessed from stack.
        }
    }
}

int main(){

    int G [7][7] = {
        {0,1,1,1,0,0,0},
        {0,0,1,0,0,0,0},
        {1,1,0,1,1,0,0},
        {1,0,1,0,1,0,0},
        {0,0,1,1,0,1,1},
        {0,0,0,0,1,0,0}, 
        {0,0,0,0,1,0,0} 
    };

    DFS(G,1);                   //We start recursion from 0 as first call, which will be executed at last.
    
    return 0;
}