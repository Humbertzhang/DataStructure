#include <iostream>

using namespace std;
//这种扫描办法为单向扫描,与quicksort.cpp中不同.
int partition(int arr[], int l, int h)
{
    int x = arr[h];
    int i = l - 1;
    for(int j = 1;j<=h-1;j++){
        if(arr[j] <= x){
            i++;
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[i+1], arr[h]);
    return (i+1);
}

void quickSort(int a[], int l, int h)
{
    int stack[h - l + 1];
    int top = -1;
    //push initial values of 1 and h to stack
    stack[++top] = l;
    stack[++top] = h;
    while(top >= 0)
    {
        h = stack[top--];
        l = stack[top--];
        int p = partition(a, l, h);
        //if there are elements on left side of pivot
        //then push left side to stack
        if(p-1 > l)
        {
            stack[++top] = l;
            stack[++top] = p - 1;
        }
        if(p+1 < h)
        {
            stack[++top] = p+1;
            stack[++top] = h;
        }

    }
}

int main()
{
    int len;
    cout << "length:";
    cin >> len;
    len += 1;
    int a[len];
    for(int i = 1; i < len; i++)
        cin >> a[i];
    quickSort(a, 1, len);
    for(int i = 1; i < len; i++)
        cout << a[i] << " ";
    cout << endl;
}
