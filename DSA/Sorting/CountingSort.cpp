#include <iostream>
#include <climits>
using namespace std;

void print(int *nums, int n){
    for(int i=0; i<n; i++){
        cout<<nums[i]<<", ";
    }
    cout<<endl;
}

void countingSort(int *nums, int n){
    int freq[100000];
    int minVal = INT_MAX, maxVal = INT_MIN;
    
    //finding the range
    for(int i =0; i < n; i++){
        minVal = min(minVal, nums[i]);
        maxVal = max(maxVal, nums[i]);
    }//O(n)
    
    //initializing freq array elements
    for(int i=0; i < n; i++){
        freq[nums[i]]++;
    }//O(n)
    
    //sorting the array nums
    for(int i= minVal, j=0; i <= maxVal; i++){
        while(freq[i] > 0){
            nums[j++] = i;
            freq[i]--;
        }
    }//O(range) where range = maxVal - minVal
}

int main(){
    int arr[] = {2, 3, 4, 1, 3, 4};
    int n = sizeof(arr)/sizeof(int);
    
    countingSort(arr, n);
    
    print(arr, n);
    
    return 0;
}