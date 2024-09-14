#include <iostream>

using namespace std;

// Node structure for the binary tree
struct Node {
    int data;
    Node* left;
    Node* right;
};

// Function to create a new node
Node* newNode(int data) {
    Node* node = new Node;
    node->data = data;
    node->left = node->right = nullptr;
    return node;
}

// Function to print the tree (in-order traversal)
void inorderTraversal(Node* root) {
    if (root != nullptr) {
        inorderTraversal(root->left); // Recursively traverse left subtree
        cout << root->data << " ";  // Print current node's data
        inorderTraversal(root->right); // Recursively traverse right subtree
    }
}

int main() {
    Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);

    cout << "Inorder traversal: ";
    inorderTraversal(root);
    cout << endl;

    return 0;
}
