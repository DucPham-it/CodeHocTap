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
        bool isDeleted ; // For handling deletions

        Entry() : key(""), value(0), isOccupied(false), isDeleted(false) {}
    };
    
    std::vector<Entry> table;
    int size;
    int count; // Number of elements in the table

    int hashFunction(const std::string& key) {
        int sum = 0;
        for (char c : key) {
            sum += static_cast<int>(c);
        }
        return sum % size;
    }
    
    bool isPrime(int n) {
        if (n <= 1) return false;
        if (n <= 3) return true;
        if (n % 2 == 0 || n % 3 == 0) return false;
    
        for (int i = 5; i * i <= n; i += 6) {
            if (n % i == 0 || n % (i + 2) == 0) return false;
        }
        return true;
    }
    
    int nextPrime(int n) {
        if (n <= 1) return 2;
    
        int prime = n;
        while (true) {
            prime++;
            if (isPrime(prime)) return prime;
        }
    }

    public:
    HashTable (int tableSize ) : size ( tableSize ) , count (0) {
        table.resize(size);
    }

    float getLoadFactor () {
        return static_cast <float>(count) / size ;
    }

    // TODO: Implement the insert method with linear probing
    bool insert(const std::string& key, int value) {
    // 1. If the table is more than 70% full , return false
    // 2. Compute the initial hash value
    // 3. Use quadratic probing : h(k, i) = (h(k) + i^2) % size to find an empty slot
    // 4. Return true if successful , false if the item cannot be inserted
    
        if (getLoadFactor() > 0.7f){
            return false;
        }

        int index = hashFunction(key);
        for (int i = 0; i < size; i++)
        {   
            int probeIndex = (index + i * i) % size;
            if (!table[probeIndex].isOccupied || table[probeIndex].isDeleted){              
                table[probeIndex].key = key;
                table[probeIndex].value = value;
                table[probeIndex].isOccupied = true;
                table[probeIndex].isDeleted = false;
                count++;
                return true;
            }
        }  

        return false; 
    }
    // TODO: Implement the search method
    bool search(const std::string& key, int& value) {

        int index = hashFunction(key);

        for (int i = 0; i < size; i++)
        {   
            int probeIndex = (index + i * i) % size;    
            
            if (!table[probeIndex].isOccupied && !table[probeIndex].isDeleted) {
                return false; // Empty spot, key not in table
            }

             if (table[probeIndex].isOccupied &&
                !table[probeIndex].isDeleted &&
                table[probeIndex].key == key){
                    value = table[probeIndex].value;
                    return true;
            }               
        }

        return false; 
    }

    bool remove ( const std :: string & key ) {
        // Find the key using linear probing
        // Mark the slot as deleted but not empty ( tombstone )
        // This requires adding a " isDeleted " flag to the Entry struct
        // Return true if successful , false if key not found

        int index = hashFunction(key);

        for (int i = 0; i < size; i++)
        {   
            int probeIndex = (index + i * i) % size;    
            
            if (!table[probeIndex].isOccupied && !table[probeIndex].isDeleted) {
                return false; // Empty spot, key not in table
            }

            if (table[probeIndex].isOccupied &&
                !table[probeIndex].isDeleted &&
                table[probeIndex].key == key){
                    table[probeIndex].isDeleted = true;
                    count--;
                    return true;
            }               
        }

        return false;        
    }

    //Rehash the table when the load factor exceeds a threshold
    void rehash() {
        std::vector<Entry> oldTable = table;
        int oldSize = size;
    
        // Double the size, preferably to the next prime number
        size = nextPrime(2 * size);
        count = 0;
        table.clear();
        table.resize(size);
    
        // Reinsert all non-deleted entries
        for (const auto& entry : oldTable) {
            if (entry.isOccupied && !entry.isDeleted) {
                insert(entry.key, entry.value);
            }
        }
    }
    
    // Print the contents of the hash table
    void print() {
        for (int i = 0; i < size; i++) {
            if (table[i].isOccupied && !table[i].isDeleted) {
                std::cout << i << ": " << table[i].key << " -> " << table[i].value << std::endl;
            } else if (table[i].isDeleted) {
                std::cout << i << ": Deleted" << std::endl;
            } else {
                std::cout << i << ": Empty" << std::endl;
            }
        }
    }
};

int main() {
    HashTable ht(13); 

    std::vector<std::pair<std::string, int>> data = {
        {"apple", 5}, {"banana", 8}, {"cherry", 3},
        {"date", 12}, {"grape", 10}, {"lemon", 7},
        {"orange", 9}, {"pear", 4}, {"fig", 6}
    };
    
    for (const auto& item : data) {
        if (ht.insert(item.first, item.second)) {
            std::cout << "Inserted " << item.first << std::endl;
        } else {
            std::cout << "Failed to insert " << item.first << std::endl;
        }
    }
    
    std::cout << "\nHash Table Contents:" << std::endl;
    ht.print();
    
    return 0;
}
    