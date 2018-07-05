#include <iostream>
using namespace std;
int main()
{
	int n;
	cin >> n;
	int a[102] = {0};
	for(int i = 0; i < n; i++){
		int num;
		cin >> num;
		a[num] += 1;
	}
	int max = a[0];
	for(int i = 0; i < 101; i++){
		if(a[i] > max){
			max = a[i];
		}
	}
	cout << max << endl;
	return 0;
}
