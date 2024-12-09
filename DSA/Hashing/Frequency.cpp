#include <iostream>
#include <vector>
#include <unordered_map>
#include <climits>
using namespace std;

void freqCount(vector<int> &vec) {
    unordered_map<int,int> m;

    int n = vec.size();
    int threshold = n / 3;

    for(int i=0; i<n; i++){
        if(m.count(vec[i]) != 0){
            m[vec[i]]++;
        }else{
            m[vec[i]] = 1;
        }

        if(m[vec[i]] > threshold){
            cout<<vec[i]<<" ";
            m[vec[i]] = INT_MIN;
        }
    }
}

int main(){
    vector<int> vec = {1,2};
    freqCount(vec);
    return 0;
}