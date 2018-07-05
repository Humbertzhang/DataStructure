#include <iostream>
using namespace std;
int main(){
	int n;
	cin >> n;
	char seats[1005];
	cin >> seats;
	if(n == 1 && seats[0] == '0'){
		cout << "No" << endl;
		return 0;
	}
	int pre = seats[0];
	int status = 1;

	for(int i = 1; i < n; i++){
		if(seats[i] == pre && seats[i] == '1'){
			status = 0;
			break;
		}
		if(i == 1){
			if(seats[i-1] == seats[i] && seats[i] == '0'){
				status = 0;
				break;
			}
		}
		if(i == n-2){
			if(seats[i] == seats[i+1] && seats[i] == '0'){
				status = 0;
				break;
			}
		}
		if(i > 0 && i < n-2){
			if(seats[i-1] == seats[i] && seats[i+1] == seats[i] && seats[i] == '0'){
				status = 0;
				break;
			}
		}
        pre = seats[i];
	}
	if(status == 1){
		cout << "Yes" << endl;
	} else {
		cout << "No" << endl;
	}
	return 0;
}

