#include <iostream>
using namespace std;

int main(){
    int arr[] = {12,23,12,3,28,13,1,5};
    int max = 0;

    int len = sizeof(arr) / sizeof(int);

    for(int i = 0; i < len; i++){
        if (arr[i] > max){
            max = arr[i];
        }
    }

    cout<<"The largest number in the array is "<<max<<endl;

    cout<<arr<<endl;

    cout<<(arr+1)<<endl;

    return 0;
}