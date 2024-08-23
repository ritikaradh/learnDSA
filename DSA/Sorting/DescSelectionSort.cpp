#include <iostream>
#include <climits>
using namespace std;

void print(int *nums, int n){
    for(int i=0; i < n; i++){
        cout<<nums[i]<<", ";
    }
    cout<<endl;
}

void selectionSort(int *nums, int n){
    for(int i=0; i < n-1; i++){
        int largest = i;
        for(int j=i+1; j < n; j++){
            if(nums[j] > nums[largest]){
                largest = j;
            }
        }
        swap(nums[i], nums[largest]);
    }
}

int main(){
    int arr[] = {1, 9, 3, 7, 5, 6,10, 0, 2, 4, 8};
    int n = sizeof(arr)/sizeof(int);
    
    selectionSort(arr, n);
    
    print(arr, n);
    
    return 0;
}