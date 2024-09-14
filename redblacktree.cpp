#include <iostream>
using namespace std;

// Define the structure for a node in the Red-Black Tree
struct Node {
    int value;
    Node* left;
    Node* right;
    bool color; // true for red, false for black
    int height;

    // Constructor to initialize the node
    Node(int v) : value(v), left(nullptr), right(nullptr), color(true), height(1) {}
};

// Function to get the height of a subtree rooted at a given node
int getHeight(Node* node) {
    if (node == nullptr) return 0;
    return node->height;
}

// Function to update the height and balance factor of a node
void updateHeight(Node* node) {
    node->height = max(getHeight(node->left), getHeight(node->right)) + 1;
}

// Function to get the balance factor of a subtree rooted at a given node
int getBalanceFactor(Node* node) {
    if (node == nullptr) return 0;
    return getHeight(node->left) - getHeight(node->right);
}

// Function to rotate a Red-Black Tree leftwards around a given node
void rotateLeft(Node*& root, Node* x) {
    Node* y = x->right;
    x->right = y->left;
    if (y->left != nullptr) {
        y->left->parent = x;
    }
    y->parent = x->parent;
    if (x->parent == nullptr) {
        root = y;
    } else if (x == x->parent->left) {
        x->parent->left = y;
    } else {
        x->parent->right = y;
    }
    y->left = x;
    x->parent = y;

    // Update node heights and colors
    updateHeight(x);
    updateHeight(y);
}

// Function to rotate a Red-Black Tree rightwards around a given node
void rotateRight(Node*& root, Node* x) {
    Node* y = x->left;
    x->left = y->right;
    if (y->right != nullptr) {
        y->right->parent = x;
    }
    y->parent = x->parent;
    if (x->parent == nullptr) {
        root = y;
    } else if (x == x->parent->right) {
        x->parent->right = y;
    } else {
        x->parent->left = y;
    }
    y->right = x;
    x->parent = y;

    // Update node heights and colors
    updateHeight(x);
    updateHeight(y);
}

// Function to insert a new value into the Red-Black Tree
void insert(Node*& root, int value) {
    Node* node = new Node(value);

    if (root == nullptr) {
        root = node;
    } else {
        Node* y = nullptr;
        Node* x = root;

        while (x != nullptr) {
            y = x;
            if (value < x->value) {
                x = x->left;
            } else {
                x = x->right;
            }
        }

        node->parent = y;
        if (value < y->value) {
            y->left = node;
        } else {
            y->right = node;
        }
    }

    // Rebalance the tree
    while (getBalanceFactor(root) > 1 || getBalanceFactor(root->left) > 0 && getBalanceFactor(root->left->left) > 0) {
        if (getHeight(root->right) - getHeight(root->left) > 1) {
            if (value < root->left->value) {
                rotateRight(root, root->left);
            } else {
                rotateLeft(root, root->left);
            }
        } else {
            // Left-left case
            if (getHeight(root->left->left) >= getHeight(root->left->right)) {
                rotateRight(root, root);
            } else {
                rotateLeft(root, root->left->left);
                updateHeight(root->left->left->left);
                rotateRight(root, root->left);
                updateHeight(root->left->left);
                updateHeight(root->left);
                rotateRight(root, root->right);
                updateHeight(root->right);
            }
        }

        // Update node heights and colors
        updateHeight(root);
    }

    while (getBalanceFactor(root) > 1 || getBalanceFactor(root->right) > 0 && getBalanceFactor(root->right->left) > 0) {
        if (getHeight(root->left) - getHeight(root->right) > 1) {
            if (value < root->right->value) {
                rotateLeft(root, root->right);
            } else {
                rotateRight(root, root->right);
            }
        } else {
            // Right-right case
            if (getHeight(root->right->right) >= getHeight(root->right->left)) {
                rotateLeft(root, root);
            } else {
                rotateRight(root, root->right->right);
                updateHeight(root->right->right->right);
                rotateLeft(root, root->right);
                updateHeight(root->right->right);
                updateHeight(root->right);
                rotateRight(root, root->left);
                updateHeight(root->left);
            }
        }

        // Update node heights and colors
        updateHeight(root);
    }
}

// Function to print the Red-Black Tree in inorder traversal order
void printTree(Node* root) {
    if (root == nullptr) return;

    printTree(root->left);

    cout << "Node " << root->value << ": Color = ";

    // Print color based on height
    if (root->height == 1) {
        cout << "Black" << endl;
    } else {
        cout << "Red" << endl;
    }

    printTree(root->right);
}

// Example usage:
int main() {
    Node* root = nullptr;

    insert(root, 10);
    insert(root, 5);
    insert(root, 15);
    insert(root, 3);
    insert(root, 7);
    insert(root, 12);

    cout << "Red-Black Tree:" << endl;
    printTree(root);

    return 0;
}
