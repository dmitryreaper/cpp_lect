#include <iostream>

// Define the structure for a node in the binary tree
struct Node {
    int value;
    Node* left;
    Node* right;

    // Constructor to initialize the node
    Node(int v) : value(v), left(nullptr), right(nullptr) {}
};

// Function to print the binary tree using inorder traversal (left-root-right)
void printTree(Node* root) {
    if (root == nullptr) return; // Base case: empty tree

    // Recursively print the left subtree
    printTree(root->left);

    // Print the current node's value
    std::cout << root->value << " ";

    // Recursively print the right subtree
    printTree(root->right);
}

// Example usage:
int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    std::cout << "Binary Tree: ";
    printTree(root); // Output: 4 2 5 1 3

    return 0;
}
