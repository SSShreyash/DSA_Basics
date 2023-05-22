#include<iostream>
using namespace std;
#include<cstdlib>
#include<vector>
#include<time.h>

void DFS(vector<vector<int>>& G, int start, int N, vector<int>& visited){
		
		cout<<start<<" ";
		visited[start] = 1;

		for(int i=0; i<N; i++){
			if(visited[i] == 0 && G[start][i]!=0){
				DFS(G,i,N,visited);
			}
		}

}

int main(){
	int N;
	cout<<"Enter the number of distinct nodes to generate: \n";
	cin>>N;

	vector<int> visited(N,0);

	vector<vector<int>> G(N, vector<int> (N));		

	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			G[i][j] = 0;				//initialize graph with cost = 0,i.e, no edges.		
		}
	}

	for(int i=0; i<N;i++){

		for(int j=0; j<(N-1)/4; j++){			
			int k = rand()%N;					//Select a random vertex to be an edge.
			G[i][k] = 1+rand()%10;						//G[i][k] is cost. If cost = 0, no edge.		
		}

	}
	
	cout<<"Adjacency Matrix Representation of the Nodes in Graph: "<<endl;
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			cout<<G[i][j];
		}
		cout<<endl;
	}
	
	srand(time(0));
	int start = rand()%N;
	
	cout<<"\nDFS Tree: "<<endl;
	DFS(G,start,N,visited);
	cout<<endl;
	return 0;
}
