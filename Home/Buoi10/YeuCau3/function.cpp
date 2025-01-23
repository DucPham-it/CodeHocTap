#include "Header.h"

Node* createNode(int x){
   Node* p = new Node;
   p->data = x;
   p->next = nullptr;
   return p;
}

void createLinkedList(LinkedList& list){
   list.head = nullptr;
   list.tail = nullptr;
}

void insertTail(LinkedList& list, int x){
   if(list.head == nullptr){
       Node *p = createNode(x);
       list.head = p;
       list.tail = p;
   }
   else{
       Node *p = createNode(x);
       list.tail->next = p;
       list.tail = p;
   }
}

void insertHead(LinkedList& list, int x){
   if(list.head == nullptr){
       Node *p = createNode(x);
       list.head = p;
       list.tail = p;
   }
   else{
       Node *p = createNode(x);
       p->next = list.head;
       list.head = p;
   }
}

void deleteHead(LinkedList &list){
   if(list.head == nullptr){

       return;
   }
   if(list.head != nullptr && list.head == list.tail){
       Node *p = list.head;
       list.head = nullptr;
       list.tail = nullptr;
       delete p;
       return;
   }
   Node *p = list.head; 
   list.head = list.head->next; 
   delete p;
}

void deleteAll(LinkedList &list){
   while(list.head != nullptr){
       deleteHead(list);
   }
}
Node* GetKthNodeFromTail(Node* head, int k){
    if (head == nullptr) return nullptr;
    int count =0;
    Node* cur = head;
    while (cur != nullptr)
    {
        count++;
        cur = cur->next;
    }
    cur = head;
    int check = 0;
    if (k > count || k < 1) return nullptr;
    while (check < count-k)
    {
        check++;
        cur = cur->next;
    }
    return cur;
}