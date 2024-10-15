#include <iostream>
#include <vector>
using namespace std;

const vector<string> keypad = {
    "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

void combination(string &num, string ans="", int pos=0){
    if(pos >= num.length()){
        cout<<ans<<", ";
        return;
    }
    
    int currentNum = num[pos] - '0';
    
    if(currentNum < 2 || currentNum > 9){
        combination(num, ans, pos+1);
    }
    
    for(char ch: keypad[currentNum-2]) {
        combination(num, ans+ch, pos+1);
    }
}

int main() {
    string num = "23";
    combination(num);
}

