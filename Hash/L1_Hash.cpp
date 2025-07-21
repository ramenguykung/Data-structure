#include <iostream>
using namespace std;

const int TABLE_SIZE = 17;
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
        node hashTable[TABLE_SIZE];
        separateChaining(int p_n) {
            n = p_n;
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

        string search(int key) {
            int j = key % TABLE_SIZE;
            if (hashTable[j].key == key) {
                return hashTable[j].value;
            } else {
                node * t_node = hashTable[j].next;
                while (t_node->next != NULL) {
                    if (t_node->key == key) {
                        return t_node->value;
                    }
                    t_node = t_node->next;
                }
            }
            return "-";
        }
};

int main() {
    char cmd;
    int key;
    string value;

    cout << "Enter command: ";
    cin >> cmd;
    
    /**
     * @brief Process the command input by the user.
     * @param cmd The command character input by the user.
     * @param key The key to be used in the hash table.
     * @param value The value to be associated with the key in the hash table.
     * @param a Add a new key-value pair to the hash table.
     * @param p Print key-value pairs in the hash table.
     * @param s Search for value by the given key.
     * @param e Exit the program.
     */
    switch (cmd) {
        case 'a':
            cin >> key >> value;
        case 'p':
        case 's':
        case 'e':
            exit(0);
        default:
            cout << "Invalid command!" << endl;
            return 1;

    }
    return 0;
}