#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(pair<int,int> &a, pair<int,int> &b){
    return a.second < b.second;
}

int maxChainLengthPair(vector<pair<int,int>> &pair){
    int n = pair.size();
    int currEnd = pair[0].second;
    int count = 1;

    //sort the received vector of pairs
    sort(pair.begin(), pair.end(), compare);

    //select non-overlapping pairs
    for(int i=1; i<n; i++){
        if(currEnd < pair[i].first){
            count++;
            currEnd = pair[i].second;
        }
    }


    return count;
}

int main(){
    vector<pair<int,int>> pairs(5, make_pair(0,0));

    pairs[0] = {5,24};
    pairs[1] = {39,60};
    pairs[2] = {5,28};
    pairs[3] = {27,40};
    pairs[4] = {50,90};

    cout<<maxChainLengthPair(pairs)<<endl;
    
    return 0;
}