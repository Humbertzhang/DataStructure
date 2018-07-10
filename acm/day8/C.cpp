#include <iostream>
#include <stdio.h>
using namespace std;

int a[100005];
long long int presum[100005];

int main()
{
	int T;
	cin >> T;
	while(T--){
		int N, S;	
		scanf("%d %d", &N, &S);
		for(int i = 1; i <= N; i++){
			scanf("%d", &a[i]);
		}
		presum[0] = 0;
		for(int i = 1; i <= N; i++){
			presum[i] = presum[i-1] + a[i];
		}
		if(presum[N] < S){
			printf("0\n");
			continue;
		}
		int i, j;
		int min = 100005;
		for(i = 1, j = 1; i <= N && j <= N;){
			if(presum[j] - presum[i-1] >= S){
				if(j-i+1 < min){
					min = j - i + 1;
				}
				i++;
			} else {
				j++;
			}	
		}
		printf("%d\n", min);
	}	
	return 0;
}
