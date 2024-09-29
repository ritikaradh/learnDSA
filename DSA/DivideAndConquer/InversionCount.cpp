#include <iostream>
#include <vector>
using namespace std;

int invCount(vector<int> &nums, int start, int end) {
    int mid = start + (end - start)/2;
    int i = start, j = mid+1, inv = 0;
    vector<int> temp;
    
    while(i <= mid && j <= end) {
        if(nums[i] > nums[j]){
            temp.push_back(nums[j++]);
            inv += (mid-i+1);
        }else{
            temp.push_back(nums[i++]);
        }
    }
    
    while(i <= mid || j <= end){
        if(i <= mid){
            temp.push_back(nums[i++]);
        }else{
            temp.push_back(nums[j++]);
        }
    }
    
    for(int i=start, j=0; i <= end; i++, j++){
        nums[i] = temp[j];
    }
    
    return inv;
}

int mergeSort(vector<int> &nums, int start, int end) {
    //base case
    if(start >= end){
        return 0;
    }
    
    //divide
    int mid = start + (end - start)/2;
    
    int inv = 0;
    
    //conquer
    inv += mergeSort(nums, start, mid);
    inv += mergeSort(nums, mid+1, end);
    
    //combine
    inv += invCount(nums, start, end);
    
    return inv;
}

int main() {
    vector<int> nums = {2,4,1,3,5,4};
    cout<<mergeSort(nums, 0, nums.size()-1);
    return 0;
}