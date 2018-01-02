#include <iostream>

using namespace std;

void InsertSort(int * a, int len)
{
    int i, j;
    for(i = 2; i <= len; i++){
        if(a[i] < a[i-1]){
            a[0] = a[i];
            for(j = i-1; a[0] < a[j]; --j){
                a[j+1] = a[j];
            }
            a[j+1] = a[0];
        }
    }
}

int main()
{
    int a[] = {0,1,4,5,-2,-113,314,21,43,563,12};
    InsertSort(a, 10);
    for(int i = 1; i <= 10; i++){
        cout << a[i] << " ";
    }
    return 0;
}
