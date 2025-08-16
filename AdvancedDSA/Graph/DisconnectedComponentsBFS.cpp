#include <iostream>
#include <list>
#include <queue>
#include <vector>
using namespace std;

class Graph{
    //data members
    int sizeOfGraph;
    list<int>* vectorsList;

    //bfs helper method
    void bfsHelper(int startNode, vector<bool> &visited){
        if(visited[startNode]){
            return;
        }

        queue<int> vectorsQueue;
        
        //insert the first node into the queue
        vectorsQueue.push(startNode);

        //loop through until the queue is not empty
        while(!vectorsQueue.empty()){
            int node = vectorsQueue.front();
            vectorsQueue.pop();
            
            //mark the node as visited and print the node
            visited[node] = true;
            cout<<node<<", ";

            //insert the neighbors of the node into the queue
            list<int> neighbors = vectorsList[node];
            
            for(int neighbor : neighbors){
                if(!visited[neighbor]){
                    vectorsQueue.push(neighbor);
                }
            }
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

    //breadth first search main method
    void bfs(){
        vector<bool> visited(sizeOfGraph, false);
        
        for(int i=0; i<sizeOfGraph; i++){
            if(!visited[i]){
                bfsHelper(i, visited);
            }
        }

        cout<<endl<<"Depth First Search Completed!"<<endl;
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

    graph.bfs();

    return 0;
}