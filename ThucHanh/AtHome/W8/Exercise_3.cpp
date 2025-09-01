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

    bool remove(int key){
        return (remove(this->root, key));
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

    //Find the most left of node->right
    Node* minValueNode(Node*& node){
        if (node == nullptr)
            return node;
        if (node->left != nullptr)
            return minValueNode(node->left);
        return node;
    }
    
    //Delete key if possible
    bool remove(Node*& root, int key){
        if (root ==  nullptr)
            return false;
        if (key < root->key)
            return remove(root->left, key);
        else if (key > root->key)
            return remove(root->right, key);
        else{
            if (root->left == nullptr){
                Node* temp = root->right;
                delete root;
                root = temp;
                return true;
            }
            else if (root->right == nullptr){
                Node* temp = root->left;
                delete root;
                root = temp;
                return true;
            }
    
            Node* temp = minValueNode(root->right);
            root->key = temp->key;
            return remove(root->right, temp->key);
        }
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

    cout << bst.remove(10); 
    cout << bst.remove(70); 

    return 0;
}

