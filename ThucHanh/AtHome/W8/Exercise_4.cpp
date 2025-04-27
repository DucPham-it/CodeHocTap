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

    int height(){
        return height(this->root);
    }

    int depth(int value){
        return depth(this->root, value);
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
    
    //F
    int height(Node* root){
        if (root == nullptr)
            return -1;
        int maxLeft = height(root->left);
        int maxRight = height(root->right);
        return (maxLeft > maxRight) ? maxLeft + 1: maxRight + 1;
    }

    //F
    int depth(Node* root, int value){
        int depth = 0;
        while (root != nullptr){
            if (root->key == value){
                return depth;
            }
            else if (root->key > value){
                root = root->left;
            }
            else{
                root = root->right;
            }
            depth++;
        }
        return -1;
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
    bst . insert (55) ;
    bst . insert (52) ;
    
    cout << bst.height() << endl;
    cout << bst.depth(52) << endl;
    return 0;
}


