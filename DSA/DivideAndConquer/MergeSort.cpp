#include <iostream>
#include <vector>
using namespace std;

void print(vector<int> &nums){
    int n = nums.size();
    for(int i=0; i<n; i++){
        cout<<nums[i]<<", ";
    }
    cout<<endl;
}

void merge(vector<int> &nums, int start, int end){
    int mid = (start+end)/2;

    vector<int> auxiliary;

    int i=start, j=mid+1; //left and right array pointers

    while(i <= mid && j<=end){
        if(nums[i] <= nums[j]) auxiliary.push_back(nums[i++]);
        else auxiliary.push_back(nums[j++]);
    }

    while(i <= mid || j <= end){
        if(i <= mid) auxiliary.push_back(nums[i++]);
        else auxiliary.push_back(nums[j++]);
    }

    for(int i=start, j=0; j < auxiliary.size(); i++, j++){
        nums[i] = auxiliary[j]; 
    }
}

void mergeSort(vector<int> &nums, int start, int end){
    if(start >= end) return; //base case

    int mid = (start+end)/2; //divide

    mergeSort(nums, start, mid); //conquer left array
    mergeSort(nums, mid+1, end); //conquer right array

    merge(nums, start, end); //combine results
}

int main(){
    vector<int> nums = {6, 3, 7, 5, 2, 4};
    mergeSort(nums, 0, nums.size()-1);
    print(nums);
    return 0;
}