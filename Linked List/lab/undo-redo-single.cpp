#include <iostream>
#include <conio.h>

class Node {
    public:
    char data;
    Node* prev;
    Node* next;

    Node (char data) {
        this->data = data;
        this->prev = nullptr;
        this->next = nullptr;
    }
};

void printChar () {

}
int main() {
    
    Node *head, *cursor = nullptr;
    int ch;
    std::cout << "Use `<` to undo, `>` to redo, and `.` to terminate the program." << std::endl;
    while (true)
    {
        ch = getch();
        // putch(ch);

        if (ch == 3) {break;} // Ctrl+C (SIGINT) signal clause
        if (ch == 8) { // backspace clause
            // TODO: delete last node and print
            continue;
        } 
        if (ch == '.') {break;} // exit loop
        if (ch == '<') { // undo clause

        }
        if (ch == '>') { // redo cluase 

        }
    }

    std::cout << '\n' 
              <<"Terminated.";
    return 0;
}