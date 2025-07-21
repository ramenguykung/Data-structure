#include <iostream>
using namespace std;

const int TABLE_SIZE = 200000;
class node {
    public:
        int key;
        string value;
        node * next;

        node() {
            key = -1;
            value = "-";
            next = NULL;
        }

        node(string p_value, int p_key) {
            value = p_value;
            key = p_key;
            next = NULL;
        }
};
/**
 * @brief Hash table using separate chaining.
 * This class implements a hash table using separate chaining
 */
class separateChaining {
    public:
        int n;
        node* hashTable;
        separateChaining(int p_n) {
            n = p_n;
            hashTable = new node[TABLE_SIZE];
        }
        
        ~separateChaining() {
            delete[] hashTable;
        }

        /**
         * @brief Add a key-value pair to the hash table.
         * @param key The key to be added.
         * @param value The value to be associated with the key.
         */
        void add(int key, string value) {
            int index = key % TABLE_SIZE;
            if (hashTable[index].next == NULL) {
                hashTable[index].value = value;
                hashTable[index].key = key;
                hashTable[index].next = new node();
            } else {
                node * t_node = hashTable[index].next;
                while (t_node->next != NULL) {
                    t_node = t_node->next;
                }
                t_node->value = value;
                t_node->key = key;
                t_node->next = new node();
            }
        }

        /**
         * @brief Search for a value by its key in the hash table.
         * @param key The key to search for.
         * @return The value associated with the key, or "-" if not found.
         */
        string search(int key) {
            int j = key % TABLE_SIZE;
            if (hashTable[j].key == key) {
                return hashTable[j].value;
            } else {
                node * t_node = hashTable[j].next;
                while (t_node != NULL && t_node->next != NULL) {
                    if (t_node->key == key) {
                        return t_node->value;
                    }
                    t_node = t_node->next;
                }
            }
            return "-";
        }

        /**
         * @brief Print the contents of the hash table.
         * This function prints all key-value pairs in the hash table.
         */
        void print() {
            // Check if the hash table is empty
            bool isEmpty = true;
            for (int i = 0; i < TABLE_SIZE; i++) {
                if (hashTable[i].key != -1) {
                    isEmpty = false;
                    break;
                }
            }
            
            if (isEmpty) {
                cout << "Hash table is empty!" << endl;
                return;
            }
            
            for (int i = 0; i < TABLE_SIZE; i++) {
                cout << "(" << hashTable[i].value << ", " << hashTable[i].key << ")";
                if (hashTable[i].next != NULL) {
                    node * t_node = hashTable[i].next;
                    while (t_node->next != NULL) {
                        cout << "(" << t_node->value << ", " << t_node->key << ")";
                        t_node = t_node->next;
                    }
                }
                cout << " ";
            }
            cout << endl;
        }
};

int main() {
    char cmd;
    int key;
    string value;
    separateChaining hashTable(TABLE_SIZE);
    
    while (true) {
        cout << "Enter command (a: add, p: print, s: search, e: exit): ";
        cin >> cmd;

        switch (cmd) {
            case 'a':
                cin >> key >> value;
                hashTable.add(key, value);
                break;
            case 'p':
                hashTable.print();
                break;
            case 's':
                cin >> key;
                value = hashTable.search(key);
                if (value == "-") {
                    cout << value << endl;
                } else {
                    cout << value << endl;
                }
                break;
            case 'e':
                exit(0);
            default:
                cout << "Invalid command!" << endl;
                continue;
        }
    }
}