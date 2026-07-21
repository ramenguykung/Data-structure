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

// Helper to print the string timeline from the beginning up to our current position
void printCurrentState(Node* head, Node* cursor) {
    Node* temp = head;
    while (temp != nullptr) {
        std::cout << temp->data;
        if (temp == cursor) break; // Stop printing at the cursor
        temp = temp->next;
    }
}

int main() {
    int ch;
    Node* head = nullptr;
    Node* cursor = nullptr;

    std::cout << "Use `<` to undo, `>` to redo, and `.` (or Ctrl+C) to terminate." << std::endl;

    while (true) {
        ch = getch(); // Grabs raw keypress

        // --- 1. HANDLE SYSTEM KEYS ---
        if (ch == 3 || ch == '.') { 
            // Ctrl+C is ASCII 3
            break; 
        }
        
        if (ch == 8) { 
            // Backspace is ASCII 8
            if (cursor != nullptr) {
                std::cout << "\b \b"; // Visually erase char from the terminal
                
                // Hard-delete the node (not an undo, an actual backspace)
                Node* toDelete = cursor;
                if (cursor->prev != nullptr) {
                    cursor = cursor->prev;
                    cursor->next = nullptr;
                } else {
                    // We backspaced the very first character
                    head = nullptr;
                    cursor = nullptr;
                }
                delete toDelete;
            }
            continue; // Skip the rest of the loop, wait for next key
        }

        // --- 2. HANDLE UNDO / REDO ---
        if (ch == '<') {
            std::cout << "<"; // Echo the keystroke
            if (cursor != nullptr) {
                cursor = cursor->prev; // Time travel backward
            }
            std::cout << "\n"; // Drop to next line
            printCurrentState(head, cursor);
            continue;
        }
        
        if (ch == '>') {
            std::cout << ">"; // Echo the keystroke
            // Time travel forward IF a future exists
            if (cursor != nullptr && cursor->next != nullptr) {
                cursor = cursor->next;
            } else if (cursor == nullptr && head != nullptr) {
                cursor = head; // Restoring the very first character after undoing everything
            }
            std::cout << "\n";
            printCurrentState(head, cursor);
            continue;
        }

        // --- 3. HANDLE NORMAL TYPING ---
        // If we are typing *after* an undo, we must nuke the alternate future
        if (cursor != nullptr && cursor->next != nullptr) {
            Node* temp = cursor->next;
            while (temp != nullptr) {
                Node* nextNode = temp->next;
                delete temp;
                temp = nextNode;
            }
            cursor->next = nullptr; // Terminate the timeline here
        }

        // Create and link the new node
        Node* newNode = new Node((char)ch);
        if (cursor == nullptr) {
            head = newNode;
            cursor = newNode;
        } else {
            cursor->next = newNode;
            newNode->prev = cursor;
            cursor = newNode;
        }

        // Echo the valid character to the screen
        putch(ch);
    }

    std::cout << "\nTerminated.\n";
    return 0;
}