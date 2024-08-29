#include <iostream>
#include <string>
using namespace std;

int countVowel(string str){
    if(str.length()==0){
        return -1;
    }
    int count = 0;
    for(char ch: str){
        if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u'){
            count +=1;
        }
    }
    return count;
}

int main(){
    string str;
    cout<<"enter string: ";
    getline(cin,str);
    
    cout<<countVowel(str)<<endl;

    return 0;
}