#include <iostream>
using namespace std;

int main(){
    //take the elements of an array as input
    int len;

    cout<<"Enter the length of array: ";
    cin>>len;

    int arr[len];
    int i = 0;

    do{
        cout<<"Enter the element: ";
        cin>>arr[i++];
    }while(i < len);

    //printing the elements of the array
    for(int i= 0; i < len; i++){
        cout<<arr[i]<<", ";
    }
    cout<<endl;
    
    cout<<"The total bits occupied in the memory to store this array is "<<sizeof(arr)<<endl;

    return 0;
}