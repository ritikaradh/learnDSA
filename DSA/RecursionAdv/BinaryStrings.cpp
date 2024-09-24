#include <iostream>
using namespace std;

void bStrings(int n, string ans, int last){
    if (n == 0) {
        cout<<ans<<endl; 
        return;
    }
    bStrings(n-1, ans+'0', 0);
    if (last != 1) bStrings(n-1, ans+'1', 1);
}

int main() {
    bStrings(3, "", 0);
    cout<<endl;
    bStrings(4, "", 0);
    return 0;
}