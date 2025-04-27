#include <iostream>
using namespace std;

struct Node {
    int key;
    Node* left;
    Node* right;
};



struct Queue{
    Queue() = default;
    ~Queue() {
        while (this->head)
        {
            dequeue();
        }          
    }
        struct queueNode
        {
           Node* node;
           queueNode* next;
        };

        queueNode* createNode(Node*& x) {
            return new queueNode{x, nullptr};
        }

        queueNode* head = nullptr;
        queueNode* tail = nullptr;
   
        void enqueue(Node*& x) {
            queueNode* p = createNode(x);
        
            if (this->head == nullptr) {
                this->head = p;
                this->tail = p;
            }
            else {
                this->tail->next = p;
                this->tail = p;
            }
        }
        
        void dequeue() {
            if (this->head == nullptr) {
                return;
            }
           
            queueNode* p = this->head;
        
            if (this->head == this->tail) {
                this->head = nullptr;
                this->tail = nullptr;
            }
            else {
                this->head = this->head->next;
            }
            delete p;
        }  
        
        bool isEmpty(){
            return (this->head == nullptr);
        }

        

};

struct BST{
    //When init BST
    BST() = default;
    //when disable BST, delete memory
    ~BST() {
        deleteAll(this->root);
    } 

    public:

    //Init Node root for BST
    Node* root = nullptr;
    
    //All interface function

    Node* insert(int key){
        return insert(this->root, key);
    }

    void levelOrder(){
        if (!this->root)
            return;
        levelOrder(this->root);
        cout << "\b\b";
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
  
    //
    void levelOrder(Node* root){
        if (root == nullptr)
            return;
        Queue q;
        q.enqueue(root);
        
        while (!q.isEmpty())
        {   
            Node* current = q.head->node;
            cout << current->key << ", ";
            if (current->left){
                q.enqueue(current->left);
            }
            if (current->right){
                q.enqueue(current->right);
            }
            q.dequeue();
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
    bst.insert(50);
    bst.insert(30);
    bst.insert(70);
    bst.insert(20);
    bst.insert(40);
    bst.insert(60);
    bst.insert(80);
    bst.insert(45);
    
    cout << "Level order traversal: [";
    bst.levelOrder();
    cout << "]" << endl;

    return 0;
}
