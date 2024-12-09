#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

bool validAnagram(string s, string t){
    unordered_map<char,int> map;
    
    for(char ch: s){
        if(map.count(ch)){
            map[ch]++;
        }else{
            map[ch] = 1;
        }
    }

    for(char ch: t){
        if(map.count(ch)){
            map[ch]--;
            if(map[ch] == 0) map.erase(ch);
        }
        else return false;
    }

    if(!map.size()) return true;
    return false;
}

int main(){
    string s = "race";
    string t = "care";

    cout<<validAnagram(s,t)<<endl;

    return 0;
}