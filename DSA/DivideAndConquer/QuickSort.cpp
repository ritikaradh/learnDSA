#include <iostream>
#include <vector>
using namespace std;

void print(vector<int> &nums) {
    int n = nums.size();
    for(int i=0; i<n; i++) 
        cout<<nums[i]<<", ";
    cout<<endl;
}

int partition(vector<int> &nums, int start, int end) {
    int i=start, pivotIdx=start, pivot=nums[end];
    while(i < end){
        if(pivot > nums[i])
            swap(nums[i], nums[pivotIdx++]);
        i++;
    }
    swap(nums[pivotIdx], nums[end]);
    return pivotIdx; 
}

void quickSort(vector<int> &nums, int start, int end) {
    if(start >= end) return;
    int pivot = nums[end];
    int pivotIdx = partition(nums, start, end);
    quickSort(nums, start, pivotIdx-1);
    quickSort(nums, pivotIdx+1, end);
}

int main() {
    // vector<int> nums = {6, 3, 7, 5, 2, 4};
    vector<int> nums = {9, 10, 3, 0, 7, 1, 8, 2, 4, 6};
    quickSort(nums, 0, nums.size()-1);
    print(nums);
    return 0;
}