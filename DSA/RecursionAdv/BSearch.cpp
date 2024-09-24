#include <iostream>
#include <vector>
using namespace std;

int bSearch(vector<int> nums, int start, int end, int target, int itr){
    if(itr ==  nums.size()/2) return -1;
    int mid = (start + end)/2;
    if(nums[mid] == target) return mid;
    else if(nums[mid] > target) return bSearch(nums, start, end=mid-1, target, itr+1);
    else return bSearch(nums, start=mid+1, end, target, itr+1);
}

int main() {
    vector<int> nums = {1,2,3,4,5,6};
    int start = 0;
    int end = nums.size() - 1;
    cout<<bSearch(nums, start, end, 1, 0)<<endl;
    cout<<bSearch(nums, start, end, 2, 0)<<endl;
    cout<<bSearch(nums, start, end, 3, 0)<<endl;
    cout<<bSearch(nums, start, end, 4, 0)<<endl;
    cout<<bSearch(nums, start, end, 5, 0)<<endl;
    cout<<bSearch(nums, start, end, 6, 0)<<endl;
    cout<<bSearch(nums, start, end, 7, 0)<<endl;
    cout<<bSearch(nums, start, end, 8, 0)<<endl;
    return 0;
}