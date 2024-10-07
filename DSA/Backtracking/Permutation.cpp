#include <iostream>
using namespace std;

void permutation(string str, string ans) {
    int n = str.length();

    //base case
    if(str.length() == 0){
        cout<<ans<<endl;
        return;
    }

    //kaam
    for(int i=0; i < n; i++) {
        //recursive call
        permutation(str.substr(0, i) + str.substr(i+1, n-i-1), ans+str[i]);
    }
}

int main() {
    string str = "abc";
    permutation(str, "");
    return 0;
}