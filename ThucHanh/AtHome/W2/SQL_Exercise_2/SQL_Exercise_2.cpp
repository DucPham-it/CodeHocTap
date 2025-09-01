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

struct Stack {
    Node* head;
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

void init(Stack& s, int capacity);
void push(Stack& s, int x);
void pop(Stack& s);
int top (Stack s);

int main(int argc, char const *argv[]) {
    Stack s;
	init(s, 10);

	push(s, 1);
	push(s, 2);
	push(s, 3);
	push(s, 4);
	push(s, 5);

	pop(s);
    cout << top(s) << endl;
    
    return 0;
}

Node* createNode(int x) 
{
    return new Node{x, nullptr};
}

int countNode(Node* head) 
{
    int count = 0;
    while (head) {
        count++;
        head = head->next;
    }
    return count;
}

void insertTail(Node*& head, int x) 
{
    Node* newNode = createNode(x);
    if (!head) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next) temp = temp->next;
    temp->next = newNode;
}

void insertHead(Node*& head, int x) 
{
    Node* newNode = createNode(x);
    newNode->next = head;
    head = newNode;
}

void deleteHead(Node*& head) 
{
    if (!head) return;
    Node* temp = head;
    head = head->next;
    delete temp;
}

void deleteTail(Node*& head) 
{
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

void deleteAll(Node*& head) 
{
    while (head) {
        deleteHead(head);
    }
}

void printLinkedList(Node* head)
 {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

void removeDuplicatedNodes(Node*& head) 
{
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

void init(Stack& s, int capacity) 
{
	s.head = nullptr;
	s.capacity = capacity;
}

void push(Stack& s, int x) 
{	
	if (countNode(s.head) == s.capacity) {
		cout << "Stack is full. Can not push!" << endl;
		return;
	}
	insertHead(s.head, x);	
}

void pop(Stack& s) 
{
	if (s.head == nullptr) {
		cout << "Stack is empty. Can not pop!" << endl;
		return;
	}

	deleteHead(s.head);
}

int top (Stack s)
{   
    if (s.head == nullptr) {
		cout << "Stack is empty. Can not top!" << endl;
		return -1;;
	}
    return s.head->data;
}