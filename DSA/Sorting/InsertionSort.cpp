#include <iostream>
using namespace std;

void print(int *nums, int n){
    for(int i=0; i<n; i++){
        cout<<nums[i]<<", ";
    }
    cout<<endl;
}

void insertionSort(int *nums, int n){
    for(int i=1; i<n; i++){
        int curr = nums[i];
        int prev = i-1;
        while(prev >= 0 && nums[prev] > curr){
            swap(nums[prev], nums[prev+1]);
            prev--;
        }
        nums[prev+1] = curr;
    }
}

int main(){
    int arr[] = {5, 4, 3, 2, 1};
    int n = sizeof(arr)/sizeof(int);
    
    insertionSort(arr, n);
    
    print(arr, n);
    
    return 0;
}