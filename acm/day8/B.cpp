#include <stdio.h>
#include <iostream>
using namespace std;

long long int pre[1000005];
int a, b;

int counter(int num){
	int c1 = 0;
	while(num){
		if(num % 10 == 1){
			c1 += 1;
		}
		num /= 10;
	}
	return c1;
}

int main()
{
	pre[0] = 0;
	for(int i = 1; i <= 1000001; i++){
		pre[i] = pre[i-1] + counter(i);
	}
	while(scanf("%d %d", &a, &b) != EOF) {
		if(a > b){int temp = b; b = a; a = temp;}
		int count1 = pre[b] - pre[a-1];
		printf("%d\n", count1);
	}
	return 0;
}
