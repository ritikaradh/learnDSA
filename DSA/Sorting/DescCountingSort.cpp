#include <iostream>
#include <climits>
using namespace std;

void print(int *arr, int n){
    for(int i=0; i < n; i++){
        cout<<arr[i]<<", ";
    }
    cout<<endl;
}

void descCountingSort(int *arr, int n){
    int maxVal = INT_MIN;
    int minVal = INT_MAX;
    int freq[100000];

    //finding the range
    for(int i=0; i<n; i++){
        maxVal = max(maxVal, arr[i]);
        minVal = min(minVal, arr[i]);
    }

    cout<<maxVal<<", "<<minVal<<endl;

    //initializing the frequency array indices
    for(int i=0; i<n; i++){
        freq[arr[i]]++;
    }

    print(freq, n);

    //sorting the array
    for(int i=minVal, j=0; i<=maxVal; i++){
        while(freq[i]>0){
            arr[j++] = i;
            freq[i]--;
        }
    }
    
    print(arr, n);
}

int main(){
    int arr[] = {2, 3, 4, 1, 3, 4};
    int n = sizeof(arr)/sizeof(int);

    descCountingSort(arr, n);

    return 0;
}