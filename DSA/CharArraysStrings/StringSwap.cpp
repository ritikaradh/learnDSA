#include <iostream>
#include <string>
using namespace std;

bool stringSwap(string str1, string str2){
    if(str1.length()!=str2.length()){
        return false;
    }

    
}

int main(){
    string str1, str2;
    getline(cin, str1);
    getline(cin, str2);

    stringSwap(str1, str2);

    return 0;
}