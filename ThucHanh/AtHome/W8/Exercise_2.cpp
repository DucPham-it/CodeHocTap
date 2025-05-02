#include <iostream>
using namespace std;

struct Node {
    int key;
    Node* left;
    Node* right;
};

struct Stack {
    Stack() = default;
    ~Stack(){
        while (this->head)
        {
            pop();
        }
        
    }

    struct stackNode{
        Node* data = nullptr;
        stackNode* next = nullptr;
    };

    stackNode* creatNode(Node*& x){
        return new stackNode{x, nullptr};
    }

    stackNode* head = nullptr;

    void push(Node*& x){
        if (this->head == nullptr){
            stackNode* p = creatNode(x);
            this->head = p;
        }
        else{
            stackNode* p = creatNode(x);
            p->next = this->head;
            this->head = p;
        }
    }

    void pop(){
        if (this->head == nullptr){
            return;
        }
        stackNode* p = this->head;
        this->head = this->head->next;
        delete p;
    }

    bool isEmpty(){
        return (this->head == nullptr);
    }

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

    void InOrder(){
        if (!this->root)
            return;
        InOrder(this->root);
        cout <<"\b\b";
    }
    void PreOrder(){
        if (!this->root)
            return;
        PreOrder(this->root);
        cout <<"\b\b";
    }
    void PostOrder(){
        if (!this->root)
            return;
        PostOrder(this->root);
        cout <<"\b\b";
    }

    void InOrderIterative(){
        if (!this->root)
            return;
        InOrderIterative(this->root);
        cout <<"\b\b";
    }
    void PreOrderIterative(){
        if (!this->root)
            return;
        PreOrderIterative(this->root);
        cout <<"\b\b";
    }
    void PostOrderIterative(){
        if (!this->root)
            return;
        PostOrderIterative(this->root);
        cout <<"\b\b";
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

    //Visit current node, left subtree, then right subtree and print out
    void PreOrder(Node* root){
        if (root == nullptr) {
            return;
        }
        cout << root->key << ", ";
        PreOrder(root->left);
        PreOrder(root->right);
    }
    
    //Visit left subtree, current node, then right subtree
    void InOrder(Node* root) {
        if (root == nullptr) {
            return;
        }
        InOrder(root->left);
        cout << root->key << ", ";
        InOrder(root->right);
    }
    
    //Visit left subtree, right subtree, then current node and print out
    void PostOrder(Node* root){
        if (root == nullptr){
            return;
        }
        PostOrder(root->left);
        PostOrder(root->right);
        cout << root->key << ", ";
    }

    //Visit current node, left subtree, then right subtree and print out
    void PreOrderIterative(Node* root){
        Stack s;
        s.push(root);

        while (!s.isEmpty())
        {
            Node* current = s.head->data;
            cout << current->key << ", ";
            s.pop();

            if (current->right){
                s.push(current->right);
            }
            if (current->left){
                s.push(current->left);
            }
        }       
    }
   
    //Visit left subtree, current node, then right subtree and print out
    void InOrderIterative(Node* root) {
        Stack st;
        Node* current = root;

        while (current != nullptr || !st.isEmpty()) {
            while (current != nullptr) {
                st.push(current);
                current = current->left;
            }
    
            current = st.head->data;
            st.pop();
    
            cout << current->key << ", ";
    
            current = current->right;
        }
    }
    
    //Visit left subtree, right subtree, then current node and print out
    void PostOrderIterative(Node* root){
        Stack s, v;
        
        s.push(root);

        while (!s.isEmpty())
        {
            Node* current = s.head->data;
            s.pop();
            v.push(current);

            if (current->left){
                s.push(current->left);
            }
            if (current->right){
                s.push(current->right);
            }
        }

        while (!v.isEmpty())
        {   
            Node* current = nullptr;
            if (v.head != nullptr)
                current = v.head->data;
            v.pop();
            if (current != nullptr){
            cout << current->key << ", ";
            }
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

    cout << "In-order traversal: ["; 
    bst.InOrder();
    cout << "]" << endl;
    cout << "Pre-order traversal: [";
    bst.PreOrder();
    cout << "]" << endl;
    cout << "Post-order traversal: [";
    bst.PostOrder();
    cout << "]" << endl;

    cout << "Iterative in-order traversal: [";
    bst.InOrderIterative();
    cout << "]" << endl;

    cout << "Iterative pre-order traversal: [";
    bst.PreOrderIterative();
    cout << "]" << endl;


    return 0;
}

