#include <iostream>
#include <map>
#include <stdio.h>
using namespace std;
map<char, char> cmap;

int getstrlen(char *str){
	int i = 0;
	while(true){
		if(str[i] == '\0'){
			break;
		}
		i += 1;	
	}
	return i;
}

int is_reg_pali(char *str) {
	int strlen = getstrlen(str);
   	for(int i = 0; i < strlen/2; i++){
		if(str[i] != str[strlen-i-1]){
			return 0;
		}
	}
	return 1;
}

int is_mirr_str(char *str) {
	int strlen = getstrlen(str);
	char str2[100];
	int flag = 1;
	for(int j = 0; j < strlen/2; j++){
		if(str[j] != cmap[str[strlen-j-1]]){
			flag = 0;
			break;
		}
	}
	
	if(strlen % 2 == 1){
		if(str[strlen/2] != cmap[str[strlen/2]]){
			flag = 0;
		}
	}
	if(flag){
		return 1;
	}
	return 0;
}

int main() {
	cmap['A'] = 'A'; cmap['E'] = '3'; cmap['H'] = 'H'; cmap['I'] = 'I';
	cmap['J'] = 'L'; cmap['L'] = 'J'; cmap['M'] = 'M'; cmap['O'] = 'O';
	cmap['S'] = '2'; cmap['T'] = 'T'; cmap['U'] = 'U'; cmap['V'] = 'V';
	cmap['W'] = 'W'; cmap['X'] = 'X'; cmap['Y'] = 'Y'; cmap['Z'] = '5';
	cmap['1'] = '1'; cmap['2'] = 'S'; cmap['3'] = 'E'; cmap['5'] = 'Z';
	cmap['8'] = '8';

	char str[100];
	while((scanf("%s", str)) != EOF){
		getchar();
		int regpali = is_reg_pali(str);
		int mirrstr = is_mirr_str(str);
		if(regpali==1 && mirrstr==1){
			cout << str << " -- is a mirrored palindrome." << endl;
		} else if(mirrstr==1 && regpali==0) {
			cout << str << " -- is a mirrored string." << endl;
		} else if(regpali==1 && mirrstr == 0) {
			cout << str << " -- is a regular palindrome." << endl;
		} else {
			cout << str << " -- is not a palindrome." << endl;
		}
		cout << endl;
	}
	return 0;
}
