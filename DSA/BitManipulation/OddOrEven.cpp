#include <iostream>
using namespace std;

void oddEven (int num){
    if(!(num & 1)){
        cout<<"even"<<"\n";
    }else{
        cout<<"odd"<<"\n";
    }
}

int main(){
    oddEven(4);
    oddEven(15);

    return 0;
}