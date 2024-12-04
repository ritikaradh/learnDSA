#include <iostream>
#include <unordered_set>
using namespace std;

int main() {
    unordered_set<int> s;

    s.insert(1);
    s.insert(5);
    s.insert(2);
    s.insert(1);

    cout<<s.size()<<endl;

    //check if a key exists
    if(s.find(5) != s.end()){
        cout<<"5 exists\n"<<endl;
    }else{
        cout<<"5 doesn't exists\n"<<endl;
    }

    s.erase(5);

    if(s.find(5) != s.end()){
        cout<<"5 exists\n"<<endl;
    }else{
        cout<<"5 doesn't exists\n"<<endl;
    }

    for(auto ele:s){
        cout<<ele<<" ";
    }

    return 0;
}