#include <iostream>

using namespace std;

void BubbleSort(int* a, int len)
{
    int i, j;
    for(i = 0; i < len-1; i++){
        int flag = 0;
        for(int j = 0; j < len-i-1; j++){
            if(a[j] > a[j+1]){
                flag = 1;
                int temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
        if(flag == 0){
            break;
        }
    }
}

int main()
{
    int a[] = {1,4,5,-2,-113,314,21,43,563,12};
    BubbleSort(a, 10);
    for(int i = 0; i < 10; i++){
        cout << a[i] << " ";
    }
    return 0;
}
