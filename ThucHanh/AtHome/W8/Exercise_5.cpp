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
   
    Node* insert(int key){
        return insert(this->root, key);
    }
    
    bool isBST() {
        return isBST(this->root, INT_MIN, INT_MAX);
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
    
    bool isBST(Node* root, int minKey, int maxKey) {
        if (root == nullptr)
            return true;
        if (root->left == nullptr || root->right == nullptr){
            if (!(root->left == nullptr && root->right == nullptr))
                return false;
        }
        // Check if the current node violates the BST property
        if (root->key <= minKey || root->key >= maxKey)
            return false;
    
        // Recursively check the left and right subtrees
        return isBST(root->left, minKey, root->key) && 
                 isBST(root->right, root->key, maxKey);
    }
    
    //Delete memory of root had made before
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
    bst . insert (50) ;
    bst . insert (30) ;
    bst . insert (70) ;
    bst . insert (20) ;
    bst . insert (40) ;
    bst . insert (60) ;
    bst . insert (80) ;
    // bst . insert (45) ;
    
    cout << bst.isBST() << endl;
    return 0;
}


