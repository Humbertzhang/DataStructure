#include <iostream>
using namespace std;
int main() {
	int a, b;
	while(true){
		cin >> a >> b;
		if(a == 0 && b == 0){
			break;
		}
		int num = a*100;
		for(int i = 0; i < 100; i++){
			if((num + i) % b == 0){
				if(i >= 0 && i <= 9){
					cout << "0" << i;
				} else {
					cout << i;
				}

				// 尾数空格
				if(100 - i <= b){
					cout << endl;
				} else {
					cout << " ";
				}
			}
		}
	}
	return 0;
}
