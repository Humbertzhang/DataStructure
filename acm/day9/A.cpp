#include <iostream>
#include <algorithm>
using namespace std;

int solution;
int n;
int y[10];

bool check(int row, int col){
	for(int i = 0; i < row; i++){
	if(y[i] == col || abs(y[i]-col) == row-i){
			return false;
		}
	}
	return true;
}

void dfs(int row){
	for(int col = 0; col < n; col++){
		if(check(row, col)){
			y[row] = col;
			if(row == n-1){
				solution += 1;
			} else {
				dfs(row+1);
			}
		}
	}
}

int Queen(int num){
	for(int i = 0; i < 10; i++){
		y[i] = 0;
	}
	solution = 0;
	n = num;
	dfs(0);
	return solution;
}


int main()
{
	int a[11];
	for(int i = 1; i <= 10; i++){
		a[i] = Queen(i);
	}
	while(true){
		int N;
		cin >> N;
		if(N == 0){
			break;
		}
		cout << a[N] << endl;
	}
	return 0;
}
