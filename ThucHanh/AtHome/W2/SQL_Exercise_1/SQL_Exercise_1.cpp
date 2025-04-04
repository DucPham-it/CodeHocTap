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

Node* createNode(int x);
int countNode(Node* head);
void insertTail(Node*& head, int x);
void insertHead(Node*& head, int x);
void deleteHead(Node*& head);
void deleteTail(Node*& head);
void deleteAll(Node*& head);
void printLinkedList(Node* head);
void removeDuplicatedNodes(Node*& head);

int main(int argc, char const *argv[]) {
    Node* head = nullptr;

    while (true) {
        int x;
        cout << "Insert x (0 to stop): ";
        cin >> x;
        if (x == 0) break;
        insertTail(head, x);
    }

    cout << "Num Node: " << countNode(head) << endl;
    insertHead(head, 5);
    printLinkedList(head);
    deleteTail(head);
    printLinkedList(head);
    deleteHead(head);
    printLinkedList(head);
    removeDuplicatedNodes(head);
    printLinkedList(head);
    deleteAll(head);

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