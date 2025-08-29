#include <iostream>
#include <list>
#include <vector>
#include <stack>
using namespace std;

class Graph{
    //data members
    int sizeOfGraph;
    list<int>* nodesList;

    void topoSortHelper(int node, vector<bool> &visited, stack<int> &nodesStack){
        if(visited[node]){
            return;
        }

        visited[node] = true;
 
        list<int> neighbors = nodesList[node];

        for(int neighbor : neighbors){
            topoSortHelper(neighbor, visited, nodesStack);
        }

        nodesStack.push(node);
    }

    public:

    Graph(int sizeOfGraph){
        this->sizeOfGraph = sizeOfGraph;
        this->nodesList = new list<int> [sizeOfGraph];
    }

    void buildDirectedGraph(int node, int neighbor) {
        nodesList[node].push_back(neighbor);
        cout<<node<<"-->"<<neighbor<<endl;
    }

    void topoSort(){
        vector<bool> visited(sizeOfGraph, false);
        stack<int> nodesStack;

        for(int node=0; node<sizeOfGraph; node++){
            if(!visited[node]){ 
                topoSortHelper(node, visited, nodesStack);
            }
        }

        while(!nodesStack.empty()){
            cout<<nodesStack.top()<<endl;
            nodesStack.pop();
        }
    }
};

int main(){
    Graph graph(6);

    graph.buildDirectedGraph(5,0);
    graph.buildDirectedGraph(5,2);
    graph.buildDirectedGraph(2,3);
    graph.buildDirectedGraph(3,1);
    graph.buildDirectedGraph(4,0);
    graph.buildDirectedGraph(4,1);

    graph.topoSort();

    return 0;
}