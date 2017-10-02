#include <iostream>

using namespace std;

void Merge(int sr[], int tr[], int i, int m , int n);
void Msort(int sr[], int tr1[], int s, int t);
void MergeSort(int r[], int len);

int main()
{
    int len;
    cout << "length:";
    cin >> len;
    int a[len];
    for(int i = 0; i < len; i++)
        cin >> a[i];
    MergeSort(a, len);
    for(int i = 0; i < len; i++)
        cout << a[i] << " ";
    cout << endl;
}


//将sr[i->m] 和 sr[m+1->n] 归并为有序的tr[]
void Merge(int sr[], int tr[], int i, int m , int n)
{
    int j, k;
    //i控制前半部分, j控制后半部分, k控制tr
    for(j = m + 1,k = i; i <= m && j <= n; ++k){
        if(sr[i] <= sr[j])
            tr[k] = sr[i++];
        else
            tr[k] = sr[j++];
    }
    while(i <= m)
        tr[k++] = sr[i++];
    while(j <= n)
        tr[k++] = sr[j++];
}
void Msort(int sr[], int tr1[], int s, int t)
{
    int tr2[t-s+1];
    if(s == t)
        tr1[s] = sr[s];
    else{
        int m = (s+t)/2;
        Msort(sr, tr2, s, m);
        Msort(sr, tr2, m+1, t);
        Merge(tr2, tr1, s, m, t);
    }
}
void MergeSort(int r[], int len)
{
    Msort(r, r, 0, len-1);
}
