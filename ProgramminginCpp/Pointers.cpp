#include <iostream>
using namespace std;

void multiplyBy2(int *param1, int *param2, int *param3){
    *param1 *= 2;
    *param2 *= 2;
    *param3 *= 2;
}

int main(){
    // int a = 51;
    // int *ptr = &a;
    // int **pptr = &ptr;
    // **pptr = 32;
    // int *ptr = NULL;
    // int a = 89;
    // cout<< &a << "\n";
    // cout<< ptr <<"\n";
    // cout<< &ptr << "\n";
    // cout<<pptr<<"\n";
    // cout<<(*ptr)<<"\n";
    // cout<<(**pptr)<<"\n";
    // cout<<a<<"\n";
    // cout<<ptr<<"\n";

    // int x = 5, y = 10;
    // int *ptr = &x, *ptr2 = &y;
    // cout<<ptr<<endl;
    // cout<<ptr2<<endl;

    // ptr2 = ptr;
    // cout<<ptr<<endl;
    // cout<<ptr2<<endl;

    // //Assignment 1
    int x;
    int *ptr;
    x = 7;
    ptr = &x;
    cout<<*ptr<<endl;

    // //Assignment 2
    int a = 1, b = 2, c = 3;
    multiplyBy2(&a, &b, &c);
    cout<<a<<b<<c<<endl;

    //Assignment 3
    // int e = 32;
    // int *ptrs = &e;

    // char ch = 'A';
    // char &cho = ch;

    // cho += e;
    // *ptrs += ch;

    // cout<<e<<" , "<<ch<<endl;


    int e = 32;
    int *ptrs = &e;

    char ch = 'A';
    char &cho = ch;

    cho += e;

    *ptrs += ch;

    cout<<e<<" , "<<ch<<endl;

    return 0;
}