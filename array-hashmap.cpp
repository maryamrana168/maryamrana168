#include <iostream>
#include<string>
using namespace std;

class HashTable {
private:
    int* table;
    int size;

public:
    HashTable(int s) {
        size = s;
        table = new int[size];

        // Initialize all slots with -1 (means empty)
        for (int i = 0; i < size; i++)
            table[i] = -1;
    }

    // Hash function
    int hashFunction(int key) {
        return key % size;
    }

    // Insert using Linear Probing
    void insert(int key) {
        int index = hashFunction(key);

        if (table[index] == -1) {
            table[index] = key;
            return;
        }

        // Collision handling
        int originalIndex = index;
        while (table[index] != -1) {
            index = (index + 1) % size;

            if (index == originalIndex) {
                cout << "Hash Table is Full!" << endl;
                return;
            }
        }

        table[index] = key;
    }

    // Search function
    bool search(int key) {
        int index = hashFunction(key);
        int originalIndex = index;

        while (table[index] != -1) {
            if (table[index] == key)
                return true;

            index = (index + 1) % size;

            if (index == originalIndex)
                break;
        }

        return false;
    }

    // Delete function
    void remove(int key) {
        int index = hashFunction(key);
        int originalIndex = index;

        while (table[index] != -1) {
            if (table[index] == key) {
                table[index] = -1;
                cout << "Key deleted\n";
                return;
            }

            index = (index + 1) % size;

            if (index == originalIndex)
                break;
        }

        cout << "Key not found\n";
    }

    // Display table
    void display() {
        for (int i = 0; i < size; i++) {
            cout << i << " --> " << table[i] << endl;
        }
    }

    // Destructor
    ~HashTable() {
        delete[] table;
        table = nullptr;
    }
};

int main() {
    HashTable ht(7);  // size of array = 7

    ht.insert(10);
    ht.insert(20);
    ht.insert(5);
    ht.insert(15);
    ht.insert(7);

    cout << "Hash Table:\n";
    ht.display();

    cout << "\nSearch 15: " << ht.search(15) << endl;
    cout << "Search 99: " << ht.search(99) << endl;

    ht.remove(15);
    cout << "\nAfter deleting 15:\n";
    ht.display();

    return 0;
}

