#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int a[15] = {0};
	int index = 0;
	for(int i = 0; i < 15; i++){
		cin >> a[i];
		if(a[i] == 0){
			break;
		}
		index = i;
	}
	sort(a, a+index+1);
	int counter = 0;
	for(int i = 0; i <= index; i++){
		for(int j = i; j <= index; j++){
			if(a[j]/a[i] == 2 && a[j]%a[i] == 0){
				counter += 1;
			}
		}
	}
	cout << counter << endl;
	return 0;
}

