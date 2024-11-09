#include <iostream>
#include <vector>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;

    //constructor
    Node(int data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

static int idx = -1;

Node* buildTree(vector<int> &lis){
    idx++;

    if(lis[idx] == -1) return NULL;

    Node* root = new Node(lis[idx]);

    root->left = buildTree(lis);
    root->right = buildTree(lis);


    return root;
}

Node* getLCA(Node* root, int node1, int node2){
    if(!root) return NULL;

    if(root->data == node1 || root->data == node2) return root;

    Node* left = getLCA(root->left, node1, node2);
    Node* right = getLCA(root->right, node1, node2);

    
    //case 1
    if(!left && !right) return NULL;

    //case 2
    else if(!left && right) return right;

    //case 3
    else if(left && !right) return left;

    //case 4
    else return root;
}

int distance(Node* root, int node){
    if(!root) return -1;

    if(root->data == node) return 0;

    int left = distance(root->left, node);
    int right = distance(root->right, node);

    if(left >= 0) return left + 1;
    else if(right >= 0) return right + 1;
}

int minDistBtwNodes(Node* root, int node1, int node2){
    if(!root) return -1;

    if(node1 == node2) return 0;

    Node* lca = getLCA(root, node1, node2);

    int dist1 = distance(lca, node1);
    int dist2 = distance(lca, node2);

    return dist1 + dist2;
}

int main(){
    vector<int> lis = {1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
    Node* root = buildTree(lis);
    cout<<minDistBtwNodes(root, 5, 3);
    return 0;
}