#include <iostream>
#include <queue>
#include <vector>
using namespace std;

void print(vector<int> &arr){
    int n = arr.size();

    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }

    cout<<endl;
}

vector<int> slidingWindowMax(vector<int> &vec, int windowSize){
    int n = vec.size();

    priority_queue<pair<int,int>> pq;
    vector<int> ans;

    //step1: push first k elements of vector into priority queue
    for(int i=0; i<windowSize; i++){
        pq.push(make_pair(vec[i],i));
    }

    //step2: insert maximum value element into ans vector
    ans.push_back(pq.top().first);

    //step3: start a for loop until vec size
    for(int i=windowSize; i<n; i++){
        //step4: remove elements outside window iff they're at top
        while(!pq.empty() && pq.top().second < i-windowSize){
            pq.pop();
        }

        //step5: push new element into pq
        pq.push(make_pair(vec[i], i));

        //step6: insert the maximum value element into ans vector
        ans.push_back(pq.top().first);
    }


    //step7: return ans
    return ans;
}

int main() {
    vector<int> vec = {1,3,-1,-3,5,3,6,7};
    vector<int> ans = slidingWindowMax(vec,3);
    print(ans);
    return 0;
}