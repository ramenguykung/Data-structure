#include <iostream>
#include <queue>

class Node {
	public:
		int data;
		Node * left;
		Node * right;
		
		Node () { // default constructor
			this->left = NULL;
			this->right = NULL;
		}
		
		Node (int data) {
			this->data = data;
			this->left = NULL;
			this->right = NULL;
		}
};

class tree {
	public:
		Node * h;
		std::queue <Node*> q;
		tree() {
			h = new Node();
		}
		//Methods
		void push(int data);
		void popThis(int data);
		void peekPreOrder();
};

void tree::push(int data) {
}
void tree::popThis(int data) {
}
void tree::peekPreOrder() {
}
int main() {
	tree * t = new tree();
	char command;
	int data;
	
	while(std::cin >> command) {
		if (command == 'a') {
		}
		else if (command == 'd') {
		}
		else if (command == 'p') {
		}
		else if (command == 'x' || command == 'X'){
			break;
		}
		else {
			std::cout << "Invalid command, try again!" << std::endl;
		}
	}
	return 0;
}
