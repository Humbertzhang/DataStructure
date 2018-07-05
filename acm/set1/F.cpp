#include <iostream>
using namespace std;

int get_sysn_sum(int num, int n){
	int sum = 0;
	while(num){
		sum += num % n;
		num /= n;
	}
	return sum;
}

int issky(int num){
	int sys10 = get_sysn_sum(num, 10);
	int sys12 = get_sysn_sum(num, 12);
	int sys16 = get_sysn_sum(num, 16);
	if(sys10 == sys12 && sys12 == sys16){
		return 1;
	} else {
		return 0;
	}
}

int main(){
	int num;
	while(true){
		cin >> num;
		if(num == 0){
			break;
		}
		if(issky(num)){
			cout << num << " is a Sky Number." << endl;
		} else {
			cout << num << " is not a Sky Number." << endl;
		}
	}
	return 0;
}
