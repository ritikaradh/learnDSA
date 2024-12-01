#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Soldier{
    public:
    int row;
    int sol;

    //constructor
    Soldier(int row, int sol){
        this->row = row;
        this->sol = sol;
    }

    //operator overloading
    bool operator < (const Soldier &obj) const{
        if(this->sol == obj.sol){
            return this->row > obj.row;
        }
        return this->sol > obj.sol;
    }
};

void weakestSoldier(vector<vector<int>> &matrix, int k){
    vector<Soldier> vec;

    for(int i=0; i<matrix.size(); i++){
        int row = i;
        int sol = 0;

        for(int j=0;  j < matrix[i].size() && matrix[i][j] == 1; j++){
            sol += 1;
        }

        vec.push_back(Soldier(row,sol));
    }

    //construct priority queue
    priority_queue<Soldier> pq(vec.begin(), vec.end());


    //print k weakest soldiers
    for(int i=0; i<k; i++){
        cout<<"soldier"<<pq.top().row<<endl;
        pq.pop();
    }
}


int main(){
    vector<vector<int>> matrix = {
        {1,0,0,0},
        {1,1,1,1},
        {1,0,0,0},
        {1,0,0,0},
    };

    weakestSoldier(matrix,2);

    return 0;
}