#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    // Constructor
    Node(int data) {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

// Helper function to perform in-order traversal and store elements in a vector
void inOrderTraversal(Node* root, vector<int>& arr) {
    if (!root) return;
    inOrderTraversal(root->left, arr);
    arr.push_back(root->data);
    inOrderTraversal(root->right, arr);
}

// Function to find pairs with a given sum using the two-pointer technique
bool findPairsWithSum(const vector<int>& arr1, const vector<int>& arr2, int target, vector<pair<int, int>>& pairs) {
    int i = 0; // Pointer for arr1
    int j = arr2.size() - 1; // Pointer for arr2

    bool found = false;

    while (i < arr1.size() && j >= 0) {
        int sum = arr1[i] + arr2[j];
        if (sum == target) {
            pairs.push_back({arr1[i], arr2[j]});
            found = true;
            i++;
            j--; // Move both pointers
        } else if (sum < target) {
            i++; // Move the pointer in arr1 forward
        } else {
            j--; // Move the pointer in arr2 backward
        }
    }

    return found;
}

int main() {
    // First BST
    Node* root1 = new Node(5);
    root1->left = new Node(3);
    root1->right = new Node(7);
    root1->left->left = new Node(2);
    root1->left->right = new Node(4);
    root1->right->left = new Node(6);
    root1->right->right = new Node(8);

    // Second BST
    Node* root2 = new Node(10);
    root2->left = new Node(6);
    root2->right = new Node(15);
    root2->left->left = new Node(3);
    root2->left->right = new Node(8);
    root2->right->left = new Node(11);
    root2->right->right = new Node(18);

    // Store in-order traversal of both BSTs
    vector<int> arr1, arr2;
    inOrderTraversal(root1, arr1);
    inOrderTraversal(root2, arr2);

    // Find pairs with the given sum
    vector<pair<int, int>> pairs;
    int target = 16;
    bool hasPairs = findPairsWithSum(arr1, arr2, target, pairs);

    // Output result
    cout << (hasPairs ? "Pairs found:" : "No pairs found") << endl;
    for (auto p : pairs) {
        cout << p.first << ", " << p.second << endl;
    }

    return 0;
}
