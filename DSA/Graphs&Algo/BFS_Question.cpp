#include<iostream>
using namespace std;
#include<chrono>
#include<cstdlib>
#include<queue>
#include<time.h>
#include<vector>

void BFS(int N){
	
	int G[N][N];
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			G[i][j] = 0;			
		}
	}

	for(int i=0; i<N;i++){

		for(int j=0; j<(N-1)/4; j++){
			int k = rand()%N;
			G[i][k] = 1;				//G[i][k] is cost. If cost = 0, no edge.			
		}
		
	}
	
	vector<int> visited(N,0);
	queue<int> q;
	
	srand(time(0));	
	int start = rand()%N;
	visited[start]=1;
	q.push(start);
	
	cout<<"BFS Tree: "<<endl;
	
	while(q.empty() == 0){
			
			int currnode = q.front();
			q.pop();
			for(int a=0; a<N; a++){
				if(visited[a]==0 && G[currnode][a]!=0){
					cout<<a<<" ";
					visited[a] = 1;
					q.push(a);
				}
			}
	}
}

int main(){
	
	int N;
	cout<<"Enter the number of distinct nodes to generate: \n";
	cin>>N;
	
	BFS(N);
	cout<<endl;

	return 0;
}