#include <iostream>
#include <stdio.h>
#include <set>
#include <map>
#include <algorithm>
using namespace std;

int page;
set<int> st;
int ideas[1000005];

int main()
{
	cin >> page;
	for(int i = 0; i < page; i++){
		scanf("%d", &ideas[i]);
		st.insert(ideas[i]);
	}	
	
	int unideas = st.size();
	int sum = 0;
	int i = 0, j = 0;
	int minlen = 1000005;
	map<int, int> mp;
	while(true){
		while(j < page && sum < unideas){
			if(mp[ideas[j]] == 0){
				sum += 1;
			}
			mp[ideas[j]] += 1; j+=1;
		}
		if(sum < unideas){
			break;
		}
		minlen = min(minlen, j-i);
		
		mp[ideas[i]] -= 1;
		if(mp[ideas[i]] == 0){
			sum -= 1;
		}
		i+=1;
	}
	cout << minlen << endl;	
	return 0;
}

