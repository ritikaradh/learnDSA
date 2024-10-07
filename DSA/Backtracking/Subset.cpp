#include <iostream>
using namespace std;

void strSubset(string str, string ans){
    //base case
    if(str.length() == 0) {
        cout<<'"'<<ans<<'"'<<"\n";
        return; 
    }
    //kaam
    char ch = str[0];

    //recursive call
    strSubset(str.substr(1, str.length()-1), ans+ch); //yes
    strSubset(str.substr(1, str.length()-1), ans); //no
}

int main(){
    string str = "abc";
    strSubset(str, "");
    return 0;
}