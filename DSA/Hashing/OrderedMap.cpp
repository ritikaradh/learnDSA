#include <iostream>
#include <map>
using namespace std;

int main (){
    map<string, int> m;

    m["China"] = 150;
    m["India"] = 150;
    m["US"] = 50;
    m["Nepal"] = 150;

    for(pair<string, int> country: m){
        cout<<country.first << " : " <<country.second<<endl;
    }

    if(m.count("Nepal")){
        cout<<"Nepal exists"<<endl;
    }else{
        cout<<"Nepal doesn't exists"<<endl;
    }

    m.erase("Nepal");

    if(m.count("Nepal")){
        cout<<"Nepal exists"<<endl;
    }else{
        cout<<"Nepal doesn't exists"<<endl;
    }

    return 0;
}