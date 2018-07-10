/*前缀和*/
#include <iostream>
using namespace std;

int main()
{
	int n = 8;
	int a[8] = {4, 7, 8, 9, 5, 4, 6, 2};
	int pre[9] = {0};

	// pre[i] : a[1]到a[i]数的和, 左右都是闭区间
	for(int i = 1; i <= n-1; i++) {
		pre[i] = pre[i-1] + a[i];
	}
	int max = pre[5] - pre[1];
	for(int i = 0, j = i + 4; i <= n-4-1; i++, j++) {
		if(pre[j] - pre[i] > max){
			max = pre[j] - pre[i];
		}
	}
	cout << max << endl;
}
