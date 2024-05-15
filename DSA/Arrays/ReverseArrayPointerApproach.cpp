#include <iostream>
using namespace std;

void reverseArr(int *arr, int n){
    int temp, j = n - 1;
    for(int i = 0; i < j; i++){
        temp = arr[i];
        arr[i] = arr[j];
        arr[j--] = temp;
        //we can swap two numbers using in-built swap function in C++ swap(arr[i],arr[j])
    }
}

int main(){
    int arr[] = {1,2,3,4,5};
    int n = sizeof(arr) / sizeof(int);

    reverseArr(arr, n);
    
    for(int i = 0; i < n; i++){
        cout<<arr[i]<<" ";
    }

    return 0;
}

