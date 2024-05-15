#include <iostream>
using namespace std;

int binarySearch(int *arr, int n, int key){
    int start = 0, end = n -1;

    while(start <= end){
        int mid = (start + end)/2;

        if(arr[mid] == key){
            return mid;
        }
        else if(key > arr[mid]){
            start = mid + 1;
        }
        else{
            end = mid - 1;
        }
    }

    return -1;
}

int main(){
    int arr[] = {1,2,3,4,5,10,12,14,16,20,23,25};
    int n = sizeof(arr) / sizeof(int);

    // int key;
    // cout<<"Enter key to be searched: "<<endl;
    // cin>>key;

    cout<<binarySearch(arr, n, 30)<<endl;

    return 0;
}