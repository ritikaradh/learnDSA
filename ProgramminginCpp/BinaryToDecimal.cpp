#include <iostream>
using namespace std;

int binaryToDecimal(int binaryNumber){
    int n = binaryNumber;
    int decimalNumber = 0;
    int power = 1;

    while(n > 0){
        int lastDigit = n % 10;
        decimalNumber += lastDigit * power;

        power *= 2;
        n /= 10;
    }
    return decimalNumber;
}

int main(){
    cout<<binaryToDecimal(10001);
    return 0;
}