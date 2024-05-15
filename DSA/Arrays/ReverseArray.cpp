#include <iostream>
using namespace std;

void reverseArray(int *arr, int len){
    int temp[len];
    int j = len -1;
    for(int i=0; i < len ; i++){
        temp[i] = arr[j--];
    }

    j=0;
    for(int i = 0; i < len; i++){
        arr[i] = temp[j++];
    }

    free(temp);
}

int main(){
    int n = 5;
    int arr[n] ={1,2,3,4,5};
    reverseArray(arr,n);
    for(int i = 0; i < n; i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}