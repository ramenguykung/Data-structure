#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

class Node {
	public:
		int data;
		Node * left;
		Node * right;
		int height;
		
		Node(){ // default constructor
			this->left = nullptr;
			this->right = nullptr;
			this->height = 1;
		}
		Node(int data) {
			this->data = data;
			this->left = nullptr;
			this->right = nullptr;
			this->height = 1;
		}
};

class tree {
	public:
		Node * h;
		tree() {
			h = nullptr;
		}
		
		// Helper functions
		int getHeight(Node* node) {
			if (node == nullptr) return 0;
			return node->height;
		}
		
		int getBalance(Node* node) {
			if (node == nullptr) return 0;
			return getHeight(node->left) - getHeight(node->right);
		}
		
		void updateHeight(Node* node) {
			if (node == nullptr) return;
			node->height = 1 + max(getHeight(node->left), getHeight(node->right));
		}
		
		// Right rotation
		Node* rotateRight(Node* y) {
			Node* x = y->left;
			Node* T2 = x->right;
			
			x->right = y;
			y->left = T2;
			
			updateHeight(y);
			updateHeight(x);
			
			return x;
		}
		
		// Left rotation
		Node* rotateLeft(Node* x) {
			Node* y = x->right;
			Node* T2 = y->left;
			
			y->left = x;
			x->right = T2;
			
			updateHeight(x);
			updateHeight(y);
			
			return y;
		}
		
		// Insert helper
		Node* insertNode(Node* node, int x) {
			if (node == nullptr) {
				return new Node(x);
			}
			
			if (x < node->data) {
				node->left = insertNode(node->left, x);
			} else if (x > node->data) {
				node->right = insertNode(node->right, x);
			} else {
				return node; // Duplicate
			}
			
			updateHeight(node);
			
			int balance = getBalance(node);
			
			// Left-Left case
			if (balance > 1 && x < node->left->data) {
				return rotateRight(node);
			}
			
			// Right-Right case
			if (balance < -1 && x > node->right->data) {
				return rotateLeft(node);
			}
			
			// Left-Right case
			if (balance > 1 && x > node->left->data) {
				node->left = rotateLeft(node->left);
				return rotateRight(node);
			}
			
			// Right-Left case
			if (balance < -1 && x < node->right->data) {
				node->right = rotateRight(node->right);
				return rotateLeft(node);
			}
			
			return node;
		}
		
		// Find minimum value node
		Node* minValueNode(Node* node) {
			Node* current = node;
			while (current->left != nullptr) {
				current = current->left;
			}
			return current;
		}
		
		// Delete helper
		Node* deleteNode(Node* node, int x) {
			if (node == nullptr) return node;
			
			if (x < node->data) {
				node->left = deleteNode(node->left, x);
			} else if (x > node->data) {
				node->right = deleteNode(node->right, x);
			} else {
				// Node with one child or no child
				if (node->left == nullptr || node->right == nullptr) {
					Node* temp = node->left ? node->left : node->right;
					
					if (temp == nullptr) {
						temp = node;
						node = nullptr;
					} else {
						*node = *temp;
					}
					delete temp;
				} else {
					// Node with two children
					Node* temp = minValueNode(node->right);
					node->data = temp->data;
					node->right = deleteNode(node->right, temp->data);
				}
			}
			
			if (node == nullptr) return node;
			
			updateHeight(node);
			
			int balance = getBalance(node);
			
			// Left-Left case
			if (balance > 1 && getBalance(node->left) >= 0) {
				return rotateRight(node);
			}
			
			// Left-Right case
			if (balance > 1 && getBalance(node->left) < 0) {
				node->left = rotateLeft(node->left);
				return rotateRight(node);
			}
			
			// Right-Right case
			if (balance < -1 && getBalance(node->right) <= 0) {
				return rotateLeft(node);
			}
			
			// Right-Left case
			if (balance < -1 && getBalance(node->right) > 0) {
				node->right = rotateRight(node->right);
				return rotateLeft(node);
			}
			
			return node;
		}
		
		// Methods
		void push(int x) {
			h = insertNode(h, x);
		}
		
		void pop(int x) {
			h = deleteNode(h, x);
		}
		void peekPreOrder() {
			preorder(h);
			cout << endl;
		}
		void preorder(Node * node) {
			if (node == nullptr) return;

			cout << node->data << " ";
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
