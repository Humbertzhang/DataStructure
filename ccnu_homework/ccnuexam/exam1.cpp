/**
 *1,一个接近排序完成的数组的排序（插入排序）
 *2,在排序完成后的数组中如何最搞效率查找一个元素（二分查找）
 */
#include <iostream>
using namespace std;

void InsertSort(int *a, int len);
//二分查找
int Find(int * sorted, int len, int start, int end, int obj);

int main() {
    //第一位为哨兵数据
    int tableT[16] = {0, 119, 120, 100, 95, 89, 88, 56, 87, 45, 31, 12, 10, 8, 5 ,1};
    InsertSort(tableT, 15);
    //int sorted[15] = {0};
    //Msort(tableT, sorted, 0, 14);
    for(int i = 1; i <= 15; i++){
        cout << tableT[i] << " ";
    }
    cout << endl;
    int obj = 56;
    int sorted[] = {120, 119, 100, 95, 89, 88, 87, 56, 45, 31, 12, 10, 8, 5, 1};
    int index = Find(sorted, 15, 0, 14, 56);
    cout << "index:" << index <<endl;
}

void InsertSort(int *a, int len)
{
    int i, j;
    for(i = 2; i <= len; i++){
        if(a[i] > a[i-1]){
            a[0] = a[i];
            for(j = i-1; a[0] > a[j]; --j){
                a[j+1] = a[j];
            }
            a[j+1] = a[0];
        }
    }
}

int Find(int * sorted, int len, int start, int end, int obj)
{
    int mid = len/2;
    if(sorted[mid] == obj){
        return mid;
    }
    else if(sorted[mid] > obj){
        return Find(sorted, mid - start, start, mid, obj);
    }
    else if(sorted[mid] < obj){
        return Find(sorted, end - mid, mid, end, obj);
    }
}
