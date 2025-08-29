#include <iostream>
#include <list>
#include <vector>
#include <string>
using namespace std;

class Graph{
    //data members
    int sizeOfGraph;
    list<int>* nodesList;

    //all path method helper
    void allPathHelper(int src, int dest, vector<bool> &visited, string &path){
        visited[src] = true;
        path += to_string(src);

        if(src == dest){
            cout<<path<<endl;
        }
        else{
            list<int> neighbors = nodesList[src];

            for(int neighbor : neighbors) {
                if(!visited[neighbor]){
                    allPathHelper(neighbor, dest, visited, path);
                }
            }
        }

        visited[src] = false;
        path = path.substr(0, path.size()-1);
    }

    public:

    //constructor
    Graph(int sizeOfGraph){
        this->sizeOfGraph = sizeOfGraph;
        nodesList = new list<int> [sizeOfGraph];
    }

    void buildGraph(int node, int neighbor){
        nodesList[node].push_back(neighbor);
        cout<<node<<"-->"<<neighbor<<endl;
    }

    void allPaths(int src, int dest){
        vector<bool> visited (sizeOfGraph, false);
        string path = "";

        allPathHelper(src, dest, visited, path);
    }
};

int main(){
    Graph graph(6);

    graph.buildGraph(5,2);
    graph.buildGraph(2,3);
    graph.buildGraph(3,1);
    graph.buildGraph(5,0);
    graph.buildGraph(0,3);
    graph.buildGraph(4,0);
    graph.buildGraph(4,1);

    graph.allPaths(5,1);
    
    return 0;
}