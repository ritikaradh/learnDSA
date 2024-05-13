#include <iostream>
using namespace std;

int main(){
    int n;
    cout<<"Enter a Number:  ";
    cin>>n;
    for (int i=1; i<=n; i++){
        for (int j=1; j<=n; j++){
            if (i> 9){
                cout<<i<<"  ";
            }
            else{
                cout<<i<<"   ";
            }
        }
        cout<<endl;
    }
    return 0;
}