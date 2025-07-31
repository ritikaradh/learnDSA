#include <iostream>
#include <list>
using namespace std;

class Graph{
    //data members
    int sizeOfGraph;
    list<pair<int,int>>* vectorsList; //list<pair<neighbor,weight>>

    public:

    //constructor
    Graph(int sizeOfGraph){
        this->sizeOfGraph = sizeOfGraph;
        vectorsList = new list<pair<int,int>> [sizeOfGraph];
    }

    //method to associate edge with vectors
    void addEdge(int vector, int neighbor, int weight){
        vectorsList[vector].push_back(make_pair(neighbor,weight));

        // vectorsList[neighbor].push_back(make_pair(vector,weight));

        cout<<vector<<"--->"<<neighbor<<"("<<weight<<")"<<endl;
    }

    //print graph
    void printGraph(){
        for(int i=0; i<sizeOfGraph; i++){
            list<pair<int,int>> neighbors = vectorsList[i];
            cout<<i<<" : ";

            for(pair<int,int> neighbor : neighbors){
                cout<<"("<<neighbor.first<<","<<neighbor.second<<")";
            }

            cout<<endl;
        }
    }

};

int main(){
    Graph graph(5);

    graph.addEdge(0,1,5);
    graph.addEdge(1,2,1);
    graph.addEdge(2,3,1);
    graph.addEdge(2,4,2);
    graph.addEdge(3,1,3);

    cout<<"____________________"<<endl;

    graph.printGraph();

    return 0;
}