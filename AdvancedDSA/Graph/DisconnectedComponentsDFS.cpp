#include <iostream>
#include <list>
#include <vector>
using namespace std;

class Graph{
    //data members
    int sizeOfGraph;
    list<int>* vectorsList;

    //dfs helper method
    void dfsHelper(int node, vector<bool> &visited){
        //check if the node is already visited, then return control
        if(visited[node]){
            return;
        }

        //mark the node as visited
        cout<<node<<", ";
        visited[node] = true;

        //traverse through its neighbors
        list<int> neighbors = vectorsList[node];
        for(int neighbor : neighbors){
            dfsHelper(neighbor, visited);
        }
    }

    public:

    //constructor
    Graph(int sizeOfGraph){
        this->sizeOfGraph = sizeOfGraph;
        this->vectorsList = new list<int>[sizeOfGraph];
    }

    //build graph method
    void buildGraph(int node, int neighbor){
        vectorsList[node].push_back(neighbor);
        vectorsList[neighbor].push_back(node);
        cout<<node<<"---"<<neighbor<<endl;
    }

    //depth first search
    void dfs(){
        vector<bool> visited(sizeOfGraph, false);
        for(int i=0; i<sizeOfGraph; i++){
            if(!visited[i]){
                dfsHelper(i, visited);
            }
        }
        
        cout<<endl<<"Depth First Search completed for the graph!"<<endl;
    }
};

int main(){
    Graph graph(10);
    graph.buildGraph(0,2);
    graph.buildGraph(2,5);
    graph.buildGraph(1,6);
    graph.buildGraph(6,4);
    graph.buildGraph(4,9);
    graph.buildGraph(4,3);
    graph.buildGraph(3,8);
    graph.buildGraph(3,7);

    graph.dfs();

    return 0;
}