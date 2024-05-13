#include<iostream>
#include<cmath>
using namespace std;

int main(){
    int start, end;
    cout<<"Enter first index ";
    cin>>start;
    cout<<"Enter end index: ";
    cin>>end;

    while(start < end){
        int flag = 0;
        for(int i=2; i <= sqrt(start); i++){
            if(start % i == 0){
                flag = 1;
                break;
            }
        }
        if (flag == 0 && start != 1){
            cout<<start<<" ";
        }
        start += 1;
    }
    return 0;
}