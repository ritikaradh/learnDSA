#include <iostream>
using namespace std;

int updateIthBit(int num, int pos, int val) {
    //clear ith bit
    int mask = ~(1 << pos);
    num = num & mask;

    //set ith bit
    int bitMask = (val << pos);
    num = num | bitMask ;

    return num;
}

int main () {
    cout<<updateIthBit(7, 2, 0)<<endl;
    cout<<updateIthBit(7, 3, 1)<<endl;

    return 0;
}