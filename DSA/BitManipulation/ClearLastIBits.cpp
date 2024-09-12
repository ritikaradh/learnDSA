#include <iostream>
using namespace std;

int clearLastIBits(int num, int pos) {
    int bitMask = -1 << pos;
    //int bitMask = ~(0) << pos;
    return (num & bitMask);
}

int main () {
    cout<<clearLastIBits(15, 2)<<endl;
    return 0;
}