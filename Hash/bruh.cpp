#include <iostream>
#include <vector>
#include <list>
#include <string>

using namespace std;

const int TABLE_SIZE = 17;

struct HashNode {
    int key;
    string value;
    HashNode(int k, string v) : key(k), value(v) {}
};

class HashTable {
private:
    vector<list<HashNode>> table;

    int hashFunction(int key) {
        return key % TABLE_SIZE;
    }

public:
    HashTable() {
        table.resize(TABLE_SIZE);
    }

    void add(int key, string value) {
        int hash = hashFunction(key);
        for (auto& node : table[hash]) {
            if (node.key == key) {
                node.value = value;
                return;
            }
        }
        table[hash].emplace_back(key, value);
    }

    string search(int key) {
        int hash = hashFunction(key);
        for (auto& node : table[hash]) {
            if (node.key == key) {
                return node.value;
            }
        }
        return "-";
    }

    void print() {
        for (int i = 0; i < TABLE_SIZE; ++i) {
            if (table[i].empty()) {
                cout << "-1 -" << endl;
            } else {
                for (auto& node : table[i]) {
                    cout << node.key << " " << node.value << " ";
                }
                cout << endl;
            }
        }
    }
};

int main() {
    HashTable hashTable;
    string command;
    int key;
    string value;

    while (true) {
        cin >> command;
        if (command == "a") {
            cin >> key >> value;
            hashTable.add(key, value);
        } else if (command == "s") {
            cin >> key;
            cout << hashTable.search(key) << endl;
        } else if (command == "p") {
            hashTable.print();
        } else if (command == "e") {
            break;
        }
    }

    return 0;
}

