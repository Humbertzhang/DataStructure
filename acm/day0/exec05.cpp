#include <iostream>
#include <algorithm>
#include <stdlib.h>

using namespace std;

bool compare(int a, int b) {
	return abs(a) > abs(b);
}

int main() {
	while(true) {
		int n;
		cin >> n;
		if (n == 0) {
			break;
		}
		int a[n];
		for(int i = 0; i < n; i++) {
			cin >> a[i];
		}
		sort(a, a+n, compare);
		for(int i = 0; i < n; i++) {
			cout << a[i];
			if(i != n-1){
				cout << " ";
			} else {
				cout << endl;
			}
		}
	}
	return 0;
}
