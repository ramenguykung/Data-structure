#include <iostream>
#include <queue>
using namespace std;

class Node {
	public:
		int data;
		Node * left;
		Node * right;
		
		Node(){ // default constructor
			this->left = NULL;
			this->right = NULL;
		}
		Node(int data) {
			this->data = data;
			this->left = NULL;
			this->right = NULL;
		}
};

class tree {
	public:
		Node * h;
		queue <Node*> q;
		tree() {
			h = new Node();
		}
		// Methods
		void push(int x);
		void popThis(int x);
		void peekBFT();
		void peekInOrder();
		void peekPreOrder();
		void peekPostOrder();
};
void tree::push(int x) {
	Node * n = new Node(x);
	if(h->right == NULL) {
		h->right == NULL;
	}
	else {
		
	}
}
void tree::popThis(int x) {
}
void tree::peekBFT() {
}
void tree::peekInOrder() {
}
void tree::peekPreOrder() {
}
void tree::peekPostOrder() {
}

int main() {
	tree * t = new tree();
	char command;
	int data;
	
	cin >> command >> data;
	
	while(command != 'x' || command != 'X'){
		switch(command) {
			case 'a':
				t->push(data);
				cout << "\n->next";
			
			case 'd':
				t->popThis(data);
				cout << "\n->next";
			
			case 'b':
				t->peekBFT();
				cout << "\n->next";
			
			case 'i':
				t->peekInOrder();
				cout << "\n->next";
			
			case 'p':
				t->peekPreOrder();
				cout << "\n->next";
			
			case 't':
				t->peekPostOrder();
				cout << "\n->next";
			
			default:
				cout << "Invalid command, try again!";
		}
	}
	return 0;
}
