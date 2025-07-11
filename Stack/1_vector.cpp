#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Optimized bracket matching function that combines checking and matching
bool bracketMatch(const string& text) {
    vector<char> st;  // Use vector instead of stack for better performance
    st.reserve(text.length() / 2);  // Reserve space to avoid reallocations
    
    bool hasBrackets = false;
    
    for(char ch : text) {
        switch(ch) {
            case '(':
            case '{':
            case '[':
                st.push_back(ch);
                hasBrackets = true;
                break;
            case ')':
                if (st.empty() || st.back() != '(') return false;
                st.pop_back();
                hasBrackets = true;
                break;
            case '}':
                if (st.empty() || st.back() != '{') return false;
                st.pop_back();
                hasBrackets = true;
                break;
            case ']':
                if (st.empty() || st.back() != '[') return false;
                st.pop_back();
                hasBrackets = true;
                break;
            // Ignore all other characters (whitespace, letters, etc.)
        }
    }
    // Return false if no brackets found or if brackets don't match
    return hasBrackets && st.empty();
}

int main() {
    string input;
    getline(cin, input);

    if (bracketMatch(input)) {
        cout << "Pass\n";
    } else {
        cout << "Error\n";
    }
    return 0;
}
