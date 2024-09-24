#include <iostream>
#include <vector>
using namespace std;

int firstOccurence(vector<int> nums, int key, int i) {
    if (i == nums.size()) return -1;
    if (nums[i] == key) return i;
    return firstOccurence(nums, key, i+1);
}

int main() {
    cout<<firstOccurence({1,2,3,4,5}, 3, 0)<<endl;
    cout<<firstOccurence({1,2,3,4,5}, 9, 0)<<endl;
    cout<<firstOccurence({1,3,3,4,5}, 5, 0)<<endl;
    return 0;
}