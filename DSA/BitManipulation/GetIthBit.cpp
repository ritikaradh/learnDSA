#include <iostream>
using namespace std;

int getIthBit(int num, int pos) {
    int mask = 1 << pos;

    if(num & mask ) {
        return 1;
    }
    return 0;
}

int main() {
    cout<<getIthBit(6, 2)<<endl;
    cout<<getIthBit(7, 2)<<endl;
    cout<<getIthBit(8, 2)<<endl;
    cout<<getIthBit(8, 3)<<endl;

    return 0;
}