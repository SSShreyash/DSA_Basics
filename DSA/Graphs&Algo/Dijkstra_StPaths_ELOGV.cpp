#include<iostream>
#include<limits.h>
#include<time.h>
#include<stdlib.h>
#include<chrono>
using namespace std;

struct AdjListNode
{
	int dest;
	int weight;
	struct AdjListNode* next;
};

struct AdjList
{
    struct AdjListNode *head;
};

struct Graph
{
	int V;
	struct AdjList* array;
};

// Function to create a new adjacency list node.
struct AdjListNode* newAdjListNode(int dest, int weight){
	struct AdjListNode* newNode = (struct AdjListNode*)malloc(sizeof(struct AdjListNode));
	newNode->dest = dest;
	newNode->weight = weight;
	newNode->next = NULL;
	return newNode;
}

struct Graph* createGraph(int V)
{
	struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
	graph->V = V;

	graph->array = (struct AdjList*)malloc(V * sizeof(struct AdjList));

	for (int i = 0; i < V; ++i)
		graph->array[i].head = NULL;

	return graph;
}

void addEdge(struct Graph* graph, int source, int dest, int weight)
{
	struct AdjListNode* newNode = newAdjListNode(dest, weight);
	newNode->next = graph->array[source].head;
	graph->array[source].head = newNode;

	newNode = newAdjListNode(source, weight);
	newNode->next = graph->array[dest].head;
	graph->array[dest].head = newNode;
}

struct MinHeapNode
{
	int v;
	int dist;
};

struct MinHeap
{
	int size;	
	int capacity;

	int *pos;
	struct MinHeapNode **array;
};

struct MinHeapNode* newMinHeapNode(int v, int dist)
{
	struct MinHeapNode* minHeapNode = (struct MinHeapNode*)malloc(sizeof(struct MinHeapNode));
	minHeapNode->v = v;
	minHeapNode->dist = dist;
	return minHeapNode;
}

struct MinHeap* createMinHeap(int capacity)
{
	struct MinHeap* minHeap = (struct MinHeap*)malloc(sizeof(struct MinHeap));
	minHeap->pos = (int *)malloc(capacity * sizeof(int));
	minHeap->size = 0;
	minHeap->capacity = capacity;
	minHeap->array = (struct MinHeapNode**)malloc(capacity *sizeof(struct MinHeapNode*));
	return minHeap;
}

void swapMinHeapNode(struct MinHeapNode** a, struct MinHeapNode** b)
{
	struct MinHeapNode* t = *a;
	*a = *b;
	*b = t;
}

void minHeapify(struct MinHeap* minHeap, int idx)
{
	int smallest, left, right;
	smallest = idx;
	left = 2 * idx + 1;
	right = 2 * idx + 2;

	if (left < minHeap->size && minHeap->array[left]->dist < minHeap->array[smallest]->dist )
	    smallest = left;

	if (right < minHeap->size && minHeap->array[right]->dist < minHeap->array[smallest]->dist )
	    smallest = right;

	if (smallest != idx)
	{
		MinHeapNode *smallestNode = minHeap->array[smallest];
		MinHeapNode *idxNode = minHeap->array[idx];

		minHeap->pos[smallestNode->v] = idx;
		minHeap->pos[idxNode->v] = smallest;

		swapMinHeapNode(&minHeap->array[smallest], &minHeap->array[idx]);
		minHeapify(minHeap, smallest);
	}
}

int isEmpty(struct MinHeap* minHeap)
{
	return minHeap->size == 0;
}

struct MinHeapNode* extractMin(struct MinHeap* minHeap)
{
	if (isEmpty(minHeap))
		return NULL;

	struct MinHeapNode* root = minHeap->array[0];

	struct MinHeapNode* lastNode = minHeap->array[minHeap->size - 1];
	minHeap->array[0] = lastNode;

	minHeap->pos[root->v] = minHeap->size-1;
	minHeap->pos[lastNode->v] = 0;

	(--minHeap->size);
	minHeapify(minHeap, 0);

	return root;
}

void decreaseKey(struct MinHeap* minHeap, int v, int dist)
{
	int i = minHeap->pos[v];

	minHeap->array[i]->dist = dist;

	while (i && minHeap->array[i]->dist < minHeap->array[(i - 1) / 2]->dist)
	{
		minHeap->pos[minHeap->array[i]->v] = (i-1)/2;
		minHeap->pos[minHeap->array[(i-1)/2]->v] = i;
		swapMinHeapNode(&minHeap->array[i], &minHeap->array[(i - 1) / 2]);

		i = (i - 1) / 2;
	}
}

bool isInMinHeap(struct MinHeap *minHeap, int v)
{
	if (minHeap->pos[v] < minHeap->size)
		return true;
	return false;
}

void printArr(int dist[], int n)
{
	cout<<"Vertex\t Distance from Source\n";
	for (int i = 0; i < n; ++i)
		cout<<i<<"\t\t"<<dist[i]<<endl;
}

void dijkstra(struct Graph* graph, int source)
{
	
	int V = graph->V;
	int dist[V];	
	struct MinHeap* minHeap = createMinHeap(V);

	for (int v = 0; v < V; ++v)
	{
		dist[v] = INT_MAX;
		minHeap->array[v] = newMinHeapNode(v,dist[v]);
		minHeap->pos[v] = v;
	}

	minHeap->array[source] = newMinHeapNode(source, dist[source]);
	minHeap->pos[source] = source;
	dist[source] = 0;
	decreaseKey(minHeap, source, dist[source]);

	minHeap->size = V;
	int compCount=0;
	int AssignCount=0;
	while (!isEmpty(minHeap))
	{
		struct MinHeapNode* minHeapNode = extractMin(minHeap);
		int u = minHeapNode->v;
		
		struct AdjListNode* t = graph->array[u].head;
		while (t != NULL)
		{
			int v = t->dest;
			compCount++;
			
			if (isInMinHeap(minHeap, v) && dist[u] != INT_MAX && t->weight + dist[u] < dist[v])
			{	
				dist[v] = dist[u] + t->weight;
				AssignCount++;
				decreaseKey(minHeap, v, dist[v]);
			}
			t = t->next;
		}
	}
	printArr(dist, V);                              //To print the shortest distances.

	cout<<"Comparisons: "<<compCount<<endl<<"Assignments: "<<AssignCount<<endl;
}

int main()
{
	int V;
	cout<<"Enter the no. of Vertices: "<<endl;
	cin>>V;
	struct Graph* graph = createGraph(V);
	srand(time(0));

    for(int i=0; i<V; i++){
		for(int j=0; j<V; j++){
			int w = 1 + rand()%10;
			if(i!=j)
				addEdge(graph, i, j, w);
		}
	}
	
	auto start = chrono :: steady_clock :: now();
	dijkstra(graph, 0);
	auto end = chrono :: steady_clock :: now();
	
	auto diff = end - start;

	cout<<chrono::duration<double,milli>(diff).count()<<"ms"<<endl;

	return 0;
}
