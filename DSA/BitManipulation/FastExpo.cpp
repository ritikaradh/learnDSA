#include <iostream>
using namespace std;

int fastExpo(int num, int pow){
    int ans = 1;

    while(pow > 0) {
        int lastBit = pow & 1;
        if (lastBit) {
            ans = ans * num ;
        }
        num = num * num;
        pow = pow >> 1;
    }
    return ans;
}

int main(){
    cout<<fastExpo(2, 4);
    return 0;
}