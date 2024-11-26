#include <iostream>
#include <queue>
using namespace std;

class Heap{
    vector<int> vec;

    public:
    
    void push(int val){
        //step1: push_back
        vec.push_back(val);

        //step2: fix heap
        int childIdx = vec.size() - 1;
        int parIdx = (childIdx - 1) / 2;

        while(parIdx >= 0 && vec[childIdx] > vec[parIdx]){
            swap(vec[childIdx], vec[parIdx]);
            childIdx = parIdx;
            parIdx = (childIdx - 1) / 2;
        }
    }

    void pop(){

    }

    int top(){
        //highest priority element
        return vec[0];
    }

    bool empty(){
        return vec.empty();
    }
};

int main(){
    Heap hp;
    hp.push(10);
    hp.push(5);
    hp.push(8);

    cout<<hp.top()<<endl;
    
    return 0;
}