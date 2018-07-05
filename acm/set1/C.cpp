#include <iostream>
#include <stdio.h>

using namespace std;

int isnum(int i) {
	int n = 0;
	int icopy = i;
	while(icopy){
		int tailn = icopy % 10;
		icopy /= 10;
		n = n + tailn * tailn * tailn;
	}
	if(n == i){
		return 1;
	} else {
		return 0;
	}
}

int main(){
	int m, n;
	while(scanf("%d %d", &m, &n) != EOF) {
		int hasnum = 0;
		for(int i = m; i <= n;i++) {
			if(isnum(i)){
				if(hasnum){
					cout << " " << i;
				} else {
					cout << i;
					hasnum = 1;
				}
			}
		}
		if(!hasnum){
			cout << "no";
		}
		cout << endl;
		scanf("%c", &m);
	}
	return 0;
}
