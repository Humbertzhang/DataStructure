#include <iostream>
using namespace std;
int main(){
	int num;
	cin >> num;
	int a[num] = {0};
	for(int i = 0; i < num; i++){
		cin >> a[i];
	}
	for(int i = 0; i < num; i++){
		int key = a[i];
		int j = i-1;
		while(j >= 0 && a[j] > key){
			a[j+1] = a[j];
			j--;
		}
		a[j+1] = key;

		for(int k = 0; k < num; k++){
			cout << a[k];
			if(k != num-1){
				cout << " ";
			} else {
				cout << endl;
			}
		}
	}
	return 0;
}
