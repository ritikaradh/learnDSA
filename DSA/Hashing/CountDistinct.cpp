#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

int countDistinct(vector<int> &vec) {
    unordered_set<int> set(vec.begin(), vec.end());
    return set.size();
}


int main(){
    vector<int> vec = {4,3,2,5,6,7,3,4,2,1};
    cout<<countDistinct(vec)<<endl;
    return 0;
}

