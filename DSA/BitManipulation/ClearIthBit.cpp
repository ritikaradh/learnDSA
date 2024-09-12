#include <iostream>
using namespace std;

int clearIthBit(int num, int pos ) {
    int bitMask = ~(1 << pos);

    return (num & bitMask);
}

int main() {
    cout<<clearIthBit(6, 1)<<endl;
    return 0;
}