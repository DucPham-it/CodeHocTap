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
void insertYAfterX(LinkedList& list, int x, int y);
void deleteHead(LinkedList &list);
void deleteAll(LinkedList &list);
void printLinkedList(LinkedList list);
void addNewNode(LinkedList& list, int x);
void reverseList(LinkedList& list);
void removeDuplicatedNodes(LinkedList& list);
void removeFromTail(LinkedList& list, int k);
bool symmetricList(LinkedList list);
#endif