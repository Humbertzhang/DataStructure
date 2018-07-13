#include <iostream>
#include <vector>
using namespace std;

int a[105];

int main() {
    for(int i = 0; i < 105; i++){
        a[i] = 0;
    }

    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        int t1, t2;
        cin >> t1 >> t2;
        for(int j = t1; j < t2; j++){
            a[j] = 1;
        }
    }

    for(int i = 0; i < m; i++){
        if(a[i] == 0){
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
    return 0;
}
