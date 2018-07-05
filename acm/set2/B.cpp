#include <iostream>
using namespace std;
int main(){
	int n;
	cin >> n;
	int a[n];
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	int swapc = 0;

	for(int i = 0; i < n; i++){
		for(int j = n-1; j >= i+1; j--){
			if(a[j] < a[j-1]){
				int temp = a[j-1];
				a[j-1] = a[j];
				a[j] = temp;
				swapc += 1;
			}
		}
	}
	for(int i = 0; i < n; i++){
		cout << a[i];
		if(i != n-1){
			cout << " ";
		} else {
			cout << endl;
		}
	}
	cout << swapc << endl;
	return 0;
}
