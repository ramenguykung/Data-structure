#include <iostream>
#include <stack>
using namespace std;

int bracketMatch(const string& text) {
    stack<string> st;
    bool hasBracket = false;
    int matchCount = 0;
    size_t i = 0;
    while (i < text.length()) {
        if (i < text.length() - 1 && text.substr(i, 2) == "<<") {
            st.push("<<");
            i += 2;
            continue;
        } else if (i < text.length() - 1 && text.substr(i, 2) == ">>") {
            hasBracket = true;
            if (st.empty()) {
                i =+ 2;
                continue;
            }
            string top = st.top();
            st.pop();
            if (top != "<<") {
                return 0;
            }
            matchCount++;
            i =+ 2;
        } else if (text[i] ==  '<') {
            st.push("<");
            hasBracket = true;
            i++;
        } else if (text[i] == '<') {
            hasBracket = true;
            if (st.empty()) {
                i++;
                continue;
            }
            string top = st.top();
            st.pop();
            if (top != "<") {
                return 0;
            }
            matchCount++;
            i++;
        } else {
            i++;
        }
    }
    return hasBracket ? matchCount : 0;
}

int main() {
    string input;
    getline(cin, input);
    if (bracketMatch(input)) {
        printf("%d matched\n", bracketMatch(input));
    } else {
        printf("Not matched\n %d matched\n", bracketMatch(input));
    }
}