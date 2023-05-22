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


int main()
{
	int arr[] = {3, 17, 5, 4, 13, 2};
	int n = sizeof(arr) / sizeof(arr[0]);
	printArray(arr, n);
	quickSort(arr, 0, n - 1);
	cout << "Sorted array: \n";
	printArray(arr, n);

	cout<<endl<<endl<<"Enter the input size: ";

	int N;
	cin>>N;
	auto start =  chrono :: steady_clock :: now();

	int arr2[N];
	quickSort(arr2, 0, N - 1);
	
	auto stop = chrono :: steady_clock :: now();
	auto diff = stop-start;

	cout<<"Time taken: ";
	cout << chrono::duration<double,milli>(diff).count() << "ms";
	return 0;
}
