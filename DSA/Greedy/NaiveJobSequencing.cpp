#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
using namespace std;

int jobSequencing(vector<pair<int,int>> &jobs){
    int n = jobs.size();

    //step1: sort
    sort(jobs.begin(), jobs.end(), [](pair<int,int> &a, pair<int,int> &b){
        if(a.first == b.first) return a.second > b.second;
        return a.first < b.first;
    });

    //step2: always select first job
    int currEnd = jobs[0].first;
    int totalProfit = jobs[0].second;

    //step3: for loop(int i=1 to n)
    for(int i=1; i<n; i++){
        int end = jobs[i].first;
        if(currEnd < end){
            currEnd = end;
            totalProfit += jobs[i].second;
        }
    }

    
    return totalProfit;
}

int main() {
    vector<pair<int,int>> jobs(4);

    jobs[0].first = 4;
    jobs[0].second = 20;

    jobs[1].first = 1;
    jobs[1].second = 10;

    jobs[2].first = 1;
    jobs[2].second = 40;

    jobs[3].first = 1;
    jobs[3].second = 30;

    cout<<jobSequencing(jobs)<<endl;

    return 0;
}