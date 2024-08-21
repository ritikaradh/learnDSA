#include <iostream>
#include <math.h>
using namespace std;

bool bitAdd(bool bit1, bool bit2){
    if(bit1 == 0){
        if(bit2 == 0){
            return 0,0;
        }
        return 1,0;
    }
    else{
        if(bit2 == 0){
            return 1,0;
        }
        return 1,1;
    }
}

int binAdd(int binNum1, int binNum2){
    int binAdd = 0;
    int i = 0;
    
    while(binNum1 > 0 || binNum2 > 0){
        bool bit1 = binNum1 % 10;
        bool bit2 = binNum2 % 10;
        
        bool add, carry = bitAdd(bit1, bit2);

        binAdd = binAdd + pow(10,i++)*add;

        binNum1 /= 10;
        binNum2 /= 10;

    }

    return binAdd;
}

int main(){
    int binNum1, binNum2;

    cout<<"Enter first binary number:\t";
    cin>>binNum1;

    cout<<"Enter second binary number:\t";
    cin>>binNum2;


    cout<<binAdd(binNum1, binNum2)<<"\n";

    return 0;
}