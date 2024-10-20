#include <iostream>
#include <queue>
using namespace std;
class Node{
	public:
		int value;
		Node* left;
		Node* right;
		Node(){
			this->left= NULL;
			this->right=NULL;
		}
		Node(int value){
			this->left= NULL;
			this->right=NULL;
			this->value=value;
		}
};

class three{
	public:
		Node* h;
		queue <Node*> q;
		three(){
			h = new Node();
		}
		void push(int value){
			Node* x = new Node(value);
			if(h->right==NULL){
				h->right = x;
			}else{
				for(Node* head = h;head->right!=NULL;head=head->right){
					cout <<"start"<< head->right->value << endl;
					if(head->right->right==NULL){	
						if(value < head->right->value && head->right->left ==NULL){
							head->right->left =x;
							cout << head->right->left->value << "insert left of "<<head->right->value<<endl;

							break;
						}else if(value > head->right->value && head->right->right ==NULL){	
							head->right->right = x;
							cout << head->right->right->value << "insert right of "<<head->right->value<<endl;
							break;
							
						}else{
							head = head->right->left;
							if(head->right==NULL&&head->value < value){
								head->right = x;
								cout << head->right->value << "insert right of "<<head->value<<endl;
								break;
							}else if( head->left==NULL&& head->value > value){
								head->left = x;
								cout << head->left->value << "insert left of "<<head->value<<endl;
								break;
							}
							
						}
					}	else if(value < head->right->value){
					
						if(head->right->left==NULL){
							
							head->right->left=x;
							cout << head->right->left->value << "l  "<<endl;
							break;
						}else{
							head = head->right->left;
							if(head->right==NULL&&head->value < value){
								head->right = x;
								cout << head->right->value << "insert right of "<<head->value<<endl;
								break;
							}else if( head->left==NULL&& head->value > value){
								head->left = x;
								cout << head->left->value << "insert left of "<<head->value<<endl;
								break;
							}
							
						}
					}
				}
			}
		}
		void BreadthFirst(){
				Node* head = h;
				q.push(head->right);
				q.push(NULL);
				int i=0;
				while(!q.empty()){
						Node* current = q.front();
	        			q.pop();
	
	        			 if (current != NULL) {
	        			 	cout << current->value << ",";
								if(current->left !=NULL){
									 q.push(current->left);		
								}
								if(current->right!=NULL){
									q.push(current->right);
								}						 
						 }else{
						 		cout << "|";
							 	if (!q.empty()) {
	                				q.push(NULL);
	           				 }
						 }				
						}
						cout << endl;
		}
						void inorder(Node* node) {
				        if (node == NULL) return;
				
				        inorder(node->left);
				        cout << node->value << ",";
				        inorder(node->right);
				    }
				
				    void inorder() {
				        inorder(h->right);
				        cout << endl;
				    }
				        void preorder(Node* node) {
				        if (node == NULL) return;
						
				        cout << node->value << ",";
				        preorder(node->left);
				        preorder(node->right);
				    }
				
				    void preorder() {
				        preorder(h->right);
				        cout << endl;
				    }
				    
				        void postorder(Node* node) {
					        if (node == NULL) return;
					
					        postorder(node->left);
					        postorder(node->right);
					        cout << node->value << ",";
					    }
					
					    void postorder() {
					        postorder(h->right);
					        cout << endl;
					    }
						    void deleteNode(int value) {
								    h->right = deleteNodeRec(h->right, value);
								}
								
								Node* deleteNodeRec(Node* root, int value) {
								    if (root == NULL) return root;
								
								    if (value < root->value) {
								        root->left = deleteNodeRec(root->left, value);
								    } else if (value > root->value) {
								        root->right = deleteNodeRec(root->right, value);
								    } else {
								        // Node with the value found
								
								        // Case 1: Node has no children (leaf node)
								        if (root->left == NULL && root->right == NULL) {
								            delete root;
								            return NULL;
								        }
								
								        // Case 2: Node has one child
								        if (root->left == NULL) {
								            Node* temp = root->right;
								            delete root;
								            return temp;
								        }
								        if (root->right == NULL) {
								            Node* temp = root->left;
								            delete root;
								            return temp;
								        }
								
								        // Case 3: Node has two children
								        Node* temp = minValueNode(root->right);
								        root->value = temp->value;
								        root->right = deleteNodeRec(root->right, temp->value);
								    }
								    return root;
								}
								
								Node* minValueNode(Node* node) {
								    Node* current = node;
								    while (current && current->left != NULL) {
								        current = current->left;
								    }
								    return current;
								}
					    
};
int main(){
	three* test = new three();
	test->push(10);
	test->push(7);
	test->push(13);
	test->push(2);
	test->push(9);
	test->push(20);
	test->push(11);

	test->BreadthFirst();
	test->inorder();
	test->preorder();
	test->postorder(); 
	test->deleteNode(7);
	test->BreadthFirst();
}
