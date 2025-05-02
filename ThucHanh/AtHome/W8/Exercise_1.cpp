#include <iostream>
using namespace std;

struct Node {
    int key;
    Node* left;
    Node* right;
};

struct BST{
    public:

    //When init BST
    BST() = default;
    //when disable BST, delete memory
    ~BST() {
        deleteAll(this->root);
    } 

    //Init Node root for BST
    Node* root = nullptr;
    
    //All interface function
    bool search(int key){
        return search(this->root, key);
    }

    Node* insert(int key){
        return insert(this->root, key);
    }

    void levelOrder() {
        if (root == nullptr) return;
        
        // Create a queue for level order traversal
        Node* queue[1000];  // Assuming max 1000 nodes
        int front = 0;
        int rear = 0;
        
        // Enqueue root
        queue[rear++] = root;
        
        while (front < rear) {
            // Dequeue a node and print it
            Node* current = queue[front++];
            cout << current->key << " ";
            
            // Enqueue left child if exists
            if (current->left != nullptr)
                queue[rear++] = current->left;
                
            // Enqueue right child if exists
            if (current->right != nullptr)
                queue[rear++] = current->right;
        }
        cout << endl;
    }

    private:
    //Helper function

    //Make new node
    Node* createNode(int key){
        Node* p = new Node;
        p->key = key;
        p->left = nullptr;
        p->right = nullptr;
        return p;
    }

    //Take key node to BST 
    Node* insert(Node*& root, int key) {
        if (root == nullptr) {
            Node* p = createNode(key);
            root = p;
            return root;
        }
        if (key < root->key)
            return insert(root->left, key);
        else if (key > root->key)   
            return insert(root->right, key);
        return root;
    }

    //Seach key node if possible
    bool search(Node* root, int key) {
        if (root == nullptr){
            return false;
        }
        if (root->key == key)
            return true;
        if (key < root->key)
            return search(root->left, key);
        else
            return search(root->right, key);
    }

    void deleteAll(Node*& root){
        if (root == nullptr){
             return;
        }
     
         deleteAll(root->left);
         deleteAll(root->right);
         
         delete root;
         root = nullptr;    
     }
};

int main(){
    BST bst;
    bst.insert(50);
    bst.insert(30);
    bst.insert(70);
    bst.insert(20);
    bst.insert(40);
    bst.insert(60);
    bst.insert(80);

    cout << "Level Order Traversal: ";
    bst.levelOrder();

    if (bst.search(40))
        cout << "true" << endl;
    else 
        cout << "false" << endl;

    if (bst.search(90))
        cout << "true" << endl;
    else 
        cout << "false" << endl;

    return 0;
}