#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

void print(vector<int> &vec){
    int n = vec.size();
    for(int i=0; i<n; i++){
        cout<<vec[i]<<", ";
    }cout<<endl;
}

int minAbsDif(vector<int> &arr1, vector<int> &arr2){
    int n = arr1.size();
    vector<int> absDiff(n,0);

    //the possible minimum sum of absolute differences is zero.
    int sumAbsDiff=0;

    //the absolute difference between two smaller numbers (or two larger numbers)
    //will always be smaller than the absolute difference between a smaller and a larger number
    //or vice versa.
    
    //therefore, sorting both the arrays in the same order.

    sort(arr1.begin(), arr1.end());
    sort(arr2.begin(), arr2.end());

    //finding pairs
    for(int i=0; i<n; i++){
        absDiff[i] = abs(arr1[i] - arr2[i]);
        sumAbsDiff += absDiff[i];
    }

    print(absDiff);

    return sumAbsDiff;
}

int main(){
    vector<int> arr1 = {6,4,78};
    vector<int> arr2 = {9,4,5};

    cout<<minAbsDif(arr1,arr2)<<endl;

    return 0;
}

