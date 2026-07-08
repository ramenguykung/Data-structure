#include <iostream>
using namespace std; 
#define MAXSIZE 100

// Global variables
int arr[MAXSIZE];
int n=0; // number of elements   

// function declaration
void insert_at_beginning(int x);
void insert_at_end(int x);
void insert_at_position(int x, int pos);
void delete_from_beginning();
void delete_from_end();
void delete_from_position(int pos);
int main() {
	int m;
	cin >> m;
	
	for (int i=0; i<m; i++){
		int temp;
		cin >> temp;
		insert_at_position(temp, 0);
	}
	
	
	// print arr out
	for (int i=0; i<n; i++){
		cout << arr[i] << " ";
	}
	cout << endl;
    return 0;
}


// function DEFINITION
void insert_at_beginning(int x){
	// 1 make room at [0] by 
	//   1.1 moving all elements to the right 
//	for (int i=n-1; i>=0; i--){
//		arr[i+1] = arr[i];
//	}
	//       OR
	//   1.2 move just arr[0] to [n]
	arr[n] = arr[0];

	// 2 put x in [0]
	arr[0] = x;
	
	// 3 increase the number of elements n
	n++;
}
void insert_at_end(int x){
	// 1 put x at [n]
	arr[n] = x;
	// 2 increase n
	n++; 	
}
void insert_at_position(int x, int pos){
	// 1 make room at [pos] by 
	//   1.1 moving elements from n-1 to pos to the right 
//	for (int i=n-1; i>=pos; i--){
//		arr[i+1] = arr[i];
//	}
	//       OR
	//   1.2 move just arr[pos] to [n]
	arr[n] = arr[pos];

	// 2 put x in [pos]
	arr[pos] = x;
	
	// 3 increase the number of elements n
	n++;
}

void delete_from_beginning(){
	if(n <= 0) { // Check if the array is empty
		return;
	}
	else {
		for (int i = 0; i < n-1; i++){ // Initialize a variable for iteration 
			arr[i] = arr[i+1];
		}
		n--; // Reduce the number of current element
	}
}
void delete_from_end(){
	if (n <= 0) {
		return;
	}
	else {
		n--; // Reduce the number of element and discard the last element entirely
	}
}
void delete_from_position(int pos){
	if (n <= 0) {
		return;
	}
	else {
		for (int i = 0; i = pos; i++) {
			arr[i] = arr[i+1];
		}
		n--;
	}
}