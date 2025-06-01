#include <iostream>
#include <string>
#include <vector>
using namespace std;


int hashFunction (const string& key , int tableSize );

int main(){
    string keys [] = {"apple", "banana", "cherry", "date", "elderberry"};
    int tableSize = 10;

    cout << " Hash values for different keys ( table size = " << tableSize << "):" << endl;

    for ( const auto & key : keys ) {
        cout << "Key: " << key << ", Hash value : " << hashFunction (key , tableSize) << endl;
    }

    return 0;
}


int hashFunction (const string& key , int tableSize){
    int sumChars = 0;
    for (char ch: key){
        sumChars+=ch;
    }
    return (sumChars % tableSize);
}