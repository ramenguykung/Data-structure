#include <iostream>
#include <queue>
using namespace std;

class Node {
	public:
		int data;
		Node * left;
		Node * right;
		
		Node(){ // default constructor
			this->left = nullptr;
			this->right = nullptr;
		}
		Node(int data) {
			this->data = data;
			this->left = nullptr;
			this->right = nullptr;
		}
};

class tree {
	public:
		Node * h;
		tree() {
			h = nullptr;
		}
		// Methods
		void push(int x) {
			if (h == nullptr) {
				h = new Node(x);
				return;
			}
			Node* current = h;
			while(true) {
				if (x < current->data) {
					if (current->left == nullptr) {
						current->left = new Node(x);
						return;
					}
					current = current->left;
				} else if (x > current->data) {
					if (current->right == nullptr) {
						current->right = new Node(x);
						return;
					}
					current = current->right;
				} else {
					return;
				}
			}
		}
		void pop(int x) {
			if (h == nullptr) return;  // Empty tree

			Node* current = h;
			Node* parent = nullptr;

			// Find the node and its parent
			while (current != nullptr && current->data != x) {
				parent = current; 
				if (x < current->data) {
					current = current->left;
				} else {
					current = current->right;
				}
			}
			if (current == nullptr) return;  // Not found

			// Now delete current
			if (current->left == nullptr && current->right == nullptr) {
				// Leaf
				if (parent == nullptr) h = nullptr;
				else if (parent->left == current) parent->left = nullptr;
				else parent->right = nullptr;
				delete current;
			} else if (current->left == nullptr) {
				// One right child
				if (parent == nullptr) h = current->right;
				else if (parent->left == current) parent->left = current->right;
				else parent->right = current->right;
				delete current;
			} else if (current->right == nullptr) {
				// One left child
				if (parent == nullptr) h = current->left;
				else if (parent->left == current) parent->left = current->left;
				else parent->right = current->left;
				delete current;
			} else {
				// Two children: Find in-order successor
				Node* successor = current->right;
				Node* succParent = current;
				while (successor->left != nullptr) {
					succParent = successor;
					successor = successor->left;
				}
				// Swap data
				current->data = successor->data;
				// Delete successor (which is now a leaf or has right child)
				if (succParent->left == successor) succParent->left = successor->right;
				else succParent->right = successor->right;
				delete successor;
			}
		}
		void peekPreOrder() {
			preorder(h);
			cout << endl;
		}
		void preorder(Node * node) {
			if (node == nullptr) return;

			cout << node->data << ",";
			preorder(node->left);
			preorder(node->right);
		}
};

int main() {
	tree * t = new tree();
	char command;
	int data;
	cin >> command;
	while(true) {
		switch(command) {
			case 'a':
				cin >> data;
				t->push(data);
				break;
			case 'd':
				cin >> data;
				t->pop(data);
				break;
			case 'p':
				t->peekPreOrder();
				break;
			
			case 'x':
				exit(0);
			default:
				cout << "Invalid command, try again!";
				break;
		}
		cin >> command;
	}
}
