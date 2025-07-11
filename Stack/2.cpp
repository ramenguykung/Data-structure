#include <iostream>
#include <stack>
using namespace std;

int main() {
    char option;
    int value;
    stack<int> st;

    while (option != 'X') {
        cin >> option;
        
        if (option == 'U') {
            cin >> value;
        }
        switch (option)
        {
        case 'U':
            st.push(value);
            break;
        case 'O':
            cout << st.top() << endl;
            st.pop();
            break;
        case 'T':
            cout << st.top() << endl;
            break;
        case 'P': {
            stack<int> temp(st);
            while (!temp.empty()) {
                cout << temp.top() << " ";
                temp.pop();
            }
            cout << endl;
            break;
        }
        case 'N':
            cout << st.size() << endl;
            break;
        default:
            break;
        }
    }
    
    return 0;
}