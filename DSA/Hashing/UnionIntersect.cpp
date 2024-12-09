#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

void unionVec(vector<int> &vec1, vector<int> &vec2){
    unordered_set<int> unionOfVec(vec1.begin(), vec1.end());

    for(int ele: vec2){
        unionOfVec.insert(ele);
    }

    for(int ele: unionOfVec){
        cout<<ele<<" ";
    }

    cout<<endl;
}

void intersectVec(vector<int> &vec1, vector<int> &vec2){
    unordered_set<int> intersectOfVec(vec1.begin(), vec1.end());

    for(int ele: vec2){
        if(intersectOfVec.count(ele)){
            cout<<ele<<" ";
            intersectOfVec.erase(ele);
        }
    }

    cout<<endl;
}

int main(){
    vector<int> vec1 = {7,3,9};
    vector<int> vec2 = {6,3,9,2,9,4};
    cout<<"Union Of Vectors"<<endl;
    unionVec(vec1,vec2);
    cout<<"Intersection Of Vectors"<<endl;
    intersectVec(vec1,vec2);

    return 0;
}