#include<iostream>
using namespace std;
#include<cstdlib>
#include<limits.h>
#include<time.h>
#include<vector>
#include<chrono>

void RELAX(int& u, int& v, int& source, vector<vector<int>>& G, vector<int>& P,int& AssignCount){
    if(G[source][u] + G[u][v] < G[source][v]){
        G[source][v] = G[source][u] + G[u][v];
        P[v] = u;
        AssignCount++;
    }
}

int selectMinVertex(vector<int>& dist, vector<bool>& processed, int V){
    int minimum = INT_MAX;
    int vertex;

    for(int i=0; i<V; i++){
        if(processed[i] == false && dist[i]<minimum){
            vertex = i;
            minimum = dist[i];
        }
    }
    
    return vertex;

}

void Dijkstra(vector<vector<int>> &G, int V, int source){
    vector<int> P(V);
    vector<int> dist(V,INT_MAX);
    vector<bool> processed(V,false);
    
    int AssignCount = 0;
    int CompCount = 0;
    P[0] = -1;
    dist[0] = 0;

    for(int i=0; i<V-1; i++){
        int min = selectMinVertex(dist, processed, V);
        processed[min] = true;

        for(int j=0; j<V; j++){

            if(G[min][j]!=0 && processed[j]==false){
                RELAX(min,j,source,G,P,AssignCount);
                cout<<"\t";
                CompCount++;
            }

        }
    }
    
    /*
    for(int x=1; x<V; x++){
        cout<<"u->v: "<<P[x]<<"->"<<x<<"\t distance = "<<G[P[x]][x]<<endl;
    }
    */

    cout<<endl<<"Comparisons: "<<CompCount<<endl<<"Assignments: "<<AssignCount<<endl;
}

int main(){
    int V;
    cout<<"Enter the number of distinct vertex to generate: \n";
    cin>>V;

    int source = 0;

    vector<vector<int>> G(V, vector<int> (V));
	for(int i=0; i<V; i++){
		for(int j=0; j<V; j++){
			G[i][j] = 0;	
		}
	}

    G[source][0] = 0;               //Distance for vertex 0(source).

    for(int i=0; i<V; i++){
       int k = rand()%V;
       if(k!=source){
            G[source][k] = rand()%50;       //Distance between source and vertices.
       }
    }

    srand(time(0));
    for(int i=0; i<V; i++){
		for(int j=0; j<V; j++){
			if(i!=j && i!=source && j!=source){
                G[i][j] = rand()%10;	    //Weights for edges.
            }
		}
    }

    auto start = chrono :: steady_clock :: now();
	Dijkstra(G,V,source);
    auto end = chrono :: steady_clock :: now();
	
	auto diff = end - start;

	cout<<chrono::duration<double,micro>(diff).count()<<"ms"<<endl;

    return 0;
}
