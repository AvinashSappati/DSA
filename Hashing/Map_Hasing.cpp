//DIVISION METHOD ,Folding and mid-square method not required !
/*
Best Case:
Key goes into an empty list or is first in list

O(1) (constant time)

Worst Case:
All keys went to same index (bad hash function)

Then you search through a full list of n elements

O(n) (linear time)

Average Case (for good hash function):
Keys are well distributed

Each index holds few elements

Fetching takes O(1 + α) time
Where α = n / size is load factor

If size is big and spread is good → fetching is almost O(1)!
*/
#include <iostream>
#include <vector>
#include <list>
using namespace std;

class HashTable {
    int size;
    vector<list<int>> table; // Each index has a list (for chaining)

public:
    HashTable(int s) {
        size = s;
        table.resize(size);
    }

    // Hash Function (Division Method)
    int hashFunction(int key) {
        return key % size;
    }

    // Insert key
    void insert(int key) {
        int index = hashFunction(key);
        table[index].push_back(key);
    }

    // Fetch / Search key
    bool search(int key) {
        int index = hashFunction(key);
        for (int x : table[index]) {
            if (x == key)
                return true;
        }
        return false;
    }

    // Display the table
    void display() {
        for (int i = 0; i < size; i++) {
            cout << i << " --> ";
            for (int x : table[i])
                cout << x << " ";
            cout << "\n";
        }
    }
};

int main() {
    HashTable ht(7); // Table of size 7

    ht.insert(10);
    ht.insert(20);
    ht.insert(15);
    ht.insert(7);
    ht.insert(17);

    ht.display();

    cout << "Searching for 15: ";
    cout << (ht.search(15) ? "Found" : "Not Found") << endl;

    cout << "Searching for 99: ";
    cout << (ht.search(99) ? "Found" : "Not Found") << endl;

    return 0;
}
