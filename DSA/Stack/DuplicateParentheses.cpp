#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool pairForm(char &s1, char &s2){
    return 
        ( s1=='(' && s2==')' ) || 
        ( s1=='[' && s2==']' ) || 
        ( s1=='{' && s2=='}' )
    ;
}

void duplicateParentheses(string &str){
    stack<char> s;
    int n = str.size();
    for(int i=0; i < n; i++){
        if( !( str[i]==')' || str[i]=='}' || str[i]==']' ) ){
            s.push(str[i]);
            continue;
        }

        //check for duplicate parentheses 
        if( pairForm(s.top(), str[i]) ){
            cout<<"Duplicate Parentheses"<<endl;
            return;
        }

        while(!s.empty() && !pairForm(s.top(), str[i])){
            s.pop();
        }

        s.pop();
    }
    cout<<"No duplicate Parentheses"<<endl;
    return;
}

int main(){
    string str1 = "((x+y))+z";
    string str2 = "((x+y)+z)";
    string str3 = "((x+y)+(z))";
    string str4 = "((x+y)+((z)))";

    duplicateParentheses(str1);
    duplicateParentheses(str2);
    duplicateParentheses(str3);
    duplicateParentheses(str4);

    return 0;
}