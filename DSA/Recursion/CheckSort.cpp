#include <iostream>
#include <vector>
using namespace std;

bool check(vector<int> nums, int n) {
    if (nums[n-1] > nums[n-2] || )
}

int main(){ 
    vector<int> nums = {1,7,3,4,5};
    int ans = check(nums, nums.size());
    if(ans){
        cout<<"Array is sorted"<<endl;
    }else{
        cout<<"Not sorted"<<endl;
    }
    return 0;
}