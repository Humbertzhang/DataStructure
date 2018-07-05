/*为了学校成为偶像..什么鬼*/
#include<iostream>
#include <stdlib.h>
#include <algorithm>
#include <stdio.h>
using namespace std;

int getd(int a, int b, int c);
int mybfind(int * a, int start, int end, int num);

int a[100005], b[100005], c[100005];
int n, m, l;

int main()
{
	cin >> n >> m >> l;
	for(int i = 0; i < n; i++){
		scanf("%d", &a[i]);
	}
	for(int i = 0; i < m; i++){
		scanf("%d", &b[i]);
	}
	for(int i = 0; i < l; i++){
		scanf("%d", &c[i]);
	}
	sort(a, a+n);
	sort(b, b+n);
	sort(c, c+n);
	int d = getd(a[0], b[0], c[0]);
	for(int i = 0; i < n; i++){
		int bindex = mybfind(b, 0, n-1, a[i]);
		int cindex = mybfind(c, 0, l-1, a[i]);
		int dt = getd(a[i], b[bindex], c[cindex]);
		if(dt < d){
			d = dt;
		}
	}
	cout << d << endl;
	return 0;
}

int getd(int a, int b, int c)
{
	return abs(a-b) + abs(b-c) + abs(c-a);
}

int mybfind(int * a, int start, int end, int num)
{
	while(start <= end){
		if(end - start == 1){
			int n1 = abs(a[start] - num);
			int n2 = abs(a[end] - num);
			return n1 < n2 ? start : end;
		}
		int mid = start + (end-start)/2;
		if(a[mid] == num) {
			return mid;
		}
		else if(a[mid] > num){
			end = mid-1;
		}
		else{
			start = mid + 1;
		}
	}

}
