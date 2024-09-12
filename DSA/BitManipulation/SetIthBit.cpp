#include <iostream>
using namespace std;

int setIthBit(int num, int pos) {
    int bitMask = 1 << pos;

    return (num | bitMask);
}

int main() {
    cout<<setIthBit(4, 3)<<endl;
    cout<<setIthBit(6, 3)<<endl;

    return 0;
}