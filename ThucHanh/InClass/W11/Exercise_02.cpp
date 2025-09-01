#include <iostream>
#include <string>
#include <vector>
using namespace std;


int hashFunction (const string& key , int tableSize );
void detectCollisions ( const std :: vector < std :: string >& keys , int tableSize );

int main(){
    vector <string> keys = {"cat", "dog", "rat", "pig", "owl", "fox", "hen", "ant", "bee"};
    int tableSize = 7;

    cout << "Detecting collisions for table size " << tableSize << ":" << endl ;
    detectCollisions ( keys , tableSize );

    return 0;
}


int hashFunction (const string& key , int tableSize){
    int sumChars = 0;
    for (char ch: key){
        sumChars+=ch;
    }
    return (sumChars % tableSize);
}

void detectCollisions ( const std :: vector < std :: string >& keys , int tableSize ){
    vector <vector<string>> T (tableSize);
    
    for (string i : keys){
        int num = hashFunction(i, tableSize);
        T[num].push_back(i);
    }

    for (int i = 0; i < tableSize; i++){
        if (T[i].size() > 1){
            cout << "Collision at index " << i << " :" << endl;
            for (int j = 0; j < T[i].size(); j++){
                cout << "- " << T[i][j] << endl;
            }
        }
    }
}
