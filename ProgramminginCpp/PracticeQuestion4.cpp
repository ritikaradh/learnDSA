#include<iostream>
using namespace std;

//Print all primes in a range from 2 to n.

//Function to generate prime numbers in the given range
void primeGenerator(int n){

    for(int i=2 ; i <= n; i++){

        bool isPrime = true;

        if(i==2){
            cout<<i<<" ";
            continue;
        }

        for (int j = 2; j <= i/2; j++){
            if(i % j==0){
                isPrime = false;
                break;
            }
        }

        if (isPrime == true){
            cout<<i<<" ";
        }
    }
}

int main(){
    int n;

    cout<<"Enter a range: ";
    cin>>n;

    cout<<"Generating Prime Number in the range 2-"<<n<<endl;

    primeGenerator(n);

    return 0;
}