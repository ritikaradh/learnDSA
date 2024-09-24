#include <iostream>
#include <vector>
using namespace std;

void find(vector<int> nums, int target, int i) {
    if(i == nums.size()) return;
    if(nums[i] == target) cout<<i<<" ";
    return find(nums, target, i+1);
}

int main () {
    vector<int> nums = {3, 2, 4, 5, 6, 2, 7, 2, 2};
    int key = 10;
    find(nums, key, 0);
    return 0;
}