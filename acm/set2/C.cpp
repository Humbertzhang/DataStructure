#include <iostream>
using namespace std;
int main(){
	int n;
	cin >> n;
	int a[101];
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	int swapc = 0;
	for(int i = 0; i < n; i++){
		int mini = i;
		for(int j = i; j < n; j++){
			if(a[j] < a[mini]){
				mini = j;
			}
		}
		if(mini != i){
			int temp = a[i];
			a[i] = a[mini];
			a[mini] = temp;
			swapc += 1;
		}
	}
	for(int i = 0; i < n; i++){
		cout << a[i];
		if(i != n-1){
			cout << " ";
		}else{
			cout << endl;
		}
	}
	cout << swapc << endl;
	return 0;
}
