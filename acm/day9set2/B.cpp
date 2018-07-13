#include <iostream>
#include <vector>
using namespace std;

int a[100005];
vector<int> index;

int main() {
    int n;
    cin >> n;
    int min;
    for(int i = 0; i < n; i++){
        scanf("%d", &a[i]);
        if(i == 0){min = a[0];}
        else{
            if(a[i] < min){
                min = a[i];
            }
        }
    }

    for(int i = 0; i < n; i++){
        if(a[i] == min){
            index.push_back(i);
        }
    }
    int min2 = index[1] - index[0];
    for(int i = 1; i < index.size(); i++){
        if(index[i] - index[i-1] < min2){
            min2 = index[i] - index[i-1];
        }
    }
    cout << min2 << endl;

    return 0;
}
