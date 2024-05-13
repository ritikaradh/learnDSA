//1.    WAP where user can keep entering numbers till they enter a multiple of 10.

// #include<iostream>
// using namespace std;

// int main(){
//     int n;
//     do{
//         cout<<"Enter a Number: ";
//         cin>>n;
//     }while(n % 10 != 0);

//     return 0;
// }

//2.    Write a program to show numbers entered by user except multiple of 10.

#include<iostream>
using namespace std;

int main(){
    int i=5, n;
    do{
        cout<<"Enter a Number:  ";
        cin>>n;
        i -= 1;
        if(n % 10 == 0){
            continue;
        }
        cout<<"You entered "<<n<<endl;
    }while(i != 0);
}