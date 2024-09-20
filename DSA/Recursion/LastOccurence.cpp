#include <iostream>
#include <vector>
using namespace std;

int lastOccurence (vector<int> nums, int target, int i) {
    if (i == nums.size()) return -1;
    int idx = lastOccurence(nums, target, i+1); //checking at later indices
    if (idx == -1 && nums[i] == target) return i;
    return idx;
} 

int main() {
    vector<int> nums = {1,4,3,4,5};
    cout<<lastOccurence(nums, 4, 0)<<endl;
    return 0;
}