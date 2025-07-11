#include <iostream>
#include <queue>
#include <limits>
#include <stdexcept>
#include <new>
using namespace std;

int main() {
    queue<int> q;
    char option;
    int value;

    cout << "Queue Operations: e(nqueue), d(equeue), p(rint), n(umber), s(how ends), x(exit)" << endl;

    while (true) {
        try {
            cout << "Enter option: ";
            if (!(cin >> option)) {
                cout << "Error: Failed to read option" << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                continue;
            }

            switch (option) {
            case 'e':
                try {
                    cout << "Enter value: ";
                    if (!(cin >> value)) {
                        throw invalid_argument("Invalid input: Please enter a valid integer");
                    }
                    
                    // Check for potential overflow in very large queues
                    if (q.size() >= numeric_limits<size_t>::max() - 1) {
                        throw overflow_error("Queue size limit reached");
                    }
                    
                    q.push(value);
                    cout << "✓ Value " << value << " added to queue (size: " << q.size() << ")" << endl;
                }
                catch (const bad_alloc& e) {
                    cout << "✗ Memory Error: " << e.what() 
                         << " - Cannot allocate memory for new element" << endl;
                }
                catch (const overflow_error& e) {
                    cout << "✗ Overflow Error: " << e.what() << endl;
                }
                catch (const invalid_argument& e) {
                    cout << "✗ Input Error: " << e.what() << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
                break;

            case 'd':
                try {
                    if (q.empty()) {
                        cout << "-1" << endl;
                    } else {
                        int front_value = q.front();  // Get value before popping
                        q.pop();
                        cout << front_value << " (remaining: " << q.size() << ")" << endl;
                    }
                }
                catch (const exception& e) {
                    cout << "✗ Dequeue Error: " << e.what() << endl;
                }
                break;

            case 'p': {
                try {
                    if (q.empty()) {
                        cout << "Queue is empty\n" << endl;
                    } else {
                        // This copy operation can throw bad_alloc
                        queue<int> temp(q);
                        cout << "Queue contents: ";
                        while (!temp.empty()) {
                            cout << temp.front() << " ";
                            temp.pop();
                        }
                        cout << endl;
                    }
                }
                catch (const bad_alloc& e) {
                    cout << "✗ Memory Error: Cannot create temporary copy - " << e.what() << endl;
                }
                catch (const exception& e) {
                    cout << "✗ Print Error: " << e.what() << endl;
                }
                break;
            }

            case 'n':
                try {
                    cout << "Queue size: " << q.size() << endl;
                }
                catch (const exception& e) {
                    cout << "✗ Size Error: " << e.what() << endl;
                }
                break;

            case 's':
                try {
                    if (q.empty()) {
                        cout << "✗ Queue is empty, cannot show front and back" << endl;
                    } else if (q.size() == 1) {
                        cout << "Front and back: " << q.front() << " " << q.front() << endl;
                    } else {
                        cout << "Front: " << q.front() << ", Back: " << q.back() << endl;
                    }
                }
                catch (const exception& e) {
                    cout << "✗ Show Error: " << e.what() << endl;
                }
                break;

            case 'x':
                cout << "Exiting program..." << endl;
                exit(0);

            default:
                cout << "Invalid option. Use: e, d, p, n, s, x" << endl;
                break;
            }
        }
        catch (const exception& e) {
            cout << "✗ Unexpected Error: " << e.what() << endl;
            cout << "Program will continue..." << endl;
        }
        catch (...) {
            cout << "✗ Unknown error occurred. Program will continue..." << endl;
        }
    }
    return 0;
}
