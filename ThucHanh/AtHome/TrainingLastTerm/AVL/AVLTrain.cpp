#include <iostream>
#include <cmath>
#include <queue>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    int height;
};

class AVLTree {
private:
    Node* root;

    int height(Node* node) {
        return node ? node->height : 0;
    }

    int balanceFactor(Node* node) {
        return node ? height(node->left) - height(node->right) : 0;
    }

    Node* rotateLL(Node* root){
        
    }
    Node* rotateRR(Node* root);
    Node* rotateLR(Node* root);
    Node* rotateRL(Node* root);
    Node* insertNode(Node* root, int data);
    Node* deleteNode(Node* root, int data);
    Node* searchNode(Node* root, int data);
    Node* minValueNode(Node* root);
    void inorder(Node* node);
    void preorder(Node* node);  
    void postorder(Node* node);
    void levelOrder(Node* node);

public:
    AVLTree() : root(nullptr) {}

    void insert(int data) {
        root = insertNode(root, data);
    }

    void remove(int data) {
        root = deleteNode(root, data);
    }

    bool search(int data) {
        return searchNode(root, data) != nullptr;
    }

    void inorder() {
        inorder(root);
        cout << endl;
    }

    void preorder() {
        preorder(root);
        cout << endl;
    }

    void postorder() {
        postorder(root);
        cout << endl;
    }

    void levelOrder() {
        levelOrder(root);
        cout << endl;
    }
};