// ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⠤⠒⠈⠉⠉⠉⠉⠒⠀⠀⠤⣀⠀⠀⠀⠀
// ⠀⠀⠀⠀⠀⠀⠀⠀⠀⣰⠁⠀⠀⠀⠀⠀⠀⢀⣄⠀⠀⠀⠀⠑⡄⠀⠀
// ⠀⠀⠀⠀⠀⠀⠀⠀⠰⠿⠿⠿⠣⣶⣿⡏⣶⣿⣿⠷⠶⠆⠀⠀⠘⠀
// ⠀⠀⠀⠀⠀⠀⠠⠴⡅⠀⠀⠠⢶⣿⣿⣷⡄⣀⡀⡀⠀⠀⠀⠀⠀⡇⠀
// ⠀⣰⡶⣦⠀⠀⠀⡰⠀⠀⠸⠟⢸⣿⣿⣷⡆⠢⣉⢀⠀⠀⠀⠀⠀⠀⠀⠀
// ⠀⢹⣧⣿⣇⠀⠀⡇⠀⢠⣷⣲⣺⣿⣿⣇⠤⣤⣿⣿⠀⢸⠀⣤⣶⠦⠀⠀
// ⠀⠀⠙⢿⣿⣦⡀⢇⠀⠸⣿⣿⣿⣿⣿⣿⣿⣿⣿⠇⠀⡜⣾⣿⡃⠇⢀⣤⡀⠀
// ⠀⠀⠀⠀⠙⢿⣿⣮⡆⠀⠙⠿⣿⣿⣾⣿⡿⡿⠋⢀⠞⢀⣿⣿⣿⣿⣿⡟⠁
// ⠀⠀⠀⠀⠀⠀⠛⢿⠇⣶⣤⣄⢀⣰⣷⣶⣿⠁⡰⢃⣴⣿⡿⢋⠏⠉⠁⠀⠀⠀
// ⠀⠀⠀⠀⠀⠀⠀⠠⢾⣿⣿⣿⣞⠿⣿⣿⢿⢸⣷⣌⠛⠋⠀⠘⠀⠀⠀⠀
// ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠙⠙⣿⣿⣿⣶⣶⣿⣯⣿⣿⣿⣆⠀⠇
// TRY TO FIX BUG TODAY, BECOME A NICE CODER TOMORROW !!!


//24120041 - Pham Vo Duc

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

struct Queue {
    Node* head;
    Node* tail;
    int capacity;
};

Node* createNode(int x);
int countNode(Node* head);
void insertTail(Node*& head, int x);
void insertHead(Node*& head, int x);
void deleteHead(Node*& head);
void deleteTail(Node*& head);
void deleteAll(Node*& head);
void printLinkedList(Node* head);
void removeDuplicatedNodes(Node*& head);

void init(Queue& s, int capacity);
void enqueue(Queue& s, int x);
void dequeue(Queue& s);
int front(Queue s);

int main(int argc, char const *argv[]) {
    Queue q;
    init(q, 5);

    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);
    printLinkedList(q.head);

    dequeue(q);
    enqueue(q, 40);
    enqueue(q, 50);
    enqueue(q, 60);
    printLinkedList(q.head);
    cout << "Front : " << front(q) << endl;
    return 0;
}

Node* createNode(int x) {
    return new Node{x, nullptr};
}

int countNode(Node* head) {
    int count = 0;
    while (head) {
        count++;
        head = head->next;
    }
    return count;
}

void insertTail(Node*& head, int x) {
    Node* newNode = createNode(x);
    if (!head) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next) temp = temp->next;
    temp->next = newNode;
}

void insertHead(Node*& head, int x) {
    Node* newNode = createNode(x);
    newNode->next = head;
    head = newNode;
}

void deleteHead(Node*& head) {
    if (!head) return;
    Node* temp = head;
    head = head->next;
    delete temp;
}

void deleteTail(Node*& head) {
    if (!head) return;
    if (!head->next) {  
        delete head;
        head = nullptr;
        return;
    }
    Node* temp = head;
    while (temp->next->next) temp = temp->next;
    delete temp->next;
    temp->next = nullptr;
}

void deleteAll(Node*& head) {
    while (head) {
        deleteHead(head);
    }
}

void printLinkedList(Node* head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

void removeDuplicatedNodes(Node*& head) {
    if (!head) return;

    Node* slow = head;
    while (slow) {
        Node* fast = slow;
        while (fast->next) {
            if (fast->next->data == slow->data) {
                Node* duplicate = fast->next;
                fast->next = fast->next->next;
                delete duplicate;
            } else {
                fast = fast->next;
            }
        }
        slow = slow->next;
    }
}

void init(Queue& s, int capacity) {
    s.capacity = capacity;
    s.head = nullptr;
    s.tail = nullptr;
}

void enqueue(Queue& s, int x) {
    if (countNode(s.head) == s.capacity){
        cout << "Queue is full!" << endl;
        return;
    }
    Node* p = createNode(x);

    if (s.head == nullptr) {
        s.head = p;
        s.tail = p;
    }
    else {
        s.tail->next = p;
        s.tail = p;
    }
}

void dequeue(Queue& s) {
    if (s.head == nullptr) {
        cout << "Queue is empty!" << endl;
        return;
    }
   
    Node* p = s.head;

    if (s.head == s.tail) {
        s.head = nullptr;
        s.tail = nullptr;
    }
    else {
        s.head = s.head->next;
    }
    delete p;
}
int front(Queue s)
{
    if (s.head == nullptr) {
        cout << "Queue is empty!" << endl;
        return -1;
    }
    return s.head->data;
}
