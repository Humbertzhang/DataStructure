#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> v;
    while(true){
        int n;
        cin >> n;
        if(n == 0) break;
        while(true){
            v.clear();

            int num;
            cin >> num;
            if(num == 0){
                cout << endl;
                break;
            }
            int countnum = 1;
            for(int i = 1; i <= n; i++){
                v.push_back(i);
                if(v.back() == num){
                    v.pop_back();
                    while(countnum < n){
                        cin >> num;
                        countnum += 1;
                        if(v.back() == num) {
                            v.pop_back();
                        } else {
                            break;
                        }
                    }
                }
            }
            if(countnum < n) {
                cout << "No" << endl;
            } else {
                cout << "Yes" << endl;
            }
            for(int i = countnum; i < n; i++){
                cin >> num;
            }
        }
    }

}
