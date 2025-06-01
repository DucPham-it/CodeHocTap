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

    int hash1(const std::string& key) {
        int sum = 0;
        for (char c : key) {
            sum += static_cast<int>(c);
        }
        return sum % size;
    }

    int hash2 ( const std :: string & key ) {
        // TODO : Implement a different hash function for double hashing
        // It should never return 0 to avoid an infinite loop during probing
        // A common approach is to use a prime number less than the table size : R - (key hash % R)
        // where R is the largest prime number less than table size
        
        int n = 1;

        while (nextPrime(n) < size)
        {
           n = nextPrime(n);
        }
        
        int h = n - (hash1(key) % n);
        return (h == 0) ? 1 : h;
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
   // 2. Compute both hash values
   // 3. Use double hashing formula : h(k, i) = (h1(k) + i * h2(k)) % size
   // 4. Return true if successful , false if the item cannot be inserted
    
        if (getLoadFactor() > 0.7f){
            return false;
        }

        int h1 = hash1(key);
        int h2 = hash2(key);
        for (int i = 0; i < size; i++)
        {   
            int probeIndex = (h1 + i * h2) % size;
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

        int h1 = hash1(key);
        int h2 = hash2(key);

        for (int i = 0; i < size; i++)
        {   
            int probeIndex = (h1 + i * h2) % size;    
            
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

        int h1 = hash1(key);
        int h2 = hash2(key);

        for (int i = 0; i < size; i++)
        {   
            int probeIndex = (h1+ i * h2) % size;    
            
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

int main () {
   HashTable ht (13) ; // Using a prime number for table size
  
   std :: vector < std :: pair < std :: string , int > > data = {
   {"cat", 1} , {"dog", 2} , {"bird", 3} , {"fish", 4} ,
   {"lion", 5} , {"tiger", 6} , {"bear", 7} , {"wolf", 8} ,
   {"fox", 9} , {"deer",10}
   };
  
   for ( const auto & item : data ) {
   if ( ht . insert (item.first , item.second) ) {
   std :: cout << "Inserted " << item . first << std :: endl ;
   } else {
   std :: cout << "Failed to insert " << item . first << std :: endl ;
   }
   }
  
   std :: cout << "\nHash Table Contents :" << std :: endl ;
   ht . print () ;
  
   int value ;
   if ( ht . search ("tiger", value ) ) {
   std :: cout << "\nFound tiger with value " << value << std :: endl ;
   } else {
   std :: cout << "\nCould not find tiger " << std :: endl ;
   }

   return 0;
}