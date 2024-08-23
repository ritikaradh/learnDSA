#include <iostream>
using namespace std;

void print(int *nums, int n){
    for(int i=0; i < n; i++){
        cout<<nums[i]<<", ";
    }
    cout<<endl;
}

void bubbleSort(int *nums, int n){
    for(int i=0; i<n; i++){
        for(int j=0; j<n-i-1; j++){
            if(nums[j] < nums[j+1]){
                swap(nums[j], nums[j+1]);
            }
        }
    }
}

int main(){
    int arr[] = {5, 4, 1, 3, 2};
    int n = sizeof(arr)/sizeof(int);
    
    bubbleSort(arr, n);
    
    print(arr, n);
    
    return 0;
}