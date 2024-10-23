#include <iostream>
#include <stack>
#include <vector>
using namespace std;

vector<int> nextGreaterElement(vector<int> &arr){
    int n = arr.size();
    vector<int> ans(n, 0);
    stack<int> s;

    for(int i = n-1; i >= 0; i--){
        while(!s.empty() && arr[i] > s.top()){
            s.pop();
        }

        if(s.empty()){
            ans[i] = -1;
        }else{
            ans[i] = s.top();
        }

        s.push(arr[i]);
    }

    return ans;
}

void print(vector<int> &ans){
    int n = ans.size();
    for(int i=0; i < n; i++){
        cout<<ans[i]<<", ";
    }cout<<endl;
}

int main(){
    vector<int> arr = {6, 8, 0, 1, 3};
    vector<int> ans = nextGreaterElement(arr);
    print(ans);
    return 0;
}