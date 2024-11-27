#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void heapify(int parI, vector<int> &arr, int n) {
    if(parI >= arr.size()-1){
        return;
    }

    int leftCI = parI*2 + 1;
    int rightCI = parI*2 + 2;

    int maxI = parI;

    if(leftCI < arr.size() && arr[leftCI] > arr[maxI]){
        maxI = leftCI;
    }

    if(rightCI < arr.size() && arr[rightCI] > arr[maxI]){
        maxI = rightCI;
    }

    swap(arr[maxI], arr[parI]);

    if(maxI != parI){
        heapify(maxI, arr, n);
    }
}

void heapSort(vector<int> &arr){
    int n = arr.size();

    //step1: for loop (n/2-1 to 0)
    for(int i = n/2; i >= 0; i--){
        heapify(i, arr, n);
    }
}