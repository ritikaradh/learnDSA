#include <iostream>
using namespace std;

//1.    Largest of two numbers.
// int main(){
//     int num1;
//     int num2;
//     cout<<"Enter first number: ";
//     cin>>num1;
//     cout<<"Enter second number: ";
//     cin>>num2;

//     if (num1 > num2){
//         cout<<"The largest of the two numbers is: "<<num1;
//     }
//     else{
//         cout<<"The largest of the two numbers is: "<<num2;
//     }

//     return 0;
// }

//2.    Odd or Even.

int main(){
    int num;
    cout<<"Enter a number to be checked: ";
    cin>>num;
    if(num % 2==0){
        cout<<num<<" is even";
    }
    else{
        cout<<num<<" is odd";
    }

    return 0;
}