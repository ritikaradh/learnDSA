#include <iostream>
#include <list>
#include <vector>
using namespace std;

class Graph{
    //data members
    int sizeOfGraph;
    list<int>* vectorsList;

    //has path helper method
    bool hasPathHelper(int srcNode, int destNode, vector<bool> &visited){
        if(visited[srcNode]){
            return false;
        }

        if(srcNode == destNode){
            return true;
        }

        //mark the node as visited and call its neighbor nodes
        visited[srcNode] = true;

        list<int> neighbors = vectorsList[srcNode];

        for(int neighbor : neighbors){
            cout<<neighbor<<", ";
            if(hasPathHelper(neighbor, destNode, visited)){
                return true;
            }
        }

        //if destination node is not found then return false
        return false;
    }

    public:

    //constructor
    Graph(int sizeOfGraph){
        this->sizeOfGraph = sizeOfGraph;
        this->vectorsList = new list<int> [sizeOfGraph];
    }

    //build graph method
    void buildGraph(int node, int neighbor){
        vectorsList[node].push_back(neighbor);
        vectorsList[neighbor].push_back(node);
        // cout<<node<<"---"<<neighbor<<endl;
    }

    //has path problem method
    void hasPath(int srcNode, int destNode){
        vector<bool> visited(sizeOfGraph, false);
        if(hasPathHelper(srcNode, destNode, visited)){
            cout<<endl<<"Path exists"<<endl;
        }
        else{
            cout<<endl<<"Path not exists"<<endl;
        }
    }
};

int main(){
    Graph graph(7);

    graph.buildGraph(0,1);
    graph.buildGraph(1,3);
    graph.buildGraph(3,5);
    graph.buildGraph(5,6);
    graph.buildGraph(0,2);
    graph.buildGraph(2,4);
    graph.buildGraph(4,3);
    graph.buildGraph(4,5);

    graph.hasPath(1,6);

    return 0;
}