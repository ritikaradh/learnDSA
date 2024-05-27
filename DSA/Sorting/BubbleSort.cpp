#include <iostream>
using namespace std;

//Bubble Sort
//Intution is to large elements come to end by swapping with adjacents.

void bubbleSort(int *arr, int n){
    bool isSwap = false;
    for(int i=0; i < n; i++){
        for(int j=0; j < n-i-1; j++){
            if(arr[j] > arr[j+1]){
                swap(arr[j], arr[j+1]);
                isSwap = true;
            }
        }
        if(!isSwap){
            return;
        }
    }
}

int main(){
    int n=7;
    int arr[n] = {5,4,1,3,2,6,2};

    bubbleSort(arr, n);

    for (int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }

    return 0;
}