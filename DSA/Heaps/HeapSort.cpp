#include <iostream>
#include <vector>
#include <queue>
using namespace std;

//time complexity: O(logn)
void heapify(int parI, vector<int> &arr, int n) {
    if(parI >= arr.size()-1){
        return;
    }

    int leftCI = parI*2 + 1;
    int rightCI = parI*2 + 2;

    int maxI = parI;

    if(leftCI < n && arr[leftCI] > arr[maxI]){
        maxI = leftCI;
    }

    if(rightCI < n && arr[rightCI] > arr[maxI]){
        maxI = rightCI;
    }

    swap(arr[maxI], arr[parI]);

    if(maxI != parI){
        heapify(maxI, arr, n);
    }
}

//time complexity: n*logn
void heapSort(vector<int> &arr){
    int n = arr.size();

    //step1: for loop (n/2-1 to 0)
    for(int i = n/2; i >= 0; i--){
        heapify(i, arr, n);
    }

    //step2: sorting the vector
    for(int i = n-1; i >= 0; i--){
        swap(arr[0], arr[i]);
        heapify(0, arr, i);
    }
}


int main(){
    vector<int> arr = {1, 4, 2, 5, 3};
    heapSort(arr);
    for(int i : arr){
        cout<<i<<" ";
    }
    return 0; 
}