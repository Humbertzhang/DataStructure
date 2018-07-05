#include <iostream>
#include <string>

using namespace std;
int main() {
	int n;
	cin >> n;
	for(int i = 0; i < n; i++) {
		string s;
		cin >> s;
		int isp = 1;		
		for(int i = 0; i < s.length()/2; i++){
			if(s[i] != s[s.length()-i-1]) {
				isp = 0;
				break;
			}
		}
		if(isp){
			cout << "yes" << endl;
		} else {
			cout << "no" << endl;
		}
	}
	return 0;
}
