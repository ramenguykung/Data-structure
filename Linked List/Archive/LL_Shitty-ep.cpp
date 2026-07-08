#include <iostream>
using namespace std;
class Node{
	public:
		int data;
		Node *next;
		
		Node(int data) { //Node Constructor
			this->data = data;
			this->next = nullptr;
		}
};

Node* insertBefore(Node* head, int value) {
	Node* newNode = new Node(value);
	newNode->next = head;
	head = newNode;
	return head;
}

void insertAfter(Node** head, int value) {
	Node* newNode = new Node(value);
}

void traverse(Node* head) {
	Node* current = head;
	while (current != nullptr) {
		cout << current->data << " ";
		current = current -> next;
	}
	cout << std::endl;
}

int main() {
	Node *a = new Node(10);
	a->next = new Node(20);
	a->next->next = new Node(30);
	traverse(a);
	return 0;
}

