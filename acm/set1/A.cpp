#include <iostream>
using namespace std;

int main(){
	int n, m;
	while(true){
		cin >> n >> m;
		if(n == 0 && m == 0) {
			break;	
		}
		int a[n+1] = {0};
		int flag = 0;
		for(int i = 0; i < n+1; i++){
			cin >> a[i];
			if(a[i] >= m && flag == 0){
				for(int j = i+1; j <= n; j++){
					a[j] = a[j-1];
				}
				a[i++] = m;
				flag = 1;
			}
		}
		for(int i = 0; i < n+1; i++){
			cout << a[i];
			if(i == n){
				cout << endl;
			} else {
				cout << " ";
			}
		}

	}
	return 0;
}
