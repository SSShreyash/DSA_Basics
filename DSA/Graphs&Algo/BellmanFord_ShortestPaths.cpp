#include<iostream>
using namespace std;
#include<cstdlib>
#include<time.h>
#include<vector>

void RELAX(int u, int v, int source, vector<vector<int>>& G, vector<int>& P){
    if(G[source][u] + G[u][v] < G[source][v]){
        G[source][v] = G[source][u] + G[u][v];
        P[v] = u;
    }
}

void BFord(vector<vector<int>>& G, int N, int source, vector<int>& P){
    bool negCycle = false;

    int u;
    int v = 1;
    for(u = 1; u<N; u++){
        while(v<=N && G[u][v]!=0){
            RELAX(u,v,source,G,P);
            v++;
        }
        cout<<"source"<<"->"<<u<<" "<<G[source][u]<<endl;
    }

    v = 1;
    for(u = 1; u<N; u++){ 
        while(v<=N && G[u][v]!=0){
            if(G[source][u] + G[u][v] < G[source][v]){
                negCycle = true;
            }
            v++;
        }
    }

    if(negCycle)
        cout<<"Negative Cycle\n";

}

int main(){

    int N;
    cout<<"Enter the number of distinct nodes to generate: \n";
    cin>>N;

    srand(time(0));
    vector<vector<int>> G(N+1, vector<int> (N+1,0));

    int source = 0;

    for(int i=1; i<=N; i++){
       if(i!=source){
            G[source][i] = rand()%50;       //Distance between source and vertices.
       }
    }

    G[source][0] = 0;               //Distance for vertex 0(source).

    srand(time(0));
    for(int i=1; i<=N;i++){
		for(int j=0; j<=N; j++){
			if(i!=j && i!=source && j!=source){
                G[i][j] = rand()%10;	        //Weights for edges.
            }
		}
	}

    vector<int> P(N+1,-1);

    BFord(G,N,source,P);

    return 0;
}