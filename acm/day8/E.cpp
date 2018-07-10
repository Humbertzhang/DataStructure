#include <iostream>
#include <algorithm>

using namespace std;

int a[100005];
int pre[100005];

int main()
{
	while(true){
		int n, k;
		cin >> n >> k;
		if(n == 0 && k == 0){
			break;
		}
		for(int i = 1; i <= n; i++){
			scanf("%d", &a[i]);
		}
		
		for(int i = 1; i <= n; i++){
			pre[i] = pre[i-1] + a[i];
		}

		for(int i = 1; i <= k; i++){
			int t;
			cin >> t;

			int l,r;
			int minnum = 1000000001;
			int minl, minr;
			for(l = 1, r = 1; l <= n && r <= n; ){
				if(abs(abs(pre[r] - pre[l-1])-t) <= minnum){
					minnum = abs(abs(pre[r] - pre[l-1])-t);
					minl = l; minr = r;

					if(a[r+1] > 0){
						
					}
				}			
			}
		}

	}

	return 0;
}
