#include <stdio.h>
#include <ctype.h>
#include <iostream>
using namespace std;

int main() {
	char a[101];
	while(cin.getline(a, 101)) {
		for(int i = 0; i < 100; i++) {
			if(a[i] == '\0') {
				break;
			}
			if(i == 0 && i != ' '){
				a[i] = toupper(a[i]);
			} else if (a[i-1] == ' ' && a[i] != ' '){
				a[i] = toupper(a[i]);
			}

		}
		printf("%s\n", a);
	}
	return 0;
}
