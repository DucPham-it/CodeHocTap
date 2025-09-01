#include <iostream>
#include <vector>
#include <queue> // For level order traversal

// Tree Node
struct Node {
    int key;
    Node* left;
    Node* right;

    // Constructor
    Node(int k) : key(k), left(nullptr), right(nullptr) {}
};

// TODO : Building tree function
// Hint : Use recursive approach with start and end indices
Node* createPerfectBST(const std::vector<int>& sortedKeys, int start, int end) {
    if (start > end) return nullptr;
    int mid = start + (end - start) / 2;
    Node* node = new Node(sortedKeys[mid]);
    node->left = createPerfectBST(sortedKeys, start, mid - 1);
    node->right = createPerfectBST(sortedKeys, mid + 1, end);
    return node;
}

// Wrapper function
Node* createPerfectBST(const std::vector<int>& sortedKeys) {
    return createPerfectBST(sortedKeys, 0, sortedKeys.size() - 1);
}

// TODO : Traversal tree functions
void preorderTraversal(Node* root) {
    if (!root) return;
    std::cout << root->key << " ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

void inorderTraversal(Node* root) {
    if (!root) return;
    inorderTraversal(root->left);
    std::cout << root->key << " ";
    inorderTraversal(root->right);
}

void postorderTraversal(Node* root) {
    if (!root) return;
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    std::cout << root->key << " ";
}

void levelOrderTraversal(Node* root) {
    if (!root) return;
    std::queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
         int levelSize = q.size();

        for (int i = 0; i < levelSize; i++) {
            Node* node = q.front(); q.pop();
            std::cout << node->key << " ";

            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
        std::cout << std::endl; 
    }
}

// TODO : Search function
bool search(Node* root, int key, std::vector<int>& comparisons) {
    if (!root) return false;
    comparisons.push_back(root->key);
    if (key == root->key) return true;
    if (key < root->key) return search(root->left, key, comparisons);
    return search(root->right, key, comparisons);
}

// TODO : Free tree function
void deleteTree(Node* root) {
    if (!root) return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

// TODO : Binary search function for comparison
bool binarySearch(const std::vector<int>& arr, int key, std::vector<int>& comparisons) {
    int left = 0, right = arr.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        comparisons.push_back(arr[mid]);
        if (arr[mid] == key) return true;
        if (key < arr[mid]) right = mid - 1;
        else left = mid + 1;
    }
    return false;
}

int main() {
    std::vector<int> sortedKeys = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
    Node* root = createPerfectBST(sortedKeys);

    std::cout << "Inorder Traversal : ";
    inorderTraversal(root);
    std::cout << std::endl;

    std::cout << "Postoder Traversal : ";
    postorderTraversal(root);
    std::cout << std::endl;

    std::cout << "Preoder Traversal : ";
    preorderTraversal(root);
    std::cout << std::endl;

    std::cout << "Level Order Traversal :" << std::endl;
    levelOrderTraversal(root);

    int testKey = 7;

    std::vector<int> bstComparisons;
    bool foundInBST = search(root, testKey, bstComparisons);

    std::vector<int> binarySearchComparisons;
    bool foundInArray = binarySearch(sortedKeys, testKey, binarySearchComparisons);

    std::cout << "\nSearch for key " << testKey << ":" << std::endl;

    std::cout << "BST search comparisons : ";
    for (int comp : bstComparisons) {
        std::cout << comp << " ";
    }
    std::cout << std::endl;

    std::cout << "Binary search comparisons : ";
    for (int comp : binarySearchComparisons) {
        std::cout << comp << " ";
    }
    std::cout << std::endl;

    deleteTree(root);

    return 0;
}
