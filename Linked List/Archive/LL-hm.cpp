#include <iostream>
using namespace std;
class Node {
	public:
		int id;
		Node* next;
		Node(int id) : id(id), next(nullptr) {}
};
class LinkedList {
public:
    Node* head;
    LinkedList() : head(nullptr) {}
    bool isExisted(int id) {
        for (Node* ptr = head; ptr; ptr = ptr->next) {
            if (ptr->id == id) {
                return true;
            }
        }
        return false;
    }
    int size() {
        int count = 0;
        for (Node* ptr = head; ptr; ptr = ptr->next) {
            count++;
        }
        return count;
    }

    void insertBefore(int id, int pos) {
        Node* n = new Node(id);
        if (!head || pos == head->id) {
            n->next = head;
            head = n;
        } else {
            Node* prev = head;
            while (prev->next && prev->next->id != pos) {
                prev = prev->next;
            }
            n->next = prev->next;
            prev->next = n;
        }
        show();
    }

    void insertAfter(int id, int pos) {
        Node* n = new Node(id);
        if (!head) {
            head = n;
        } else {
            for (Node* ptr = head; ptr; ptr = ptr->next) {
                if (ptr->id == pos) {
                    n->next = ptr->next;
                    ptr->next = n;
                    break;
                }
            }
        }
        show();
    }

    void deleteNode(int id) {
        if (head && head->id == id) {
            head = head->next;
        } else {
            Node* prev = head;
            while (prev->next && prev->next->id != id) {
                prev = prev->next;
            }
            if (prev->next) {
                prev->next = prev->next->next;
            }
        }
        show();
    }

    void show() {
        for (Node* ptr = head; ptr; ptr = ptr->next) {
            cout << ptr->id << " ";
        }
        cout << endl;
    }
};

int main() {
    char cmd;
    int id, pos;
    LinkedList l;

    while (cin >> cmd) {
        switch (cmd) {
            case 'A':
                cin >> id >> pos;
                l.insertAfter(id, pos);
                break;
            case 'I':
                cin >> id >> pos;
                l.insertBefore(id, pos);
                break;
            case 'D':
                cin >> id;
                l.deleteNode(id);
                break;
            case 'E':
                return 0;
            default:
                cout << "Invalid" << endl;
        }
    }
}
