#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void stockSpanProblem(vector<int> stock){
    vector<int> span(stock.size(), 0);
    stack<int> s;

    for(int i=0; i < stock.size(); i++){
        int currPrice = stock[i];

        while(!s.empty() && currPrice > stock[s.top()]){
            s.pop();
        }

        if(s.empty()) span[i] = i+1;
        else{
            int prevHigh = s.top();
            span[i] = i - prevHigh;

            if(stock[prevHigh] == currPrice){
                span[i] += 1;
            }
        }
        s.push(i);
    }
    

    //print span
    for(int i=0; i<span.size(); i++){
        cout<<span[i]<<" ";
    }cout<<endl;
}
int main(){
    vector<int> stock = {100, 80, 60, 70, 60, 85, 100};

    stockSpanProblem(stock);
    return 0;
}