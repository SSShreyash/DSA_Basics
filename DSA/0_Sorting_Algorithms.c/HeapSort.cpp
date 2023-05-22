#include<iostream>
using namespace std;
#include<chrono>

void printArray(int arr[], int n){
    for(int i = 0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void swap(int* a, int* b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

void heapify(int arr[],int n, int root){
	int largest = root;
	int LC = 2*root+1;
	int RC = 2*root+2;
	
	if(LC<n && arr[largest]<arr[LC]){
		largest = LC;
	}

	if(RC<n && arr[largest]<arr[RC]){
		largest = RC;
	}

	if(largest!=root){
		swap(&arr[root],&arr[largest]);
		heapify(arr,n,largest);
	}
}

void heapSort(int arr[], int n){
	
	//Build Max heap.
	for(int i = n/2-1; i>0; i--){
		heapify(arr, n, i);
	}
	
	for(int i = n-1; i>0; i--){
		swap(&arr[0],&arr[i]);
		heapify(arr, i, 0);
	}
}

int main(){

    int arr[] = {32, 17, 5, 40, 13, 2, 1};
    int n = sizeof(arr)/ sizeof(arr[0]);
    printArray(arr, n);
    heapSort(arr, n);
    printArray(arr,n);

	cout<<endl<<endl<<"Enter input size: ";
	int N;
	cin>>N;

	auto start = chrono :: steady_clock :: now();
	int arr2[N];
	heapSort(arr2,N);
	auto stop = chrono :: steady_clock :: now();

	auto diff = stop - start;

	cout<<"Time taken: ";
	cout<<chrono::duration<double,milli>(diff).count()<<"ms"<<endl;

	return 0;
}