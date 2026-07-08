#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class Node {
    public:
    int data;
    Node * next;
    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};

class LinkedList {
    public:
    Node * head;

    LinkedList() {
        head = nullptr;
    }

    ~LinkedList() {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    void insertBefore(int data, int id);
    void insertAfter(int data, int id);
    void deleteNode(int id);
    void printList();
};

/**
 * Inserts a new node with the given data before the node with the specified id.
 * @param data The data to be inserted.
 * @param id The id of the node before which the new node should be inserted.
 * If the id is 0, the new node is inserted at the beginning (head)of the list.
 */
void LinkedList::insertBefore(int data, int id) {
    // Insert at head if list is empty or if we want to insert before the first node
    if (head == nullptr || head->data == id) {
        Node * newNode = new Node(data);
        newNode->next = head;
        head = newNode;
        return;
    }

    Node * ptr = head;
    while (ptr != nullptr && ptr->next != nullptr && ptr->next->data != id) {
        ptr = ptr->next;
    }

    if (ptr->next != nullptr) {
        Node * newNode = new Node(data);
        newNode->next = ptr->next;
        ptr->next = newNode;
    } else {
        cout << "Node with id " << id << " not found." << endl;
    }
}
void LinkedList::insertAfter(int data, int id) {
    // Traverse the list to find the node with the specified id
    Node * ptr = head;
    while (ptr != nullptr && ptr->data != id) {
        ptr = ptr->next;
    }

    if (ptr != nullptr) {
        Node * newNode = new Node(data);
        newNode->next = ptr->next;
        ptr->next = newNode;
    } else {
        cout << "Node with id " << id << " not found." << endl;
    }
}
void LinkedList::deleteNode(int id) {
    if (head == nullptr) {
        cout << "List is empty." << endl;
        return;
    }

    // If the head node is to be deleted
    if (head->data == id) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }

    // Find the node before the one to be deleted
    Node* ptr = head;
    while (ptr->next != nullptr && ptr->next->data != id) {
        ptr = ptr->next;
    }

    if (ptr->next != nullptr) {
        Node* temp = ptr->next;
        ptr->next = ptr->next->next;
        delete temp;
    } else {
        cout << "Node with id " << id << " not found." << endl;
    }
}
void LinkedList::printList() {
    Node * ptr = head;
    while (ptr != nullptr) {
        cout << ptr->data << " ";
        ptr = ptr->next;
    }
    cout << endl;
}
int main() {
    LinkedList list;
    char option;
    int data, id;

    while(cin >> option) {
        switch (option) {
        case 'A':
            cin >> data >> id;
            list.insertAfter(data, id);
            list.printList();
            break;
        case 'I':
            cin >> data >> id;
            list.insertBefore(data, id);
            list.printList();
            break;
        case 'D':
            cin >> id;
            list.deleteNode(id);
            list.printList();
            break;
        case 'E':
            cout << "Exiting..." << endl;
            return 0;
        default:
            cout << "Invalid option. Please try again." << endl;
        }
    }
    return 0;
}