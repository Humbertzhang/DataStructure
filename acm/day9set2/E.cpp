#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    int count1 = 0, count2 = 0;
    int pnum;
    int groupnum = 0;
    for(int i = 0; i < n; i++){
        cin >> pnum;
        if(pnum == 1){count1 += 1;}
        else if(pnum == 2){count2 += 1;}
    }
    if(count1 <= count2){
        cout << count1 << endl;
    } else {
        groupnum = groupnum + count2;
        count1 -= count2;
        groupnum = groupnum + count1/3;
        cout << groupnum << endl;
    }
    return 0;
}
