#include <iostream>
#include <string>
using namespace std;

string rmDuplicate(string str, bool* map, string ans, int i) {
    if(i == str.length()) return ans;
    int idx = str[i] - 'a';
    if(map[idx] == false) {
        ans += str[i];
        map[idx] = true;
    }
    return rmDuplicate(str, map, ans, i+1);
}

int main(){
    bool map[26] = {false};
    cout<<rmDuplicate("apnacollege", map, "", 0)<<endl;
    cout<<rmDuplicate("abcabcabcd", map, "", 0)<<endl;

    return 0;
}