#include <iostream>
using namespace std;

int main()
{
	char a[1005] = {0};
	cin >> a;
	int num = 0;
	for(int i = 0; i < 1003; i++){
		num = num + a[i] - '0';
	}
	while(num >=10) {
		int sum = 0;
		while(num){
			int d = num % 10;
			sum += d;
			num /= 10;
		}
		num = sum;
	}
	cout << num << endl;
	return 0;
}
