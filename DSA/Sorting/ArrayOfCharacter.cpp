#include <iostream>
using namespace std;

void charInsertionSort(char *arr, int n){
    for(int i=0; i<n; i++){
        char curr = arr[i];
        int prev = i-1;
        while(prev >=0 && curr > arr[prev]){
            swap(arr[prev], arr[prev+1]);
            prev--;
        }
        arr[prev+1] = curr;
    }
}

int main(){
    // Sort this array of characters using Insertion Sort.
    char arr[] = {'f', 'b', 'a', 'e', 'c', 'd'};
    int n = sizeof(arr)/sizeof(char);

    charInsertionSort(arr, n);

    for(int i=0; i<n; i++){
        cout<<arr[i]<<", ";
    }
    cout<<endl;

    return 0;
}