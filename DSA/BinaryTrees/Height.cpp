#include <iostream>
#include <vector>
#include <queue>
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

    if(lis[idx]==-1) return NULL;

    Node* root = new Node(lis[idx]);

    root->left = buildTree(lis);
    root->right = buildTree(lis);


    return root;
}

void levelOrder(Node* root){
    //step0: initialize queue of Node*
    queue<Node*> q;

    //step1: push root and a NULL into the queue
    q.push(root);
    q.push(NULL);

    //step2: start while loop (until q is not empty)
    while(!q.empty()){
        
        //step3: store front in currNode pointer and pop front
        Node* currNode = q.front();
        q.pop();

        //step6: base case i.e., track end level
        if(!currNode){
            cout<<endl;

            if(q.empty()) break;

            q.push(NULL);
            continue; 
        }

        //step4: print own data
        cout<<currNode->data<<" ";

        //step5: insert children in queue if not null
        if(currNode->left) q.push(currNode->left);
        if(currNode->right) q.push(currNode->right);
    }
}

int heightOfTree(Node* root){
    //base case
    if(!root) return 0;

    //ask left
    int leftHeight = heightOfTree(root->left);

    //ask right
    int rightHeight = heightOfTree(root->right);


    //return ans
    return max(leftHeight, rightHeight) + 1;
}

int main(){
    vector<int> preorder =  {1,2,4,-1,-1,5,-1,6,-1,7,-1,-1,3,-1,-1};

    Node* root = buildTree(preorder);

    levelOrder(root);

    cout<<"The height of this binary tree is "<<heightOfTree(root)<<endl;

    return 0;
}