#include <iostream>
using namespace std;

const int MOD = 1e9 + 7;

int goodString(int n, int pos=0, int ans=1){
    if(pos == n) return ans;
    if(pos % 2 == 0) return goodString(n, pos+1, (ans*5) % MOD);
    else return goodString(n, pos+1, (ans*4) % MOD);
}

int main(){
    cout<<goodString(1)<<endl;
    cout<<goodString(2)<<endl;
    cout<<goodString(3)<<endl;
    cout<<goodString(4)<<endl;
    return 0;
}


