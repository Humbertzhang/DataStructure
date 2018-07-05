#include <iostream>
using namespace std;
int my_pow(int a, int b){
	int t = my_pow(a, b/2);
	if(b%2 == 1) return t*t*a;
	else return t*t;
}
int main(){
	int a = my_pow(2, 10);
	cout << a << endl;
}
