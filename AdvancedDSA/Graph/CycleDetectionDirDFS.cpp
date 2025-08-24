#include <iostream>
#include <vector>
#include <list>
using namespace std;

class Graph{
    //data members
    int sizeOfGraph;
    list<int>* nodesList;

    //helper method for cycle detection method
    bool cycleDetectorHelper(int node, vector<bool> &visited, vector<bool> &recursionPath){
        visited[node] = true;
        recursionPath[node] = true;

        list<int> neighbors = nodesList[node];

        for(int neighbor : neighbors) {
            if(!visited[neighbor]){
                if(cycleDetectorHelper(neighbor, visited, recursionPath)){
                    return true;
                }
            } 
            else if (recursionPath[neighbor]){
                return true;
            }
        }

        recursionPath[node] = false;
        return false;
    }

    public:

    //constructor
    Graph(int sizeOfGraph) {
        this->sizeOfGraph = sizeOfGraph;
        this->nodesList = new list<int> [sizeOfGraph];
    }

    //build graph method
    void buildGraph(int node, int neighbor){
        nodesList[node].push_back(neighbor);
        cout<<node<<"--->"<<neighbor<<endl;
    }

    //cycle detection method in directed graph
    void cycleDetector(){
        vector<bool> visited(sizeOfGraph, false);
        vector<bool> recursionPath(sizeOfGraph, false);

        for(int node=0; node<sizeOfGraph; node++){
            if(!visited[node] && cycleDetectorHelper(node, visited, recursionPath)){
                cout<<endl<<"Cycle exists"<<endl;
                return;
            }
        }

        cout<<endl<<"Cycle doesn't exists"<<endl;
    }   
};

int main(){
    Graph graph_1(6);

    graph_1.buildGraph(0,1);
    graph_1.buildGraph(1,2);
    graph_1.buildGraph(2,3);
    graph_1.buildGraph(3,0);
    graph_1.buildGraph(2,4);
    graph_1.buildGraph(4,5);

    graph_1.cycleDetector();

    cout<<endl<<endl;

    Graph graph_2(6);

    graph_2.buildGraph(0,1);
    graph_2.buildGraph(1,2);
    graph_2.buildGraph(2,3);
    graph_2.buildGraph(2,4);
    graph_2.buildGraph(4,5);

    graph_2.cycleDetector();



    return 0;
}