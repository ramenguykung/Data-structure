#include <iostream>
using namespace std;

const int TABLE_SIZE = 17;
/**
 * @brief Hash table using separate chaining.
 * This class implements a hash table using separate chaining
 */
class separateChaining {
    public:
        int hash_key[TABLE_SIZE];
        string hash_table[TABLE_SIZE];
        int n = 0;
        int r = 0;

        separateChaining(int p_n, int p_r) {
            n = p_n;
            r = p_r;
            for(int i = 0; i < n; i++) {
                hash_key[i] = -1;
                hash_table[i] = "-";
            }
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