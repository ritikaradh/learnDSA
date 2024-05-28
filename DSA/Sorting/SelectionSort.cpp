#include <iostream>
using namespace std;

void selectionSort(int *arr, int n){
    //idea- for each position, find correct element.
    for(int pos=0; pos < n-1; pos++){
        int minIndex = pos;
        for(int index=pos+1; index < n; index++){
            if(arr[index] < arr[minIndex]){
                minIndex = index;
            }
        }
        swap(arr[pos], arr[minIndex]);
    }
}

int main(){
    int n=5;
    int nums[5] = {5, 4, 1, 3, 2};

    selectionSort(nums, n);

    for(int i=0; i<n; i++){
        cout<<nums[i]<<" ";
    }
    return 0;
}


//The time complexity of the above code is