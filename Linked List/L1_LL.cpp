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

    void insertBefore(int data, int id);
    void insertAfter(int data, int id);
    void deleteNode(int id);
};

void LinkedList::insertBefore(int data, int id) {
    Node * newNode = new Node(data);
    newNode->next = head;
    head = newNode;
}
void LinkedList::insertAfter(int data, int id) {
}
void LinkedList::deleteNode(int id) {
}

int main() {
    LinkedList list;
    char option;
    int data, id;
    cin >> option;

    switch (option) {
        case 'A':
            cin >> data >> id;
            list.insertAfter(data, id);
            break;
        case 'I':
            cin >> data >> id;
            list.insertBefore(data, id);
        case 'D':
            cin >> id;
            list.deleteNode(id);
            break;
        case 'E':
            cout << "Exiting..." << endl;
            exit(0);
    }
}