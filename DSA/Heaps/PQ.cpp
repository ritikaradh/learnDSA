#include <iostream>
#include <queue>
using namespace std;

int main(){
    priority_queue<int> pq;
    priority_queue<int, vector<int>, greater<int>> q;
    pq.push(12);
    pq.push(42);
    pq.push(15);
    q.push(12);
    q.push(42);
    q.push(15);

    cout<<"Max Heap"<<endl;
    while(!pq.empty()){
        cout<<pq.top()<<" ";
        pq.pop();
    }
    
    cout<<endl<<"Min Heap"<<endl;

    while(!q.empty()){
        cout<<q.top()<<" ";
        q.pop();
    }

    return 0;
}