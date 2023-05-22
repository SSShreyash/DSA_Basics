#include <iostream>
using namespace std;
#include<chrono>

void printArray(int arr[], int size)
{
	int i;
	for (i = 0; i < size; i++)
		cout << arr[i] << " ";
	cout << endl;
}

void swap(int* a, int* b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

int partition (int arr[], int low, int high)
{
	int pivot = arr[high];
	int x = (low - 1);

	for (int i = low; i < high; i++)
	{
		if (arr[i] < pivot)
		{
			x++;
			swap(&arr[x], &arr[i]);
		}
	}
	swap(&arr[x + 1], &arr[high]);
	return (x + 1);
}

void quickSort(int arr[], int low, int high)
{
	if (low < high)
	{
		int partIn = partition(arr, low, high);
		quickSort(arr, low, partIn - 1);
		quickSort(arr, partIn + 1, high);
	}
}

void Merge(int arr[], int left, int mid, int right){
    int Lsize = (mid - left) + 1;                       //Including mid in left array.
    int Rsize = right - mid;
    
    int Left[Lsize], Right[Rsize];

    for(int i = 0; i<Lsize; i++){
        Left[i] = arr[left+i]; 
    }

    for(int j = 0; j<Rsize; j++){
        Right[j] = arr[mid+j+1];
    }

    int i = 0;
    int j = 0;
    int k = left;

    while(i<Lsize && j<Rsize){
        if(Left[i] <= Right[j]){
            arr[k] = Left[i];
            i++;
            k++;
        }
        else{
            arr[k] = Right[j];
            j++;
            k++;
        }
    }

    while(i<Lsize){
        arr[k] = Left[i];
        i++;
        k++;
    }

    while(j<Rsize){
        arr[k] = Right[j];
        j++;
        k++;
    }

}

void MergeSort(int arr[], int left, int right){
    if(left<right){
        int mid = (left + right) / 2;
        MergeSort(arr, left, mid);
        MergeSort(arr, mid+1, right);
        
        Merge(arr, left, mid, right);
    }
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
	
	for(int i = n/2-1; i>=0; i--){
		heapify(arr, n, i);
	}

	for(int i = n-1; i>=0; i--){
		swap(&arr[0],&arr[i]);
		heapify(arr, i, 0);
	}
}

int main(){
    
    int Exarr1[] = {3, 17, 5, 4, 13, 2};               //Example array.
    int n = sizeof(Exarr1) / sizeof(Exarr1[0]);

// Quick sort.
    cout<<"Quick sort for example array:\n";
	
    printArray(Exarr1, n);
	quickSort(Exarr1, 0, n - 1);
	cout << "Sorted array: \n";
	printArray(Exarr1, n);

	cout<<endl<<"Enter the input size: ";
	int N1;
	cin>>N1;

	auto start1 =  chrono :: steady_clock :: now();
	int arr1[N1];
	quickSort(arr1, 0, N1 - 1);
	auto stop1 = chrono :: steady_clock :: now();
	auto diff1 = stop1-start1;

	cout<<"Time taken: ";
	cout << chrono::duration<double,milli>(diff1).count() << "ms"<<endl;

// Merge sort.
    int Exarr2[] = {3, 17, 5, 4, 13, 2};
    n = sizeof(Exarr2) / sizeof(Exarr2[0]);
    cout<<"\nMergeSort for example array:\n";

    printArray(Exarr2, n);
    MergeSort(Exarr2, 0, n-1);
    printArray(Exarr2, n);

    cout<<endl<<endl<<"Enter the input size: ";
    int N2;
    cin>>N2;

    auto start2 = chrono :: steady_clock :: now();
    int arr2[N2];
    MergeSort(arr2, 0, N2-1);
    auto stop2 = chrono :: steady_clock :: now();
    auto diff2 = stop2 - start2;
    
    cout<<"Time taken: ";
    cout<< chrono::duration<double,milli>(diff2).count() << "ms"<< endl;

// Heap sort.
    int Exarr3[] = {3, 17, 5, 4, 13, 2};
    n = sizeof(Exarr3) / sizeof(Exarr3[0]);
    cout<<"\nHeap sort for example array.\n";
    printArray(Exarr3, n);
    heapSort(Exarr3, n);
    printArray(Exarr3, n);

	cout<<endl<<endl<<"Enter input size: ";
	int N3;
	cin>>N3;

	auto start3 = chrono :: steady_clock :: now();
	int arr3[N3];
	heapSort(arr3,N3);
	auto stop3 = chrono :: steady_clock :: now();
	auto diff3 = stop3 - start3;

	cout<<"Time taken: ";
	cout<<chrono::duration<double,milli>(diff3).count()<<"ms"<<endl;

	return 0;
}
