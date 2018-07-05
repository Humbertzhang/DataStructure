#include <iostream>
using namespace std;

int func(int n) {
	return n*n + n + 41;
}

int isprime(int n) {
	for(int i = 2; i < n; i++) {
		if(n % i == 0) {
			return 0;
		}
	}
	return 1;
}

int main() {
	int a, b;
	while(true) {
		cin >> a >> b;
		int isok = 1;
		if(a == 0 && b == 0) {
			break;
		}
		for(int i = a; i <= b; i++) {
			if(!isprime(func(a))){
				isok = 0;
				break;
			}
		}
		if(isok){
			cout << "OK" << endl;
		} else {
			cout << "Sorry" << endl;
		}
	}
	return 0;
}
