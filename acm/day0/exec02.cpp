#include <stdio.h>

int main() {
	char a, b, c;
	while(scanf("%c%c%c", &a, &b, &c) != EOF){
		if(a > b){
			int temp = a;
			a = b;
			b = temp;
		}	
		if(c <= a){
			printf("%c %c %c\n", c, a, b);
		} else if(c >= b){
			printf("%c %c %c\n", a, b, c);
		} else {
			printf("%c %c %c\n", a, c, b);
		}
		scanf("%c", &a);
	}
	return 0;
}
