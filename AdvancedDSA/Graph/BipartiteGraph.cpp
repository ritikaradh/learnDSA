#include <iostream>
#include <queue>
#include <list>
using namespace std;

class Graph {
    //data members
    int sizeOfGraph;
    list<int>* nodesList;

    //bipartite graph helper method
    bool isBipartiteGraphHelper(int node, vector<bool> &visited, queue<int> &nodesQueue, vector<int> &color){
        nodesQueue.push(node);
        visited[node] = true;
        color[node] = 0; // 0->red, 1->black

        while(!nodesQueue.empty()){
            int currNode = nodesQueue.front();
            // cout<<currNode<<", ";
            nodesQueue.pop();

            list<int> neighbors = nodesList[currNode];

            for(int neighbor : neighbors){
                if(!visited[neighbor]){
                    nodesQueue.push(neighbor);
                    visited[neighbor] = true;
                    color[neighbor] = color[currNode] == 0 ? 1 : 0;
                }else if(color[currNode] == color[neighbor]){
                    return false;
                }
            }
        }

        cout<<endl;
        return true;
    }

    public:

    //constructor
    Graph(int sizeOfGraph){
        this->sizeOfGraph = sizeOfGraph;
        this->nodesList = new list<int> [sizeOfGraph];
    }

    //build graph method
    void buildGraph(int node, int neighbor){
        nodesList[node].push_back(neighbor);
        nodesList[neighbor].push_back(node);

        cout<<node<<"---"<<neighbor<<endl;
    }

    //check if the graph is bipartite
    void isBipartiteGraph(){
        vector<bool> visited(sizeOfGraph, false);
        vector<int> color(sizeOfGraph, -1);
        queue<int> nodesQueue;

        for(int node=0; node<sizeOfGraph; node++){
            if(!visited[node] && !isBipartiteGraphHelper(node, visited, nodesQueue, color)){
                cout<<endl<<"Not bipartite graph"<<endl;
                return;
            }
        }

        cout<<endl<<"Bipartite Graph"<<endl;
    }


};

int main(){
    Graph graph_1(4);

    graph_1.buildGraph(0,1);
    graph_1.buildGraph(1,2);
    graph_1.buildGraph(2,3);
    graph_1.buildGraph(3,0);

    graph_1.isBipartiteGraph();
    cout<<endl<<endl;


    Graph graph_2(5);

    graph_2.buildGraph(0,1);
    graph_2.buildGraph(1,3);
    graph_2.buildGraph(3,4);
    graph_2.buildGraph(4,2);
    graph_2.buildGraph(2,0);

    graph_2.isBipartiteGraph();
    cout<<endl<<endl;

    return 0;
}