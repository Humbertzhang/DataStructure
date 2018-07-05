#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;

void flip(vector<int>& a, int ope);
int getmax(vector<int>& a, int size);

int main()
{
    string line;
    while(getline(cin, line)) {
        stringstream ss(line);
        vector<int> a;
        int num;
        int i = 0;
        int max, min;
        while(ss >> num){
            a.push_back(num);
            if(i == 0){
                max = i;
                min = i;
            } else {
                if(a[i] > a[max]){
                    max = i;
                }
                if(a[i] < a[min]){
                    min = i;
                }
            }
            i += 1;
        }
        int size = a.size();
        for(int i = 0; i < size; i++){
            cout << a[i];
            if(i != size - 1){
                cout << " ";
            } else {
                cout << endl;
            }
        }
        int mined = 0;
        int realmax = a[getmax(a, size)];
        while(size!=1){
            int ope = 0;
            max = getmax(a, size);
            if(max == size - 1){
                ;
            } else if (max == 0) {
                ope = mined + 1;
                flip(a, ope);
                cout << ope << " ";
            } else {
                ope = mined + size - max;
                flip(a, ope);
                cout << ope << " ";
                ope = mined + 1;
                flip(a, ope);
                cout << ope << " ";
            }
            size -= 1;
            mined += 1;
        }
        cout << 0 << endl;
    }
    return 0;
}



void flip(vector<int>& a, int ope)
{
    reverse(a.begin(), a.end());
    reverse(a.begin() + ope -1, a.end());
    reverse(a.begin(), a.end());
}

int getmax(vector<int>& a, int size)
{
    int max = 0;
    for(int i = 0; i < size; i++){
        if(a[i] > a[max]){
            max = i;
        }
    }
    return max;
}
