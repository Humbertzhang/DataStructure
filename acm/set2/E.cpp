#include <iostream>
#include <stdio.h>
using namespace std;
int main() {
    int T;
    cin >> T;
    while(T--){
        int n, m;
        cin >> n >> m;
        float median;
        int a[n+1] = {0};
        for(int i = 1; i <= n; i++){
            cin >> a[i];
        }
        for(int j = 0; j < m; j++){
            int l1, r1, l2, r2;
            cin >> l1 >> r1 >> l2 >> r2;
            int length = (r1-l1+1) + (r2-l2+1);
            int b[length] = {0}; 
            int p = l1,q = l2, i = 0;
            while(p <= r1 || q <= r2){
                if(p <= r1 && q <= r2) {
                    if (a[p] >= a[q]) {
                        b[i++] = a[q];
                        q += 1;
                    } else {
                        b[i++] = a[p];
                        p += 1;
                    }
                } else if(p <= r1 && q > r2) {
                    int k;
					for(k = p; k <= r1; k++){
                        b[i++] = a[k];
                    }
                    p = k;
                } else if(q <= r2 && p > r1) {
                    int k;
					for(k = q; k<=r2; k++) {
                        b[i++] = a[k];
                    }
                    q = k;
                }
            }
            if(length % 2 == 1){
                median = b[length/2];
            } else {
                median = float(b[length/2]) + float(b[(length/2)-1])/2;
            }
			printf("%.1f", median);
        }
    }

    return 0;
}
