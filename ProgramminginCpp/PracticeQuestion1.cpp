//1.    Print the sum of digits of a number using while loop.

// #include <iostream>
// using namespace std;

// int main(){
//     int sum = 0, n;
//     cout<<"Enter a Number: ";
//     cin>>n;
    
//     while(n >= 1){
//         int digit = n % 10;
//         sum += digit;
//         n /= 10;
//     }
    
//     cout<<"The sum of the digits of the number "<<"is "<<sum;

//     return 0;
// }

//2.    Print the sum of odd digits of a number using while loop.

// #include<iostream>
// using namespace std;

// int main(){
//     int sum=0, n;
//     cout<<"Enter a Number:  ";
//     cin>>n;

//     while(n >= 1){
//         int digit = n % 10;

//         if(digit % 2 != 0){
//             sum += digit;
//         }
        
//         n /= 10;
//     }
//     cout<<"The sum of the odd digits of the number is "<<sum;

//     return 0;
// }

//3.    Print the digits of a given number in reverse using while loop.

// #include <iostream>
// using namespace std;

// int main(){
//     int n, n_reversed;
//     cout<<"Enter a Number: ";
//     cin>>n;

//     while(n >= 1){
//         int digit = n % 10;
//         cout<<digit;
//         n /= 10;
//     }

//     return 0;
// }

//4.    Reverse a given number and print the result.

#include<iostream>
using namespace std;

int main() {
    int reversed_num = 0, n;
    cout<<"Enter a Number: ";
    cin>>n;

    while(n >= 1){
        int digit = n % 10;
        reversed_num = reversed_num*10 + digit;
        n /= 10;
    }

    cout<<"The reversed number is "<<reversed_num;

    return 0;
}
