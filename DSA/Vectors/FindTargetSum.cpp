#include <iostream>
#include <vector>
using namespace std;

//leetcode problem #167
//find if any pair in sorted vector has target sum
vector<int> pairSum(vector<int> vec, int target){
    int size = vec.size();
    int start = 0, end = size - 1;
    vector<int> ans;

    while(start < end){
        int sum = vec[start] + vec[end];

        if(sum == target){
            ans.push_back(start);
            ans.push_back(end);
            return ans;
        }else if(sum > target){
            end--;
        }else{
            start++;
        }
    }
    return ans;
}

int main(){
    vector<int> vec = {2, 7, 11, 15};
    int target = 9;

    vector<int> ans = pairSum(vec, target);

    cout<<ans[0]<<", "<<ans[1];

    return 0;
}