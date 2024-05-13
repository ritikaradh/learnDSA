#include <iostream>
using namespace std;

int main(){
    int n;
    cout<<"Enter a number:  ";
    cin>>n;
    int sum = 0;

    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= i; j++){
            sum += 1;
            cout<<sum<<" ";
        }
        cout<<endl;
    }

    return 0;
}