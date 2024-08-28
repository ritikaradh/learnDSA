#include <iostream>
#include <string>
using namespace std;

bool validAnagram(string str1, string str2){
    if(str1.length() != str2.length()){
        return false;
    }

    int countArr[26] = {0};

    for(char ch: str1){
        int pos = ch - 'a';
        countArr[pos]++;
    }

    for(char ch: str2){
        int pos = ch - 'a';
        if(countArr[pos] == 0){
            return false;
        }
        countArr[pos]--;
    }
    return true;
}

int main(){
    string str1 = "cat";
    string str2 = "dog";

    cout<<validAnagram(str1,str2)<<"\n";

    return 0;
}