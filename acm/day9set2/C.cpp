#include <iostream>
#include <algorithm>
using namespace std;

int n, a, b;

int main() {
    cin >> n >> a >> b;

    int ap = 0, bp = 0, pnum = 0;
    for (int i = 1; i <= a; i++) {
        ap = a / i;
        for (int j = 1; j <= b; j++) {
            bp = b / j;
            if (ap + bp >= n) {
                int newpnum = min(i, j);
                if (newpnum > pnum) {
                    pnum = newpnum;
                }
            }
        }
    }
    cout << pnum << endl;
    return 0;
}
