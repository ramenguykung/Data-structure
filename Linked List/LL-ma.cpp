#include <iostream>
using namespace std;

class Node {
public:
	int data;
	Node* next;
	Node(int data) {
		this->data = data;
		this->next = NULL;
	}
};

class LinkList {
public:
	Node* head;
	bool isValidInsertion;
	LinkList() {
		head = new Node(0); // temp head node
		head->next = NULL;
		isValidInsertion = true;
	}

	void push(int data) {
		Node* ptr = head;
		Node* x = new Node(data);
		x->next = ptr;
		head = x;
	}

	bool exists(int data) {
		for (Node* ptr = head; ptr != NULL; ptr = ptr->next) {
			if (ptr->data == data) {
				isValidInsertion = false;
				return true;
			}
		}
		isValidInsertion = true;
		return false;
	}

	void insert(int data, int id) {
		if (exists(data)) {
			return;
		}

		Node* ptr = head;
		if (id == 0 && ptr->next == NULL) {
			push(data);
		} else if (ptr->next != NULL && ptr->data == id) {
			push(data);
		} else {
			for (Node* ptr = head; ptr != NULL; ptr = ptr->next) {
				if (ptr->data == data) {
					break;
				} else if (ptr->next->data == id) {
					Node* x = new Node(data);
					x->next = ptr->next;
					ptr->next = x;
					break;
				} else if (ptr->next->next == NULL && ptr->data != id) {
					Node* x = new Node(data);
					x->next = ptr->next;
					ptr->next = x;
					break;
				}
			}
		}
	}

	void insertafter(int data, int id) {
		if (exists(data)) {
			return;
		}

		Node* ptr = head;
		if (id == 0 && ptr->next == NULL) {
			push(data);
		} else if (ptr->next != NULL && ptr->data == id) {
			Node* x = new Node(data);
			x->next = ptr->next;
			ptr->next = x;
		} else {
			for (Node* ptr = head; ptr != NULL; ptr = ptr->next) {
				if (ptr->data == id) {
					Node* x = new Node(data);
					x->next = ptr->next;
					ptr->next = x;
					break;
				} else if (ptr->next->next == NULL && ptr->data != id) {
					Node* x = new Node(data);
					x->next = ptr->next;
					ptr->next = x;
					break;
				}
			}
		}
	}

	void deletenode(int data) {
		for (Node* ptr = head; ptr != NULL; ptr = ptr->next) {
			if (ptr->data == data) {
				head = ptr->next;
				break;
			} else if (ptr->next->data == data) {
				ptr->next = ptr->next->next;
				break;
			}
		}
	}

	void printList() {
		for (Node* ptr = head; ptr != NULL; ptr = ptr->next) {
			if (ptr->data == 0) {
				continue;
			} else {
				cout << ptr->data << " ";
			}
		}
		cout << endl;
	}
};

int main() {
	LinkList* test = new LinkList();
	char c;
	int data, id;
	do {
		cin >> c;
		switch (c) {
			case 'I': {
				cin >> data;
				cin >> id;
				test->insert(data, id);
				if (test->isValidInsertion) {
					test->printList();
				}
				test->isValidInsertion = true;
				break;
			}
			case 'D': {
				cin >> data;
				test->deletenode(data);
				test->printList();
				break;
			}
			case 'A': {
				cin >> data;
				cin >> id;
				test->insertafter(data, id);
				if (test->isValidInsertion) {
					test->printList();
				}
				test->isValidInsertion = true;
				break;
			}
		}
	} while (c != 'E');

	return 0;
}

