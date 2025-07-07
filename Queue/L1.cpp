#include <iostream>
#include <queue>
using namespace std;

int main() {
    queue<int> q;
    char option;
    int value;

    while (option != 'x' || option != 'X') {
        switch (option) {
        case 'e':
            cin >> value;
            q.push(value);
            break;
        case 'd':
            if (q.empty()) {
                cout << "-1" << endl;
            } else {
            cout << q.front() << endl;
            }
        case 'p': {
            queue<int> temp;
        }
        default:
            break;
        }
    }
    return 0;
}