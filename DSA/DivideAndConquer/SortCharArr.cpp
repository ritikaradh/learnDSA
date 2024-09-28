#include <iostream>
#include <vector>
using namespace std;

void print(vector<string> &arr){
    int n = arr.size();
    for(int i=0; i<n; i++) cout<<arr[i]<<", ";
    cout<<endl;
}

void merge(vector<string> &arr, int start, int end){
    vector<string> temp;
    int mid = start + (end - start)/2;
    int i = start, j = mid+1;

    while(i <= mid && j <= end){
        if(arr[i] <= arr[j]) 
            temp.push_back(arr[i++]);
        else
            temp.push_back(arr[j++]);
    }

    while(i <= mid || j <= end){
        if(i <= mid)
            temp.push_back(arr[i++]);
        else
            temp.push_back(arr[j++]);
    }

    for(int i=start, j=0; j < temp.size(); i++, j++){
        arr[i] = temp[j];
    }
}

void mergeSort(vector<string> &arr, int start, int end){
    if(start >= end) return;

    int mid = start + (end - start)/2;

    mergeSort(arr, start, mid);
    mergeSort(arr, mid+1, end);

    merge(arr, start, end);
}

int main(){
    vector<string> arr= {"sun", "earth","mars","mercury"};
    mergeSort(arr, 0, arr.size()-1);
    print(arr);
    return 0;
}