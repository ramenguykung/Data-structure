#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Highly optimized bracket matching function
bool bracketMatch(const string& text) {
    // Early exit for empty strings
    if (text.empty()) return false;
    
    vector<char> st;
    st.reserve(text.length() / 4);  // More conservative reservation
    
    bool hasBrackets = false;
    
    // Use size_t for better performance with large strings
    for(size_t i = 0; i < text.length(); ++i) {
        char ch = text[i];
        
        // Group opening brackets for better branch prediction
        if (ch == '(' || ch == '{' || ch == '[') {
            st.push_back(ch);
            hasBrackets = true;
        }
        // Handle closing brackets with optimized matching
        else if (ch == ')') {
            if (st.empty() || st.back() != '(') return false;
            st.pop_back();
            hasBrackets = true;
        }
        else if (ch == '}') {
            if (st.empty() || st.back() != '{') return false;
            st.pop_back();
            hasBrackets = true;
        }
        else if (ch == ']') {
            if (st.empty() || st.back() != '[') return false;
            st.pop_back();
            hasBrackets = true;
        }
        // All other characters (whitespace, letters, etc.) are ignored
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
