#include <iostream>
#include <cmath>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
    int height;
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

Node* newNode(int data);
int height(Node* root);
int balanceFactor(Node* root);
Node* rotateLL(Node* root);
Node* rotateRR(Node* root);
Node* rotateLR(Node* root);
Node* rotateRL(Node* root);
Node* insertNode(Node* root, int data);
Node* searchNode(Node* root, int data);
Node* deleteNode(Node* root, int data);
void NLR(Node* root);
void LNR(Node* root);
void LRN(Node* root);
void LevelOrder(Node* root);
bool isFull(Node* root);
bool isComplete(Node* root);
bool isPerfect(Node* root);
void printSpecialNodes(Node* root);


int main(int argc, char const *argv[])
{
    Node* root = nullptr;

    for (int i = 1; i < 8; i++) {
        cout << "insert to AVL : ";
        int x;
        cin >> x;
        root = insertNode(root, x);
    }

    NLR(root);
    cout << endl;

    cout << "is Full : " << isFull(root) << endl;
    cout << "is complete : " << isComplete(root) << endl;
    cout << "is perpect : " << isPerfect(root) << endl;

    printSpecialNodes(root);

    return 0;
}

Node* newNode(int data){
    return new Node{data, nullptr, nullptr, 1};
}

int height(Node* root){
    if (root == nullptr){
        return 0;
    }
    return root->height;
}

int balanceFactor(Node* root){
    if (root == nullptr){
        return 0;
    }
    return height(root->left) - height(root->right);
}

Node* rotateLL(Node* root){
    Node* x = root->left;
    Node* y = x->right;

    x->right = root;
    root->left = y;

    root->height = max(height(root->left), height(root->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x;
}

Node* rotateRR(Node* root){
    Node* x = root->right;
    Node* y = x->left;

    x->left = root;
    root->right = y;

    root->height = max(height(root->left), height(root->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x;
}

Node* rotateLR(Node* root){
    Node* x = root->left;
    Node* y = x->right;
    
    x->right = y->left;
    root->left = y->right;
    y->left = x;
    y->right = root;

    root->height = max(height(root->left), height(root->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;
    
    return y;
}

Node* rotateRL(Node* root){
    Node* x = root->right;
    Node* y = x->left;
    
    x->left = y->right;
    root->right = y->left;
    y->right = x;
    y->left = root;

    root->height = max(height(root->left), height(root->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;
    
    return y;
}

Node* insertNode(Node* root, int data){
    if (root == nullptr)
            return newNode(data);

        if (data < root->data)
            root->left = insertNode(root->left, data);
        else if (data > root->data)
            root->right = insertNode(root->right, data);
        else
            return root;

        // Update height of this ancestor Node
        root->height = 1
                       + max(height(root->left),
                             height(root->right));

        // Get the balance factor of this ancestor Node
        int balance = balanceFactor(root);

        // If this Node becomes unbalanced, then there are 4
        // cases

        // Left Left Case
        if (balance > 1 && data < root->left->data)
            return rotateLL(root);

        // Right Right Case
        if (balance < -1 && data > root->right->data)
            return rotateRR(root);

        // Left Right Case
        if (balance > 1 && data > root->left->data) {
            return rotateLR(root);
        }

        // Right Left Case
        if (balance < -1 && data < root->right->data) {
            return rotateRL(root);
        }

        return root;
}

Node* searchNode(Node* root, int data){
    if (root == nullptr or root->data == data)
        return root;
    if (root->data < data)
        return searchNode(root->right, data);
    else if (root->data > data)
        return searchNode(root->left, data);
    return nullptr;
}

void NLR(Node* root){
    if (root == nullptr)
        return;
    cout << root->data << " ";
    NLR(root->left);
    NLR(root->right);
}

void LNR(Node* root){
    if (root == nullptr)
        return;
    LNR(root->left);
    cout << root->data << " ";
    LNR(root->right);
}
void LRN(Node* root){
    if (root == nullptr)
        return;
    LRN(root->left);
    LRN(root->right);
    cout << root->data << " ";
}

void LevelOrder(Node* root){
    if (root == nullptr)
        return;
    Queue q;
    q.enqueue(root);
    
    while (!q.isEmpty())
    {   
        Node* current = q.head->node;
        q.dequeue();
        cout << current->data << " ";
        if (current->left){
            q.enqueue(current->left);
        }
        if (current->right){
            q.enqueue(current->right);
        }
    }
}

bool isFull(Node* root){
    if (root == nullptr)
         return true;
    if (root->left == nullptr && root->right == nullptr) {
        return true;
    }
    if (root->left != nullptr && root->right != nullptr) {
        return isFull(root->left) && isFull(root->right);
    }

    return false;    
}

bool isComplete(Node* root){
    if (root == nullptr)
    return true;

    Queue q;
    q.enqueue(root);
    bool foundNullChild = false;

    while (!q.isEmpty()) {
        Node* current = q.head->node;
        q.dequeue();

        if (current->left) {
            if (foundNullChild) return false;
            q.enqueue(current->left);
        } else {
            foundNullChild = true;
        }

        if (current->right) {
            if (foundNullChild) return false;
            q.enqueue(current->right);
        } else {
            foundNullChild = true;
        }
    }
    return true;
}       

int findDepth(Node* node) {
    int d = 0;
    while (node != nullptr) {
        d++;
        node = node->left;
    }
    return d;
}

bool isPerfectUtil(Node* root, int depth, int level = 1) {
    if (root == nullptr)
        return true;

    if (root->left == nullptr && root->right == nullptr)
        return (depth == level);

    if (root->left == nullptr || root->right == nullptr)
        return false;

    return isPerfectUtil(root->left, depth, level + 1) && isPerfectUtil(root->right, depth, level + 1);
}

bool isPerfect(Node* root) {
    int depth = findDepth(root);
    return isPerfectUtil(root, depth);
}

void printSpecialNodes(Node* root){
    if (root == nullptr)
        return;
    
    printSpecialNodes(root->left);
    if (root->left != nullptr && root->right != nullptr){
        if (root->right->data % root->left->data == 0)
            cout << root->data << " ";
    }
    printSpecialNodes(root->right);
}

