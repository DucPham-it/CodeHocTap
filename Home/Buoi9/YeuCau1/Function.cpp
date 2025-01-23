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

void insertYAfterX(LinkedList& list, int x, int y){
   Node* cur = list.head;
   while(cur != nullptr){
       if(cur->data == x){
           break;
       }
       cur = cur->next;
   }
   if(cur == nullptr){
       return;
   }
   if(cur == list.tail){
       insertTail(list, y);
   }
   else{
       Node *p = createNode(y);
       p->next = cur->next;
       cur->next = p;
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

void printLinkedList(LinkedList list){
   Node *cur = list.head;
   while(cur != nullptr){
       cout << cur->data << " ";
       cur = cur->next;
   }
   cout << endl;
}

void addNewNode(LinkedList& list, int x){
    Node* p = createNode(x);

    if (list.head==nullptr) {
        list.head = p;
        list.tail = p;
        return;
    }
    if (list.head->data > list.head->next->data){
        if (x > list.head->data){
            insertHead(list,x);
            return;
        }
    }
    if (list.head->data < list.head->next->data){
        if (x < list.head->data){
            insertHead(list,x);
            return;
        }  
    }

    Node *cur = list.head;    
    while (cur->next != nullptr)
    {
        if ((cur->data > cur->next->data) && (x > cur->next->data) && (x < cur->data)){
            p->next = cur->next;
            cur->next = p;
            return;
        }
        if ((cur->data < cur->next->data) && (x < cur->next->data) && (x > cur->data)){
            p->next = cur->next;
            cur->next = p;
            return;
        }
        cur = cur->next;
    }
    list.tail->next = p;
    list.tail = p; 
}
    
void reverseList(LinkedList& list){
    Node* cur = list.head;
    LinkedList listCpy;
    createLinkedList(listCpy);
    while (cur != nullptr){
        insertHead(listCpy, cur->data);
        cur = cur->next;
    }
    cur = list.head; 
    Node* curCpy = listCpy.head;
    while (cur != nullptr){
        cur->data = curCpy->data;
        cur = cur->next;
        curCpy = curCpy->next;    
    }
    deleteAll(listCpy);
}

void removeDuplicatedNodes(LinkedList& list){
    Node* cur = list.head;
    LinkedList listCpy;
    createLinkedList(listCpy);

    while (cur != nullptr){
        Node* curCpy = listCpy.head;
        bool checkDuplicated = false;
        while  (curCpy != nullptr ){
            if (curCpy->data == cur->data)
            {
                checkDuplicated = true;
                break;
            }
            curCpy = curCpy->next;
        }
        if (!checkDuplicated) {
            insertTail(listCpy, cur->data);
        }
        cur = cur->next;
    }
    LinkedList temp;
    temp.head = list.head;
    temp.tail = list.tail;
    list.head = listCpy.head;
    list.tail = listCpy.tail;
    listCpy.head = temp.head;
    listCpy.tail = temp.tail;
    deleteAll(listCpy);
}


void deleteNodeInList(LinkedList& list, Node* p){
    if (p == list.head){
        deleteHead(list);
        return;
    }
    Node* beforeP = list.head;
    while (beforeP->next != p)
    {
        beforeP = beforeP->next;
    }
    beforeP->next= p->next;
    delete p;
}

void removeFromTail(LinkedList& list, int k){
    Node* p = list.head;
    while (p != nullptr){
        Node* check = p;
        int i=2;
        while (i<=k)
        {  
           if (check == nullptr) break;
           check = check->next;
           i++; 
        }
        bool flag = false;
        if (check == list.tail){
            flag = true;
        }
        if (flag) break;
        p = p->next;
    }
    deleteNodeInList(list,p);
}

bool symmetricList(LinkedList list){
    Node*p = list.head;
    LinkedList listCpy;
    createLinkedList(listCpy);
    while (p != nullptr)
    {
        insertTail(listCpy, p->data);
        p = p->next;
    }
    reverseList(listCpy);
    p = list.head;
    Node* check = listCpy.head;
    while (p != nullptr)
    {
        if (p->data !=  check->data) {
            deleteAll(listCpy);
            return false;
        }
        p = p->next;
        check = check ->next;
    }
    deleteAll(listCpy);
    return true;
}