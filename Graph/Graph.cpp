#include <iostream>
using namespace std;

class Graph {
	public:
	int edges[100][100];
	int s_v;
	Graph(int n) {	//	Initialize constructure with input (n).
		s_v = n;
		for(int i = 0; i < s_v; i++) {  // nested for loop to format matrix to 0.
			for(int j = 0; j < s_v; j++) {
				edges[i][j] = 0;
			}
		}
	}

	//	methods
	void add_edge(int x, int y, int w);
	void print();
	void BFT(int start);
	void sub_DFT(int start);
	void DFT(int start);
	void in_degree();
};

int main() {
	return 0;
}