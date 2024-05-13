#include<iostream>
using namespace std;

//1.    WAF to find the product of 2 numbers: a and b
int productTwoNumber(int a, int b){
    return a*b;
}

//2.    WAF to print if a number is odd or even.
string oddOrEven(int num){
    if (num % 2==0){
        return "even";
    }
    else{
        return "odd";
    }
}

//3.    WAF to print the factorial of a number n.
int fact(int num){
    int factorial = 1;
    for(int i = 1; i <= num; i++){
        factorial *= i;
    }

    return factorial;
}

//4.    WAF to print if a number is prime or not.
string primeNumber(int num){
    if(num == 1){
        return "not prime";
    }
    else{
        for(int i=2; i <= num/2; i++){
            if (num % i == 0){
                return "not prime";
            }
        }
    }
    return "prime";
}

//drivre's code
int main(){
    int a, b, num;

    // cout<<"Product of Two Numbers"<<endl;
    // cout<<"Enter a number:  "<<endl;
    // cin>>a;
    // cout<<"Enter another number:    "<<endl;
    // cin>>b;
    // int output1 = productTwoNumber(a,b);
    // cout<<"The product of two numbers is "<<output1<<endl;

    cout<<"Enter a number: ";
    cin>>num;
    string output2 = oddOrEven(num);
    cout<<"The number is "<<output2<<endl;

    int output3 = fact(num);
    cout<<"The factorial of the number "<<num<<" is "<<output3<<endl;

    string output4 = primeNumber(num);
    cout<<output4<<endl;

    return 0;
}