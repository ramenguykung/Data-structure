#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class open_addressing {
	public:
		int hash_key[17];
		string hash_table[17];
		int n = 0;
		int r = 0;
		
		open_addressing(int p_n, int p_r) {
			n = p_n;
			r = p_r;
			for(int i = 0; i < n; i++) {
				hash_key[i] = -1;
				hash_table[i] = "-";
			}
		}
};

int main() {
	char cmd;
	while(cin >> cmd) {
		
	}
	return 0;
}
