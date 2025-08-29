#include <iostream>
#include <stack>
#include <string>
using namespace std;

int bracketMatch(const string& text) {
    stack<char> st;
    int matchCount = 0;

    for (char c : text) {
        if (c == '(' || c == '{' || c == '[' || c == '<') {
            st.push(c);
        } else if (c == ')' || c == '}' || c == ']' || c == '>') {
            if (st.empty()) {
                return -1;  // Unmatched closing bracket
            }

            char top = st.top();
            st.pop();

            if ((c == ')' && top != '(') || 
                (c == '}' && top != '{') || 
                (c == ']' && top != '[') ||
                (c == '>' && top != '<')) {
                return -1;  // Mismatched bracket types
            } else {
                matchCount++;
            }
        }
    }
    
    // If there are unmatched opening brackets, return -1
    if (!st.empty()) {
        return -1;
    }
    
    return matchCount;
}

int main() {
    string input;

    getline(cin, input);
    int result = bracketMatch(input);
    
    // Check if there are any brackets in the input
    bool hasBrackets = false;
    for (char c : input) {
        if (c == '(' || c == ')' || c == '{' || c == '}' || 
            c == '[' || c == ']' || c == '<' || c == '>') {
            hasBrackets = true;
            break;
        }
    }
    
    if (!hasBrackets) {
        printf("No brackets found\n");
    } else if (result > 0) {
        printf("%d matched", result);
    } else {
        printf("Not matched\n0 matched");
    }
    return 0;
}