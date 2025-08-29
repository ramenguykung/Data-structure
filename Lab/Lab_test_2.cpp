#include <iostream>
#include <stack>
#include <string>
using namespace std;

int bracketMatch(const string& text) {
    stack<char> st;
    bool hasBrackets = false;
    int matchCount = 0;

    for (char c : text) {
        if (c == '(' || c == '{' || c == '[' || c == '<') {
            st.push(c);
            hasBrackets = true;
        } else if (c == ')' || c == '}' || c == ']' || c == '>') {
            hasBrackets = true;
            if (st.empty()) {
                continue;
            }

            char top = st.top();
            st.pop();

            if ((c == ')' && top != '(') || 
                (c == '}' && top != '{') || 
                (c == ']' && top != '[') ||
                (c == '>' && top != '<')) {
                return 0;
            } else {
                matchCount++;
            }
        }
    }
    return hasBrackets ? matchCount : 0;
}

int main() {
    string input;

    getline(cin, input);
    if (bracketMatch(input)) {
        cout << bracketMatch(input) << " matched" << endl;
    } else {
        cout << "Not Matched" << endl;
        cout << bracketMatch(input) << " not matched" << endl;
    }
    return 0;
}