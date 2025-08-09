#include <iostream>
#include <list>
#include <vector>
using namespace std;

class Graph{
    //@param : sizeOfGraph
    //@description : defines the number of nodes in the graph
    int sizeOfGraph;

    //@param : vectorsList
    //@description : a pointer to list representing the nodes and their respective neighbors
    list<int>* vectorsList;

    //@method_name : dfsHelper
    //@description : private helper method for dfs
    void dfsHelper(int node, vector<bool> &visited){
            //base case : if node is alredy visited then return control
            if(visited[node] == true){
                return;
            }

            //print the node and mark it as visited
            cout<<node<<", ";
            visited[node] = true;

            //traverse through first unvisited neighbor
            list<int> neighbors = vectorsList[node];
            for(int neighbor : neighbors){
                dfsHelper(neighbor, visited);
            }
        }

    public:

    //@method_name : Graph
    //@description : parameterized constructor for the class Graph
    Graph(int sizeOfGraph){
        this->sizeOfGraph = sizeOfGraph;
        this->vectorsList = new list<int> [sizeOfGraph];
    }

    //@method_name : buildGraph
    //@description : adds undirected and unweighted edge between the nodes passed as parameters with the method
    void buildGraph(int node, int neighbor){
        vectorsList[node].push_back(neighbor);
        vectorsList[neighbor].push_back(node);
        cout<<node<<"---"<<neighbor<<endl;
    }

    //@method_name : dfs
    //@description : graph traversal - depth first search (dfs)
    void dfs(){
        vector<bool> visited(sizeOfGraph, false);
        int firstNode = 0;
        dfsHelper(firstNode, visited);
        cout<<endl<<"depth first search traversal completed!"<<endl;
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
    graph.buildGraph(4,5);

    
    // graph.printGraph();
    graph.dfs();
    return 0;
}