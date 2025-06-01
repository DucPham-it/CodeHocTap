#include <iostream>
#include <vector>
#include <algorithm>

// AVL Tree Node
struct Node {
    int val;
    Node* left;
    Node* right;
    int height;

    // Constructor
    Node(int v) : val(v), left(nullptr), right(nullptr), height(1) {}
};

// TODO : Function to get the height of a node
int getHeight(Node* node) {
    if (!node) return 0;
    return node->height;
}

// TODO : Function to calculate the balance factor of a node
int getBalanceFactor(Node* node) {
    if (!node) return 0;
    return getHeight(node->left) - getHeight(node->right);
}

// TODO : Right rotation
Node* rightRotate(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = std::max(getHeight(y->left), getHeight(y->right)) + 1;
    x->height = std::max(getHeight(x->left), getHeight(x->right)) + 1;

    return x;
}

// TODO : Left rotation
Node* leftRotate(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = std::max(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = std::max(getHeight(y->left), getHeight(y->right)) + 1;

    return y;
}

// TODO : Insert a node into the AVL tree
Node* insert(Node* node, int val) {
    if (!node) return new Node(val);

    if (val < node->val)
        node->left = insert(node->left, val);
    else if (val > node->val)
        node->right = insert(node->right, val);
    else
        return node; // No duplicates

    // Update height
    node->height = std::max(getHeight(node->left), getHeight(node->right)) + 1;

    // Get balance factor
    int balance = getBalanceFactor(node);

    // Balance cases
    if (balance > 1 && val < node->left->val)
        return rightRotate(node);

    if (balance < -1 && val > node->right->val)
        return leftRotate(node);

    if (balance > 1 && val > node->left->val) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    if (balance < -1 && val < node->right->val) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

// TODO : Find the path from root to a node with given value
bool findPath(Node* root, int val, std::vector<int>& path) {
    if (!root) return false;

    path.push_back(root->val);

    if (root->val == val) return true;

    if ((val < root->val && findPath(root->left, val, path)) ||
        (val > root->val && findPath(root->right, val, path)))
        return true;

    path.pop_back(); 
    return false;
}

// TODO : Find the Lowest Common Ancestor (LCA ) of two nodes
int findLCA(Node* root, int p, int q) {
    std::vector<int> pathP, pathQ;

    if (!findPath(root, p, pathP) || !findPath(root, q, pathQ))
        return -1; 

    int i = 0;
    while (i < pathP.size() && i < pathQ.size() && pathP[i] == pathQ[i])
        i++;

    return pathP[i - 1]; 
}

// TODO : Utility function to free the memory
void deleteTree(Node* root) {
    if (!root) return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

int main() {
    // Read input
    int n;
    std::cin >> n;

    std::vector<int> values(n);
    for (int i = 0; i < n; i++) {
        std::cin >> values[i];
    }

    int p, q;
    std::cin >> p >> q;

    // Build AVL tree
    Node* root = nullptr;
    for (int val : values) {
        root = insert(root, val);
    }

    // Find and output the LCA
    int lca = findLCA(root, p, q);
    std::cout << lca << std::endl;

    // Clean up
    deleteTree(root);

    return 0;
}
