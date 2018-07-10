/*尺取法*/
#include <iostream>
using namespace std;

char a[8] = {'a', 'a', 'b', 'c', 'd', 'e', 'f', 'g'};
int check(int start, int end)
{
	int m[26] = {0};
	for(int i = start; i <= end; i++){
		m[a[i] - 'a'] = 1;
	}
	int count = 0;
	for(int i = 0; i < 26; i++){
		count += m[i];
	}
	return count;
}

int main() {
	int n = 8;
	int reqkind = 4;
	int i, j;
	int kind = 0;
	for(i = 0, j = 0; i < n && j < n;) {
		int result = check(i, j);
		if(result < reqkind) {
			j+=1;
		}
		else if(result > reqkind) {
			i+= 1;
		}
		else{
			cout << "i:" << i << " j:" << j << endl;	
			i += 1;
		}
	}

}
