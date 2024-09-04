#include <iostream>
using namespace std;

void func(){
    int size;
    cin>>size;

    //declaring dynamic 1D array
    int *ptr = new int[size];

    int var = 5;

    //defining dynamic 1D array
    for(int i=0; i<size; i++){
        *(ptr+i) = var;
        var += 5;
        cout<<ptr[i]<<", ";
    }
    cout<<endl;

    delete[] ptr;
}

int main() {
    int size;
    cin>>size;

    int *arr = new int[size];
    
    int var = 1;

    for(int i=0; i<size; i++){
        *(arr + i) = var++;
        cout<<arr[i]<<", ";
    }

    cout<<endl;

    func();

    return 0;
}