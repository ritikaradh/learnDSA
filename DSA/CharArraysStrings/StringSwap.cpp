#include <iostream>
#include <string>
using namespace std;

bool stringSwap(string str1, string str2){
    if(str1.length()!=str2.length()){
        return false;
    }

    int size = str1.length();
    
    for(int i = 0; i < size; i++){
        for(int j=i+1; j < size; j++){
            string temp = str2;
            swap(temp[i], temp[j]);
            if(temp == str1){
                return true;
            }
        }
    }

    for(int i = 0; i < size; i++){
        for(int j=0; j < size; j++){
            string temp = str1;
            swap(temp[i], temp[j]);
            if(temp == str2){
                return true;
            }
        }
    }

    return false;
}

int main(){
    string str1 = "kanb", str2 = "bank";

    cout<<stringSwap(str1, str2)<<"\n";

    return 0;
}