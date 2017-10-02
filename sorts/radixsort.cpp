#include <iostream>
#include <cstdio>
using namespace std;

void radixSort(int a[])
{
    int temp[10][10] = {0};//第二维为10，则每个位置相同的不能超过10个
    int order[10] = {0};
    int n = 1;
    while(n<=10){
		//针对某位数进行划分
        for(int i = 0; i < 10; i++){
            int lsd = (a[i]/n)%10;//得到某一位的数字
            temp[lsd][order[lsd]] = a[i];//将其放入相应的位置中
            order[lsd]+=1;//每一位的数字的个数加1
        }
        int k = 0;
		//根据划分进行排序
        for(int i = 0; i < 10; i++){
            if(order[i] != 0){
                for(int j = 0; j < order[i]; j++, k++){
                    a[k] = temp[i][j];//将a[]中的数字根据temp来一个个重新赋值
                }
            }
            order[i] = 0;//清零order
        }
        n*=10;//位数加一，比较上一位
    }
}

int main(void) { 
    int data[10] = {73, 22, 93, 43, 55, 14, 28, 65, 39, 81}; 
      
    printf("\n排序前: "); 
    int i;
    for(i = 0; i < 10; i++) 
        printf("%d ", data[i]); 

    putchar('\n'); 

    radixSort(data);
    
    printf("\n排序后: "); 
    for(i = 0; i < 10; i++) 
        printf("%d ", data[i]); 

    return 0; 
} 

