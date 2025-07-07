#include <iostream>
#include <queue>
using namespace std;

int main() {
    queue<int> q;
    char option;
    int value;

    while (true) {
        cin >> option;
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
            q.pop();
            }
            break;
        case 'p': {
            queue<int> temp(q);
            
            if (q.empty()) {
                cout << "\n";
            } else {
                while (!temp.empty()) {
                    cout << temp.front() << " ";
                    temp.pop();
                }
                cout << endl;
            }
            break;
        }
        case 'n':
            cout << q.size() << endl;
            break;
        case 's':
            cout << q.front() << " " << q.back() << endl;
            break;
        case 'x':
            exit(0);
        default:
            break;
        }
    }
    return 0;
}