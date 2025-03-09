#include <iostream>
using namespace std;

int countSetBits(int num){
    int count = 0;

    while(num > 0){
        count += (num & 1);
        num = num >> 1;
    }

    return count;
}

int main () {
    cout<<countSetBits(2)<<endl;
    return 0;
}