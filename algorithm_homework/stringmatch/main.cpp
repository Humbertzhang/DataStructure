#include <iostream>
#include <string.h>
#define STRBLEN 80

using namespace std;

int bf(char * a, char * b);
int kmp(char * a, char * b);
void getnext(char* a, char* next);

int bm(char* a, char* b, int alen, int blen);
void getBmGc(int* BmGc, char * T, int tlen);
void getsuff(int* suff, char * T, int tlen);
void getBmGs(int* suff, char * T, int tlen, int* BmGs);


int main()
{
	char* stra = "abcdefghijklmnopqrstuvwxyz";
	char strb[STRBLEN];
	int alen = 0, blen = 0;
	cout << "请输入待检查字段:";
	cin >> strb;
	while(stra[alen] != '\0'){
		alen += 1;
	}
	while(strb[blen] != '\0'){
		blen += 1;
	}

	int index1 = bf(stra, strb);
	//int index2 = -1;
	int index2 = kmp(stra, strb);
	int index3 = bm(stra, strb, alen, blen);
	cout << "BF:" << index1 << " KMP:" << index2 << " BM:" << index3 <<endl;
	return 0;
}

int bf(char * a, char * b)
{
	// a被匹配字符串，b匹配字符串
	int index = 0;
	int i = 0, j = 0; // i for a, j for b
	while(a[i] != '\0' && b[j] != '\0'){
		if(a[i] == b[j]){ 
			i += 1; 
			j += 1;
		} else {
			index += 1;
			i = index; // i回溯到index处
			j = 0; // j 回溯到b开始处
		}
	}
	if(b[j] == '\0'){
		return index + 1;
	}
	return 0;
}

void getnext(char* a, int* next){
	int j = 0, k = -1;
	next[0] = -1;
	while(a[j] != '\0'){
		if(k == -1){ //初始情况
			next[++j] = 0;
			k = 0;
		} else if (a[j] == a[k]) {
			k += 1;
			next[++j] = k;
		} else {
			k = next[k];
		}
	}
}

int kmp(char * a, char * b){
	int i = 0, j = 0;
	int next[80];
	getnext(b, next);
	while(a[i] != '\0' && b[j] != '\0'){
		if(a[i] == b[j]){
			i++; j++;
		} else {
			j = next[j];
			if(j == -1){  //第一个字符
				i++; j++;
			}
		}
	}
	if(b[j] == '\0'){
		return (i - strlen(b) + 1);
	}
	return 0;
}

int bm(char* a, char* T, int alen, int tlen) {
	int BmGc[256] = {0};
	int BmGs[tlen + 2] = {0};
	int suff[tlen + 2] = {0};
	getBmGc(BmGc, T, tlen);
	getBmGs(suff, T, tlen, BmGs);

	int i, j;
	for(j = 0; j <= alen - tlen; ) {
		for(i = tlen-1; i >= 0 && a[j+i] == T[i]; i--) ;
		if(i < 0){
			return j+1;
		}else{
			j += max(BmGs[i],BmGc[a[i+j]]-tlen+1+i);
		}
	}
	return -1;
}

void getBmGc(int* BmGc, char* T, int tlen) {
	for(int i = 0; i < 256; i++){
		BmGc[i] = tlen;
	}
	for(int i = 0; i < tlen; i++) {
		BmGc[T[i]] = tlen - 1 - i;
	}
}

void getsuff(int* suff, char * T, int tlen) {
	suff[tlen - 1] = tlen;
	for(int i = tlen-2; i >= 0; i--) {
		int tmp = i;
		while (tmp >= 0 && T[tmp] == T[tlen-1-i+tmp])
			tmp--;
		suff[i] = i - tmp;
	}
}

void getBmGs(int* suff, char * T, int tlen, int* BmGs) {
	getsuff(suff, T, tlen);
	for (int i = 0; i < tlen; i++) {
		BmGs[i] = tlen;
	}
	int j = 0;
	for(int i = tlen-1; i>=0; i--) {
		if(suff[i] == i+1){
			for(; j < tlen - 1 - i; j++){
				if(BmGs[j] == tlen){
					BmGs[j] = tlen -i -1;
				}
			}
		}
	}
	for(int i = 0; i <= tlen-2; i++){
		BmGs[tlen-1-suff[i]] = tlen - i - 1;
	}
}