#include <iostream>
using namespace std;

void printArr(int *nums, int n){
    for(int i=0; i<n; i++){
        cout<<nums[i]<<", ";
    }
    cout<<"\n";
}

void rotateArr(int *nums, int n, int pivotIdx){
    int j = 0, arr[pivotIdx];
    
    for(int i=0; i < pivotIdx; i++){
        arr[i] = nums[i];
    }
    
    for(int i=pivotIdx; i<n; i++){
        nums[j++] = nums[i];
    }
    
    for(int i=0; i < pivotIdx; i++){
        nums[j++] = arr[i];
    }
    
    printArr(nums, n);
}

int main(){
    int nums[] = {0, 1, 2, 4, 5, 6, 7};
    int n = sizeof(nums)/sizeof(int);
    
    int pivotIdx = 3;
    
    //Time complexity of rotateArr is O(3n) = O(n)
    rotateArr(nums, n, pivotIdx);
    
    return 0;
}