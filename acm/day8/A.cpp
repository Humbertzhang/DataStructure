#include <iostream>
#include <string>
using namespace std;

string s;

int check(int start, int end){
	char a[26] = {0};
	for(int i = start; i <= end; i++){
		a[s[i]-'A'] = 1;
	}
	int count = 0;
	for(int i = 0; i < 26; i++){
		count += a[i];
	}
	return count;
}

int main()
{
	cin >> s;
	int slen = s.length();
	int minlen = slen + 1;
	int i, j;
	for(i = 0, j = 0; i < slen && j < slen; ) {
		int checked = check(i, j);
		if(checked < 26){
			j += 1;
		} else {
			if(j-i+1 < minlen){
				minlen = j-i+1;
			}
			i += 1;
		}
	}
	if(minlen != slen + 1){
		cout << minlen << endl;
	} else {
		cout << "No Solution" << endl;
	}
	return 0;
}
