#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int coinExchange(vector<int> &denomination, int val){
    int n = denomination.size();
    int count = 0;

    //sort the denomination
    sort(denomination.begin(), denomination.end(), [](int &a, int &b){
        return a > b;
    });

    //start while loop until V > 0
    for(int i=0; i < n && val > 0; i++){
        if(denomination[i] <= val){
            count += val / denomination[i];
            val = val % denomination[i];
        }
    }


    //return totalCoins
    return count;
}

int main(){
    vector<int> denomination = {
        1,2,5,10,20,50,100,500,2000
    };

    cout<<coinExchange(denomination, 590)<<endl;
    cout<<coinExchange(denomination, 121)<<endl;

    return 0;
}