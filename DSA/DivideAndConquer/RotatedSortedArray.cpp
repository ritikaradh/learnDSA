#include <iostream>
#include <vector>
using namespace std;

int rotatedSortedArr(vector<int> &nums, int target, int start, int end){
    // base case
    if(start > end) return -1;
    
    // divide
    int mid = start + (end - start)/2;

    // check
    if(nums[mid] == target) return mid;

    // conquer
    if(nums[start] <= nums[mid]){ // L1
        if(nums[start] <= target && nums[mid] > target) // case1
            return rotatedSortedArr(nums, target, start, mid-1);   // left subarray
        else    // case2
            return rotatedSortedArr(nums, target, mid+1, end); // right subarray
    }else{  // L2
        if(nums[mid] < target && nums[end] >= target)    // case3
            return rotatedSortedArr(nums, target, mid+1, end);  // right subarray
        else    // case 4
            return rotatedSortedArr(nums, target, start, mid-1);
    }
}

int main(){ 
    // vector<int> nums = {7, 8, 9, 0, 2, 3, 4, 6};
    // cout<<rotatedSortedArr(nums, 2, 0, nums.size()-1)<<endl;
    // cout<<rotatedSortedArr(nums, 3, 0, nums.size()-1)<<endl;
    vector<int> nums = {7};
    cout<<rotatedSortedArr(nums, 9, 0, nums.size()-1)<<endl;
    return 0;
}