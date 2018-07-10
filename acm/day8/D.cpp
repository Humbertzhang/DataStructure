#include <iostream>
#include <stdio.h>
#include <set>
#include <vector>
using namespace std;

int page;
set<int> st;
int ideas[1000005];
int pre[1000005];

int main()
{
	cin >> page;
	for(int i = 1; i <= page; i++){
		scanf("%d", &ideas[i]);
	}
	pre[0] = 0;
	for(int i = 1; i <= page; i++){
		if(st.find(ideas[i]) == st.end()){
			pre[i] = pre[i-1] + 1;
			st.insert(ideas[i]);
		} else {
			pre[i] = pre[i-1];
		}
	}
	
	for(int i = 1; i <= page; i++){
		cout << "pre" << i << ":" << pre[i] << endl;
	}
		
	int max = pre[page];	
	int i, j;
	int minlen = 1000005;
	for(i = 1, j = 1; i <= page && j <= page; ){
		if(pre[j] - pre[i-1] >= max){
			if(j-i+1 < minlen){
				minlen = j-i+1;
			}
			i+=1;	
		} else {
			j+=1;
		}
	}
	cout << minlen << endl;	
	return 0;
}
