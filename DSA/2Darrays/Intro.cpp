#include <iostream>
using namespace std;

int main(){
    //student array stores the marks of subject english and maths for five students
    const int n = 5, m = 2;
    int student[n][m];

    for(int i=0; i<n; i++){
        cout<<"Student "<<i+1<<"\n";
        for(int j=0; j < m; j++){
            cin>>student[i][j];
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cout<<student[i][j]<<", ";
        }
        cout<<"\n";
    }
    // print(student, n, m);

    return 0;
}