#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int minCost(vector<int> &vec){
    if(vec.size() == 0 || vec.size() == 1) return 0;
    priority_queue<int, vector<int>, greater<int>> pq(vec.begin(), vec.end());
    int totalCost = 0;

    while(!pq.empty()){
        int x = pq.top(); pq.pop();
        int y = pq.top(); pq.pop();

        int cost = x+y;

        totalCost += cost;

        if(!pq.empty()) pq.push(cost);
    }

    return totalCost;
}

int main(){
    vector<int> vec = {4,3,2,6};
    cout<<minCost(vec)<<endl;
    return 0;
}