#include <iostream>
using namespace std;

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

    int x = 5, y = 10;
    int *ptr = &x, *ptr2 = &y;
    cout<<ptr<<endl;
    cout<<ptr2<<endl;

    ptr2 = ptr;
    cout<<ptr<<endl;
    cout<<ptr2<<endl;
    
    return 0;
}