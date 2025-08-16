#include <iostream>
#include <list>
#include <vector>
using namespace std;

class Graph{
    //data members
    int sizeOfGraph;
    list<int>* vectorsList;

    //helper method for cycle detection in undirected graph through dfs
    bool cycleDetectionDFSHelper(int node, vector<bool> &visited, int parent){
        visited[node] = true;

        list<int> neighbors = vectorsList[node];

        for(int neighbor : neighbors){
            if(!visited[neighbor]){
                if (cycleDetectionDFSHelper(neighbor, visited, node)) 
                    return true;
            }
            else{
                if(parent != -1 && neighbor != parent) 
                    return true;
            }
        }

        return false;
    }

    public:

    //constructor
    Graph(int sizeOfGraph){
        this->sizeOfGraph = sizeOfGraph;
        this->vectorsList = new list<int>[sizeOfGraph];
    }

    //build graph method - used to associate edge between nodes
    void buildGraph(int node, int neighbor){
        vectorsList[node].push_back(neighbor);
        vectorsList[neighbor].push_back(node);
        cout<<node<<"---"<<neighbor<<endl;
    }

    void cycleDetectionDFS(){
        vector<bool> visited(sizeOfGraph, false); 
        int parent = -1;

        for(int node=0; node<sizeOfGraph; node++){
            if(!visited[node]){
                if(cycleDetectionDFSHelper(node, visited, parent)){
                    cout<<"Cycle exists"<<endl;
                    return;
                }
            }
        }

        cout<<"Cycle doesn't exists"<<endl;
    }
};

int main(){
    Graph graph(5);

    graph.buildGraph(0,1);
    graph.buildGraph(1,2);
    // graph.buildGraph(2,0);
    graph.buildGraph(0,3);
    graph.buildGraph(3,4);


    graph.cycleDetectionDFS();

    return 0;
}