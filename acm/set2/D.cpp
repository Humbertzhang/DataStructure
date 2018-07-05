#include <iostream>
using namespace std;
int main(){
	int n;
	cin >> n;
	for(int t = 0; t < n; t++){
		int size;
		cin >> size;
		int a[1001] = {0};
		for(int j = 0; j < size; j++){
			cin >> a[j];
		}
		/*正序*/
		int countasc = 0;
		for(int i = 0; i < size; i++){
			int flag = 0;
			for(int j = size-1; j >= i+1; j--){
				if(a[j] < a[j-1]){
					countasc += 1;
					flag = 1;
					int temp = a[j-1];
					a[j-1] = a[j];
					a[j] = temp;
				}
			}
			if(flag == 0){
				break;
			}
		}

		/*逆序*/
		int countdesc = 0;
		for(int i = 0; i < size; i++){
			int flag = 0;
			for(int j = size-1; j >= i+1; j--){
				if(a[j] > a[j-1]){
					countdesc += 1;
					flag = 1;
					int temp = a[j-1];
					a[j-1] = a[j];
					a[j] = temp;
				}
			}
			if(flag == 0){
				break;
			}
		}
		cout << "Scenario #" << t+1 << ":" << endl;
		if(countasc >= countdesc){
			cout << countdesc << endl;
		}else{
			cout << countasc << endl;
		}
		cout << endl;
	}
	return 0;
}
