#include<iostream>

using namespace std;

int main(){

    int password;
    cin>>password;

/*Without array.
    for(int digit=0; digit<9; digit++){         
        for(int num = password; num>0; num/=10){        
            if(num%10==digit){                    //gives the last digit of the integer.
                cout<<digit<<endl;                //Prints digits from 0 to 9(ascending order) present in password(stored in num).
            }
        }
    }
*/

//With array.
    int size = 0;
    int k = password;
    
    while(k>0){
        size++;
        k/=10;
    }

    k = password;

    int arr[size];
    int i=0;
    while(k>0){
        arr[i] = k%10;
        i++;
        k/=10;
    }

    //Sorting.
    for(int i=0; i<size; i++){
        for(int j=i+1; j<size; j++){
            if(arr[i]>arr[j]){
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

    //After sorting updating the array such that it doesn't start from 0.
    int zeroCount=0;
    while(arr[zeroCount]==0){
        zeroCount++;
    }

    //Replace first index with first index after zeroes.
    int temp = arr[zeroCount];              //Represents the index of element just after all zeroes.
    arr[zeroCount] = arr[0];
    arr[0] = temp;

    for(int i=0; i<size; i++){
        cout<<arr[i];
    }

    return 0;
}