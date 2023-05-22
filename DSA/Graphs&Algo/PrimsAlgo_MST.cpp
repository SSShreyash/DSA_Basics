//Prim's Alogrithm is a Greedy approach to find Minimum Spanning Tree(MST).
/*
#include<iostream>
using namespace std;
#include<vector>
#include<time.h>
#include<stdlib.h>

#define V 6

int minVertex(vector<int> cost, vector<bool> MSTset){
    int vertex;
    int min = INT_MAX;

    for(int i = 0; i<V; i++){                               //Checking for all vertices.
        if(MSTset[i] == false && cost[i]<min){              //If not already in MSTset[] and cost is lesser than previous cost.
            vertex = i;
            min = cost[i];
        }
    }
    return vertex;
}

void MST(int G[V][V]){
    
    int parent[V];              //Storing parent node each time we cover all adjacent edges starting from different nodes.

    vector<int> cost(V,INT_MAX);
    vector<bool> MSTset(V,false);

    parent[0] = -1;
    cost[0] = 0;
    
    for(int i = 0; i<V-1; i++){                      //For total no. of edges.  
        
        int L = minVertex(cost,MSTset);
        MSTset[L] = true;

        for(int j = 0; j<V; j++){
            if(G[L][j] != 0 && MSTset[j] == false && G[L][j]<cost[j]){
                cost[j] = G[L][j];
                parent[j] = L;
            }
        }

    }

    int sum=0;
    //Print MST.
    for(int x = 1; x<V; x++){
        printf("%d - %d\t %d \n", parent[x], x, G[x][parent[x]]);
        sum+=G[x][parent[x]];
    }
    cout<<"Total weight of MST: "<<sum<<endl;
}

int main(){

    srand(time(0));
    int x;
    int G[V][V];

    for(int i=0; i<V; i++){
        for(int j=0; j<V; j++){
            x = rand()%50;
            G[i][j] = x;
            if(G[i][j]!=0)
                G[j][i]=G[i][j];
        }
    }    

    for(int i=0; i<V; i++){
        for(int j=0; j<V; j++){
            if(i==j)
                G[i][j]=0;

            if(G[i][j]!=0 && i!=j)
                G[j][i]=G[i][j];
        }
    }    

    MST(G);

    return 0;
}


*/

#include<bits/stdc++.h>
using namespace std;

#define V 6

int minVertex(vector<int> cost, vector<bool> MSTSET){
    int min = INT_MAX;
    int vertex;

    for(int i=0; i<V; i++){
        if(MSTSET[i]==false&&cost[i]<min){
            vertex = i;
            min = cost[i];
        }
    }

    return vertex;

}

void MST(int G[V][V]){
    vector<int> parent(V);
    vector<bool> MSTSET(V,false);
    vector<int> cost(V,INT_MAX);

    cost[0] = 1;
    parent[0] = -1;

    for(int i=0; i<V-1; i++){
        int u = minVertex(cost,MSTSET);
        MSTSET[u] = true;

        for(int j=0; j<V; j++){
            if(G[u][j]!=0 && MSTSET[j]==false && G[u][j]<cost[j]){
                cost[j]=G[u][j];
                parent[j] = u;
            }
        }    
    }

    int sum=0;
    
    for(int x = 1; x<V; x++){
        printf("%d - %d\t %d \n", parent[x], x, G[x][parent[x]]);
        sum+=G[x][parent[x]];
    }
    cout<<"Total weight of MST: "<<sum<<endl;

}

int main(){

    int G[V][V];

    srand(time(0));
    int x;
    for(int i=0; i<V; i++){
        for(int j=0; j<V; j++){
            x = rand()%25;
            G[i][j] = x;
        }
    }

    for(int i=0; i<V; i++){
        for(int j=0; j<V; j++){
            if(G[i][j]!=0 && i!=j)
                G[j][i] = G[i][j];
            if(i==j)
                G[i][j]=0;
        }
    }

    MST(G);

    return 0;
}