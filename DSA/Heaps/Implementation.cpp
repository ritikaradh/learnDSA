#include <iostream>
#include <queue>
using namespace std;

class Heap{
    vector<int> vec;

    //O(logn)
    void heapify(int parI){
        if(parI >= vec.size()){
            return;
        }

        int leftChildI = parI*2 + 1;
        int rightChildI = parI*2 + 2;

        int maxI = parI;

        if(leftChildI < vec.size() && vec[leftChildI] > vec[maxI]) {
            maxI = leftChildI;
        }

        if(rightChildI < vec.size() && vec[rightChildI] > vec[maxI]) {
            maxI = rightChildI;
        }

        swap(vec[maxI], vec[parI]);

        if(maxI != parI){
            heapify(maxI);
        }
    }

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
        //step1: swap first and lastIdx
        swap(vec[0],vec[vec.size()-1]); //O(1)

        //step2: remove element at lastIdx
        vec.pop_back(); //O(1)

        //step3: fix the heap, call heapify
        heapify(0); //O(logn)
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

    while(!hp.empty()) {
        cout<<hp.top()<<" ";
        hp.pop();
    }
    
    return 0;
}