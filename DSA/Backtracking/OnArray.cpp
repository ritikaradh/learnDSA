#include <iostream>
#include <vector>
using namespace std;

void print(vector<int> &nums){
    int n = nums.size();
    for(int i=0; i < n; i++){
        cout<<nums[i]<<", ";
    }cout<<endl;
}

void change(vector<int> &nums, int n, int idx) {
    if(idx == n){
        print(nums);
        return;
    }
    nums[idx] = idx+1;
    change(nums, n, idx+1);
    nums[idx] -= 2;

}

int main() {
    vector<int> nums(5,0);
    print(nums);

    change(nums, 5, 0);
    print(nums);

    return 0;
}