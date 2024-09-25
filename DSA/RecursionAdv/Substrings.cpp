#include <iostream>
#include <string>
using namespace std;

int countStr(string str, int i, int j, int ans) {
    if(i == str.length()) {  // BASE CASE
        return ans;
    }
    else if(j == str.length()) { // RECURSIVE CALL
        return countStr(str, i+1, i+1, ans); 
    }
    else { // KAAM
        if(str[i] == str[j]) ans += 1;
        return countStr(str, i, j+1, ans); 
    }
}

int main() {
    cout<<countStr("abcab", 0, 0, 0)<<endl;
    cout<<countStr("aba", 0, 0, 0)<<endl;
    return 0;
}
