#include <iostream>
#include <queue>
#include <utility>
using namespace std;

struct compare{
    //operator overloading

    //max-heap
    bool operator () (const pair<string,int> &p1, const pair<string,int> &p2) const{
        return p1.second < p2.second;
    }

    //min-heap
    // bool operator () (const pair<string,int> &p1, const pair<string,int> &p2) const{
    //     return p1.second > p2.second;
    // }
};

int main(){
    priority_queue<pair<string,int>, vector<pair<string,int>>, compare> pq;

    pq.push(make_pair("ritika",75));
    pq.push(make_pair("anisha",90));
    pq.push(make_pair("tisha", 80));

    while(!pq.empty()){
        cout<<pq.top().first<<", "<<pq.top().second<<endl;
        pq.pop();
    }

    return 0;
}