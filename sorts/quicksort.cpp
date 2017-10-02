/*递归版本*/
#include <iostream>

using namespace std;

int Partition(int r[], int low, int high);
void qsort(int r[], int s, int t);
void QuickSort(int r [], int len);

int main()
{
    int len;
    cout << "length:";
    cin >> len;
    len += 1;
    int a[len];
    for(int i = 1; i < len; i++)
        cin >> a[i];
    QuickSort(a, len);
    cout << "Output:";
    for(int i = 1; i < len; i++)
        cout << a[i] << " ";
    cout << endl;
}

int Partition(int r[], int low, int high)
{
    //返回枢轴所在位置
    r[0] = r[low]; //r[0]临时储存r[low],也即pivotkey的值,以便以后保存回正确位置
    int pivotkey = r[low];
    while(low < high){
        while(low < high && r[high] >= pivotkey)//对于大于pivotkey的high不处理
            high -= 1;
        if(low < high)//直到pivotkey小于high的值或high减到low了停止，并判断
            r[low++] = r[high]; //如果为第二种情况，则交换low所指元素与该元素

        while(low < high && r[low] <= pivotkey)//low大致一样
            low += 1;
        if(low < high)
            r[high--] = r[low];
    }
    r[low] = r[0];  //将现在low所指位置改为原来的pivotkey,
                    //也即前面的都小于pivotkey,后面的都大于pivotkey
    return low;
}

void qsort(int r[], int s, int t)
{
    if(s < t){
        int pivotloc = Partition(r, s, t);
        qsort(r, s, pivotloc-1);
        qsort(r, pivotloc + 1, t);
    }
}

void QuickSort(int r [], int len)
{
    qsort(r, 1, len-1);
}
