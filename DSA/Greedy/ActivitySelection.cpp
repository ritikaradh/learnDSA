#include <iostream>
#include <vector>
using namespace std;

int activitySelection(vector<int> &start, vector<int> &end){

    //greedy approach

    //step1: sort activities on end time

    //step2: select non-overlapping activity
    int n = start.size();
    int count = 1;
    int currEnd = end[0];

    cout<<"Activity No. 1"<<", ";

    for(int i=1; i < n; i++){
        if(currEnd <= start[i]){
            cout<<"Activity No. "<<i+1<<", ";
            count+=1;
            currEnd = end[i];
        }
    }

    cout<<endl;
    return count;
}

int main() {
    vector<int> start = {1, 3, 0, 5, 8, 5};
    vector<int> end = {2, 4, 6, 7, 9, 9};

    cout<<activitySelection(start, end)<<endl;

    return 0;
}