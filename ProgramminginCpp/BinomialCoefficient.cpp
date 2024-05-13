#include <iostream>
using namespace std;

//WAF to find the binomial coefficient for given n & r.
    //nCr = n!/r!(n-r)!

//function to calculate factorial of a number
int fact(int num){
    int factorial = 1;
    for(int i = 1; i <= num; i++){
        factorial *= i;
    }

    return factorial;
}

//function to calculate binomial coefficient of two numbers
int binomialCoeff(int n, int r){
    int nFact = fact(n);
    int rFact = fact(r);
    int nrFact = fact(n-r);

    int binomialCoeff = nFact/ (rFact * nrFact);
    return binomialCoeff;
}

//driver's code
int main(){
    int a,b;

    cout<<"Enter a number:  ";
    cin>>a;

    cout<<"\nEnter another number:    ";
    cin>>b;

    int output = binomialCoeff(a,b);
    cout<<"\nThe binomial coeff of "<<a<<" and "<<b<<" is "<<output;
}