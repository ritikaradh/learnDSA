#include <iostream>
using namespace std;

int linearSearch(int *arr, int n, int key){
    for (int i=0 ; i < n; i++){
        if (arr[i] == key){
            return i;
        }
    }
    return -1;
}

int main(){
    int arr[] = {12, 23, 45, 12, 54, 32, 95, 54};

    int key;
    cout<<"Enter a key to be searched: ";
    cin>>key;

    int len = sizeof(arr) / sizeof(int);

    cout<<linearSearch(arr, len, key)<<endl;

    return 0;
}