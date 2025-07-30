#include <iostream>
#include <list>
using namespace std;

class Graph{
    //data members
    int sizeOfGraph; //no. of vectors in the graph
    list<int>* vectorsList; //list containing the vectors
    
    public:
    
    //constructor
    Graph(int sizeOfGraph){
        this->sizeOfGraph = sizeOfGraph;
        vectorsList = new list<int>[sizeOfGraph];
    }
    
    //associate edges with vector
    void addEdge(int currVec, int neighborVec){
        vectorsList[currVec].push_back(neighborVec);
        vectorsList[neighborVec].push_back(currVec);
        cout<<currVec<<"---"<<neighborVec;
        cout<<endl;
    }
    
    //print the graph
    void printGraph(){
        //i->vector
        for(int i=0; i<sizeOfGraph; i++){
            list<int> neighbors = vectorsList[i];
            
            cout<<i<<" : ";
            
            for(int neighbor : neighbors){
                cout<<neighbor<<", ";
            }
            
            cout<<endl;
        }
    }
};

int main(){
    Graph graph(5);
    
    graph.addEdge(0,1);
    graph.addEdge(1,2);
    graph.addEdge(2,3);
    graph.addEdge(2,4);
    graph.addEdge(3,1);
    
    graph.printGraph();
    
    return 0;
}