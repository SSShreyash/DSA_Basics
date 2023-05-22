#include<iostream>
using namespace std;
#include<chrono>

void printArray(int arr[], int n){
    for(int i = 0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
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

int main(){

    cout<<"MergeSort for example array.\n";
    int arr[] = {3, 17, 5, 4, 13, 2};
    int n = sizeof(arr)/ sizeof(arr[0]);
    printArray(arr,n);
    MergeSort(arr,0,n-1);
    printArray(arr,n);

    cout<<endl<<endl<<"Enter the input size: ";
    int N;
    cin>>N;

    auto start = chrono :: steady_clock :: now();
    int arr2[N];
    MergeSort(arr2, 0, N-1);
    auto stop = chrono :: steady_clock :: now();
    auto diff = stop - start;
    
    cout<<"Time taken: ";
    cout<< chrono::duration<double,milli>(diff).count() << "ms"<<endl;
    
    return 0;
}
