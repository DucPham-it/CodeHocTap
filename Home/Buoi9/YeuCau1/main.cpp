#include "Header.h"

int main(){

    LinkedList list1 ,list2, list3, list4, list5;
    createLinkedList(list1);
    createLinkedList(list2);
    createLinkedList(list3);
    createLinkedList(list4);
    createLinkedList(list5);

    while(1 < 10){
       int x;
       cout << "Nhap x: ";
       cin >> x;
       if(x == 0){
           break;
       }
       insertTail(list1, x);
       insertTail(list2, x);
       insertTail(list3, x);
       insertTail(list4, x);
       insertTail(list5, x);
   }
   cout << "List Origin:" << endl;
   printLinkedList(list1);

   addNewNode(list1, 25);
   cout << "List Assignment 1:" << endl;
   printLinkedList(list1);
   deleteAll(list1);

   reverseList(list2);
   cout << "List Assignment 2:" << endl;
   printLinkedList(list2); 
   deleteAll(list2);

   removeDuplicatedNodes(list3);
   cout << "List Assignment 3:" << endl;
   printLinkedList(list3); 
   deleteAll(list3);

   removeFromTail(list4, 2);
   cout << "List Assignment 4:" << endl;
   printLinkedList(list4); 
   deleteAll(list4);


   cout << "List Assignment 5:" << endl;
   if (symmetricList(list5)) 
        cout << "True" << endl;
   else
        cout << "False" << endl;
   deleteAll(list5);
   return 0;
}