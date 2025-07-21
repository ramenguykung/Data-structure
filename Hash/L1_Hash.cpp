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

    cout << "Enter command: ";
    cin >> cmd;
    switch (cmd) {
        case 'a':
            
    }
    return 0;
}