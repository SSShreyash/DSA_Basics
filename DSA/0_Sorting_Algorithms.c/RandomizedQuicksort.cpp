
#include <iostream>
using namespace std;
#include<chrono>
#include<time.h>
#include<cstdlib>

void printArray(int arr[], int size)
{
	int i;
	for (i = 0; i < size; i++)
		cout << arr[i] << " ";
	cout <<endl<<endl<<endl;
}

void swap(int* a, int* b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

//Same partition function used for both standard and randomized quicksort with last element as pivot.
int partition(int arr[], int low, int high)
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

void quickSortStd(int arr[], int low, int high)
{
	if (low < high)
	{
		int partIn = partition(arr, low, high);
		quickSortStd(arr, low, partIn - 1);
		quickSortStd(arr, partIn + 1, high);
	}
}

//Randomized Quicksort.
int PartitionRand(int arr[], int low, int high){

    int random = low + rand()%(high-low);
    swap(&arr[high], &arr[random]);
    return partition(arr,low,high);
}

//After swapping random index element with last index element, call partition function with last element(now random) as pivot.
void quickSortRand(int arr[], int low, int high)
{
	if (low < high)
	{
		int partIn = PartitionRand(arr, low, high);
		quickSortRand(arr, low, partIn - 1);
		quickSortRand(arr, partIn + 1, high);
	}
}

int main()
{   
    /*
	int arr[] = {3, 17, 5, 4, 13, 2, 9};
	int n = sizeof(arr) / sizeof(arr[0]);
	printArray(arr, n);
	//quickSortStd(arr, 0, n-1);
    //quickSortRand(arr, 0, n-1);
	cout << "After sorting:- \n";
	printArray(arr, n);
*/
	cout<<"Enter the input size: ";
	
	int N;
	cin>>N;
	auto startStd =  chrono :: steady_clock :: now();

	int arr1[N];
    for(int i=0; i<N; i++){
        arr1[i] = rand()%N;
    }

	quickSortStd(arr1, 0, N - 1);
	cout<<"Sorted Array for Standard Quicksort: \n";
    printArray(arr1,N);
	auto stopStd = chrono :: steady_clock :: now();
	auto diffStd = stopStd-startStd;

	cout<<"Time taken for standard Quicksort: ";
	cout << chrono::duration<double,milli>(diffStd).count() << "ms"<<endl;


    cout<<endl<<endl;
//Randomized Quicksort.
    auto startRand =  chrono :: steady_clock :: now();

	int arr2[N];
    for(int j=0; j<N; j++){
        arr2[j] = rand()%N;
    }

	quickSortRand(arr2, 0, N - 1);
    cout<<"Sorted Array for randomized Quicksort\n";
	printArray(arr2,N);

	auto stopRand = chrono :: steady_clock :: now();
	auto diffRand = stopRand-startRand;

	cout<<"Time taken for randomized Quicksort: ";
	cout << chrono::duration<double,milli>(diffRand).count() << "ms"<<endl;
	
    return 0;
}