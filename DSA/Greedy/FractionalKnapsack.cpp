#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
using namespace std;

bool compare(pair<double,int> &a, pair<double,int> &b){
    //sort in descending order of valuability
    return a.first > b.first;
} 

vector<pair<double,int>> getSortedRatio(vector<int> &price, vector<int> &weight){
    int n = price.size();

    vector<pair<double,int>> ratio(n, make_pair(0.0, 0));

    for(int i=0; i<n; i++){
        ratio[i].first = price[i] / weight[i];
        ratio[i].second = i;
    }

    //sort the value vector from most precious item to least precious item
    sort(ratio.begin(), ratio.end(), compare);

    return ratio;
}

int knapsack(vector<int> &price, vector<int> &weight, int capacity){
    int n = price.size();
    double totalVal = 0;

    //calculate the value of each item
    vector<pair<double,int>> ratio = getSortedRatio(price, weight);

    //fill knapsack bag
    for(int i=0; i<n; i++){
        int idx = ratio[i].second;

        if(weight[idx] <= capacity){
            totalVal += price[idx];
            capacity -= weight[idx];
        }else{
            totalVal += (ratio[i].first * capacity);
            break;
        }
    }

    //total value of the knapsack
    return totalVal;
}

int main(){
    vector<int> price = {60, 100, 120};
    vector<int> weight = {10, 20, 30};
    int capacity = 50;

    cout<<knapsack(price, weight, capacity)<<endl;

    return 0;
}