#include <iostream>
#include <ctime>

using namespace std;

void BF(int * a, int size);
void DP(int * a, int size);
void DC(int * a, int size);
int MaxSumDC(int *a, int left, int right);
void time_counter(void (*func)(int*, int), int* a, int size, string method);


int main() {
    int a[9] = {-2,1,-3,4,-1,2,1,-5,4};
    //int a[9] = {-1, -2, -10, -2, -3, -4, -9, -8, -1};
    time_counter(BF, a, 9, "蛮力法");
    time_counter(DP, a, 9, "动态规划法");
    time_counter(DC, a, 9, "分治法");
    return 0;
}

void time_counter(void (*func)(int*, int), int* a, int size, string method) {
    clock_t start, end;

    start = clock();
    func(a, size);
    end = clock();

    double time_used = end - start;
    cout << method << "用时为:" << time_used <<endl;
}


// 分治
void DC(int * a, int size) {
    int max = MaxSumDC(a, 0, size-1);
    cout << "最大子段和:" << max <<endl;
}

// left right 都是闭合的
int MaxSumDC(int *a, int left, int right) {
    int leftsum = 0, rightsum = 0, midsum = 0;
    // 左等于右
    if(left == right) {
        return a[left];
    }
    //else
    int mid = (left + right) / 2;
    leftsum = MaxSumDC(a, left, mid);
    rightsum = MaxSumDC(a, mid+1, right);

    // midsum
    // left part
    int lsum = 0, maxleft = 0;
    for(int i = mid; i >= left; i--){
        lsum += a[i];
        if(maxleft < lsum){
            maxleft = lsum;
        }
    }
    // right part
    int rsum = 0, maxright = 0;
    for(int i = mid+1; i <= right; i++){
        rsum += a[i];
        if(maxright < rsum){
            maxright = rsum;
        }
    }
    midsum = maxleft + maxright;
    return max(max(leftsum, rightsum), midsum);
}

// 动态规划
void DP(int * a, int size) {
    int ans = 0, sum = 0;
    for(int i = 0; i < size; i++){
        sum += a[i];
        ans = max(sum, ans);
        // 只有sum < 0 时才有必要重置sum 为0
		// 因为所求为最大子段和, 故当大于0时对子段和的增加
		// 是有利的，只有当小于0时才有必要重新置0
        sum = max(sum, 0);
    }
    cout << "最大子段和:" << ans <<endl;
}

// 暴力
void BF(int * a, int size) {
    int max = 0;
    for(int i = 1; i <= size; i++){  //子段和长度
        for(int j = 0; j < size-i; j++) {    //起始位置
            int sum = 0;
            for(int k = j; k < j+i; k++) {
                sum += a[k];
            }
            if(sum > max){
                max = sum;
            }
        }
    }
    if(max < 0){
        max = 0;
    }
    cout << "最大子段和:" << max <<endl;
}

