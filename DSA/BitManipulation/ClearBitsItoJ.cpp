#include <iostream>
using namespace std;

int clearBits(int num, int i, int j) {
    int a = (~0) << (j+1);
    int b = (1 << i) - 1;

    int mask = a | b;
    num = num & mask;

    return num;
}

int main () {
    cout<<clearBits(15, 1, 3)<<endl;
    cout<<clearBits(31, 1, 3)<<endl;

    return 0;
}