#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<vector<int>> threeSum(vector<int> &nums){
    int n = nums.size();
    vector<vector<int>> ans;

    sort(nums.begin(), nums.end());

    for(int i = 0; i < n-2; i++){
        //skip duplicate elements for the current index i
        if(i > 0 && nums[i] == nums[i-1])
            continue;

        int start = i+1, end = n-1;

        while(start < end){
            int sum = nums[i] + nums[start] + nums[end];

            if(sum == 0){
                vector<int> temp = {nums[i], nums[start], nums[end]};
                ans.push_back(temp);

                //skipping duplicates for the two pointers
                while(start < end && nums[start] == nums[start+1]) start++;
                while(start < end && nums[end] == nums[end-1]) end--;

                start++, end--;
            }
            else if(sum > 0) {
                end--;
            }
            else{
                start++;
            }
        }
    }
    return ans;
}

int main(){
    vector<int> nums = {-2,0,0,2,2};
    vector<vector<int>> ans = threeSum(nums);

    for(int i=0; i < ans.size(); i++){
        cout<<ans[i][0]<<", "<<ans[i][1]<<", "<<ans[i][2];
        cout<<endl;
    }

    return 0;
}