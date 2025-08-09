#include <iostream>
#include <vector>
#include <list>
#include <queue>
using namespace std;

class Graph{
    //data members
    int sizeOfGraph;
    list<int>* vectorsList;

    public:

    //constructors
    Graph(int sizeOfGraph){
        this->sizeOfGraph = sizeOfGraph;
        this->vectorsList = new list<int> [sizeOfGraph];
    }

    //build graph method
    void buildGraph(int node, int neighbor){
        vectorsList[node].push_back(neighbor);
        vectorsList[neighbor].push_back(node);
        cout<<node<<"---"<<neighbor<<endl;
    }

    //print graph
    void printGraph(){
        for(int i=0; i<sizeOfGraph; i++){
            list<int> neighbors = vectorsList[i];
            cout<<i<<" : ";

            for(int neighbor : neighbors) {
                cout<<neighbor<<", ";
            }

            cout<<endl;
        }
    }

    //breadth first search
    void bfs(){
        queue<int> nodesQueue;
        vector<bool> visited(sizeOfGraph, false);

        //insert first node to the queue
        nodesQueue.push(0);
        visited[0] = true;

        while(nodesQueue.size()>0){
            //print the front node in the queue
            int node = nodesQueue.front();
            nodesQueue.pop();
            cout<<node<<", ";

            //insert the neighbors of the front node in the queue
            list<int> neighbors = vectorsList[node];
            for(int neighbor : neighbors){
                if(visited[neighbor] == false){
                    //insert the neighbor node in the queue
                    nodesQueue.push(neighbor);

                    //mark the neighbor node as visited
                    visited[neighbor] = true;
                }
            }
        }

        cout<<endl;
    }
};

int main(){
    Graph graph(5);
    
    graph.buildGraph(0,1);
    graph.buildGraph(1,2);
    graph.buildGraph(2,3);
    graph.buildGraph(2,4);
    graph.buildGraph(3,1);
    
    // graph.printGraph();
    graph.bfs();

    return 0;
}

