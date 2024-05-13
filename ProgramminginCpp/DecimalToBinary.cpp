#include <iostream>
using namespace std;

int decimalToBinary(int decimalNum){
    int n = decimalNum;
    int pow = 1;
    int binaryNum = 0;

    while(n >= 1){
        int rem = n % 2;
        binaryNum += rem * pow;

        pow *= 10;
        n /= 2; 
    }

    return binaryNum;
}

int main(){
    cout<<decimalToBinary(39);
    return 0;
}