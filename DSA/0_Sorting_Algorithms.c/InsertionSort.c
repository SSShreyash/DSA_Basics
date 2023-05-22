#include<stdio.h>

void printArray(int arr[], int N){
    for(int i=0; i<N; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void insertionSort(int arr[], int N){
    int i,j;
    for(i=1; i<N; i++){
        int curr = arr[i];
        for(j = i-1; j>=0 && arr[j]>curr; j--){
            arr[j+1] = arr[j];
        }
        arr[j+1] = curr;
    }
}

int main(){
    
    int arr[] = {5,12,2,17,4,6,41,20,5,12};
    int N = sizeof(arr)/sizeof(arr[0]);
    printArray(arr,N);

    insertionSort(arr,N);
    printArray(arr,N);
    return 0;
}