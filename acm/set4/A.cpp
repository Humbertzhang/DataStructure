#include <iostream>
#include <stdio.h>
using namespace std;

int check(int money);

int n, m;
int money[100005];

int main()
{
	cin >> n >> m;
	for(int i = 0; i < n; i++){
		scanf("%d", &money[i]);
	}
	int max = money[0], sum = 0;
	for(int i = 0; i < n; i++){
		if(money[i] > max){
			max = money[i];
		}
		sum += money[i];
	}
	if(check(max)){
		cout << max << endl;
		return 0;	
	}
	int l = max, r = sum;
	while(r-l > 1){
		int mid = (r+l)/2;
		if(check(mid)){
			r = mid;
		} else {
			l = mid;
		}
	}
	cout << r << endl;
	return 0;
}

int check(int maxb)
{
	int sum = 0;
	int cnt = 0;
	for(int i = 0; i < n; i++){
		if(sum + money[i] > maxb){
			sum = 0;
			cnt += 1;
			sum += money[i];
		} else {
			sum += money[i];
		}
	}
	cnt += 1;	
	return cnt <= m; 
}
