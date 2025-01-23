#ifndef _HEADER_H_
#define _HEADER_H_

#include <iostream>
#include <fstream>
using namespace std;


struct Node{
   int data; 
   Node* next; 
};

struct LinkedList{
   Node* head; 
   Node* tail; 
};

Node* createNode(int x);
void createLinkedList(LinkedList& list);
void insertTail(LinkedList& list, int x);
void insertHead(LinkedList& list, int x);
void deleteHead(LinkedList &list);
void deleteAll(LinkedList &list);
Node* GetKthNodeFromTail(Node* head, int k);

#endif