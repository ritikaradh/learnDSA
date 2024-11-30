#include <iostream>
#include <queue>
#include <utility>
#include <vector>
#include <math.h>
using namespace std;

class Car{
    public:
    int idx;
    int distS;

    //constructor
    Car(int idx, int distS){
        this->idx = idx;
        this->distS = distS;
    }

    //operator overloading
    bool operator < (const Car &obj) const{
        return this->distS > obj.distS;
    }
};

void nearbyCars(vector<pair<int,int>> &vec, int k){
    vector<Car> cars;

    for(int i=0; i<vec.size(); i++){
        int distS = pow(vec[i].first,2) + pow(vec[i].second,2);
        cars.push_back(Car(i,distS));
    }

    priority_queue<Car> pq(cars.begin(), cars.end());

    

    //printing nearest cars
    for(int i=0; i<k; i++){
        cout<<"car"<<pq.top().idx<<", "<<pq.top().distS<<endl;
        pq.pop();
    }
}

int main(){
    vector<pair<int,int>> vec;
    vec.push_back(make_pair(3,3));
    vec.push_back(make_pair(5,1));
    vec.push_back(make_pair(-2,4));
    int k = 3;

    nearbyCars(vec,k);


    return 0;
    
}