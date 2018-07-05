#include <iostream>
using namespace std;
int main(){
	int a[7];
	while(scanf("%d %d %d %d %d %d", a+1, a+2, a+3, a+4, a+5, a+6) != EOF){
		/******************/
		int notall0 = 0;
		for(int i = 1; i <= 6; i++){
			if(a[i] != 0){
				notall0 = 1;
				break;
			}
		}
		if(notall0 == 0){
			break;
		}
		/******************/
		int counter = 0;
		counter += a[6];
		if(a[5] != 0){
			counter += a[5];
			if(a[1] <= a[5]*11){
				a[1] = 0;
			} else {
				a[1] -= a[5]*11;
			}
		}

		if(a[4] != 0){
			counter += a[4];
			
		}



	}
	return 0;
}
