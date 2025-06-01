#include <iostream>
#include <string>
#include <vector>
using namespace std;

class HashTable {
    private:
    struct Entry {
        std::string key;
        int value;
        bool isOccupied;

        Entry() : key(""), value(0), isOccupied(false) {}
    };
    
    std::vector<Entry> table;
    int size;
    
    int hashFunction(const std::string& key) {
        int sum = 0;
        for (char c : key) {
            sum += static_cast<int>(c);
        }
        return sum % size;
    }
    
    public:
    HashTable(int tableSize) : size(tableSize) {
        table.resize(size);
    }

    // TODO: Implement the insert method with linear probing
    bool insert(const std::string& key, int value) {
        // 1. Compute the initial hash value
        // 2. If the slot is empty, insert the entry
        // 3. If there’s a collision, use linear probing to find the next available slot
        // 4. Return false if the table is full

        int index = hashFunction(key);
        for (int i = 0; i < size; i++)
        {   
            int probeIndex = (index + i) % size;  
            if (!table[probeIndex].isOccupied){              
                table[probeIndex].key = key;
                table[probeIndex].value = value;
                table[probeIndex].isOccupied = true;
            return true;
            }
        }  
        
        return false; 
    }

    // TODO: Implement the search method
    bool search(const std::string& key, int& value) {
        // 1. Compute the initial hash value       
        // 2. Check if the key exists at that position
        // 3. If not, use linear probing to search for the key
        // 4. Return true and set the value if found, false otherwise

        int index = hashFunction(key);

        for (int i = 0; i < size; i++)
        {   
            int probeIndex = (index + i) % size;    
            if (!table[probeIndex].isOccupied) {
                return false; // Empty spot, key not in table
            }
            if (table[probeIndex].isOccupied && 
                table[probeIndex].key == key){
                    value = table[probeIndex].value;
                    return true;
            }               
        }

        return false; 
    }

    // Print the contents of the hash table
    void print() {
        for (int i = 0; i < size; i++) {
            if (table[i].isOccupied) {
                std::cout << i << ": " << table[i].key << " -> " << table[i].value << std::endl;
            } else {
                std::cout << i << ": Empty" << std::endl;
            }
        }
    }
};
    
int main() {
    HashTable ht(10);
    
    ht.insert("apple", 5);
    ht.insert("banana", 8);
    ht.insert("cherry", 3);
    ht.insert("date", 12);
    ht.insert("grape", 10);
    ht.insert("lemon", 7);
    
    std::cout << "Hash Table Contents:" << std::endl;
    ht.print();
    
    std::cout << "\nLookup Operations:" << std::endl;
    int value;
    if (ht.search("banana", value)) {
        std::cout << "Found banana with value " << value << std::endl;
    } else {
         std::cout << "Could not find banana" << std::endl;
    }
    
    if (ht.search("kiwi", value)) {
        std::cout << "Found kiwi with value " << value << std::endl;
    } else {
        std::cout << "Could not find kiwi" << std::endl;
    }
    
    return 0;
}
    