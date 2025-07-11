#include <iostream>
#include <stack>
#include <string>
using namespace std;


bool bracketMatch(const string& text) {
    stack<char> st;
    bool hasBrackets = false;
    
    for (char c : text) {
        if (c == '(' || c == '{' || c == '[') {
            st.push(c);
            hasBrackets = true;
        }
        else if (c == ')' || c == '}' || c == ']') {
            hasBrackets = true;
            if (st.empty()) {
                return false;
            }
            
            char top = st.top();
            st.pop();
            
            if ((c == ')' && top != '(') ||
                (c == '}' && top != '{') ||
                (c == ']' && top != '[')) {
                return false;
            }
        }
    }
    return st.empty() && hasBrackets;
}
int main() {
    string input;
    getline(cin, input);

    if (bracketMatch(input)) {
        cout << "Pass" << endl;
    } else {
        cout << "Error" << endl;
    }
}