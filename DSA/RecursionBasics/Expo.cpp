#include <iostream>
using namespace std;

//time complexity O(n)
int expo1(int num, int power) {
    if (power == 1){
        return num;
    }
    return num * expo1(num, power-1);
}

//time complexity O(logn)
int expo2(int num, int power) {
    if (power == 0) return 1;
    int half = expo2(num, power/2);
    int square = half * half;
    if (power % 2 != 0) return num*square;

    return square;
}

int main () {
    cout<<expo1(2,8)<<endl;
    cout<<expo2(2,8)<<endl;
    return 0;
}