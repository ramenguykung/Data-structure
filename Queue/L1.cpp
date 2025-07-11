#include <iostream>
#include <queue>
#include <limits>
using namespace std;

int main() {
    queue<int> q;
    char option;
    int value;

    while (true) {
        cin >> option;
        switch (option) {
        case 'e':
            try {
                if (!(cin >> value)) {
                    // Input failed (not a valid integer)
                    cout << "Error: Invalid input. Please enter a valid integer." << endl;
                    cin.clear(); // Clear error flags
                    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear input buffer
                    break;
                }
                q.push(value);
                cout << "Value " << value << " added to queue." << endl;
            }
            catch (const bad_alloc& e) {
                cout << "Error: Memory allocation failed - " << e.what() << endl;
            }
            catch (const exception& e) {
                cout << "Error: " << e.what() << endl;
            }
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
            try {
                if (q.empty()) {
                    cout << "Error: Queue is empty, cannot show front and back." << endl;
                } else {
                    cout << q.front() << " " << q.back() << endl;
                }
            }
            catch (const exception& e) {
                cout << "Error: " << e.what() << endl;
            }
            break;
        case 'x':
            exit(0);
        default:
            break;
        }
    }
    return 0;
}