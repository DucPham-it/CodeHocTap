#include "Header.h"

int main(){
    LinkedList list;
    createLinkedList(list);
    ifstream f ("input.txt");
    
    if (!f.is_open()){
        cout << "ERROR" << endl;
        return 0;
    }
    int x;
    while (f >> x)
    {
        insertTail(list, x);
    }

    int k;
    cout <<" Insert number Kth want to find: ";
    cin >> k;
    Node* check = GetKthNodeFromTail(list.head, k);
    if (check != nullptr){
        cout << check->data << endl;
    }
    else{
        cout << "NULL" << endl;
    }
    deleteAll(list);
    return 0;
}