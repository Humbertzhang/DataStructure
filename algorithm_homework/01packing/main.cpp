#include<stdio.h>
#define N 3

int c=30;               //背包容量
int w[]={20,15,15};     //对象重量数组
int v[]={40,25,25};     //对象收益数组
int cw;                 //当前背包重量
int cv;                 //当前背包价值
int bestv;              //迄今最大的收益
int X[N];               //记录在树中的移动路径,为1的时候表示选择该组数据，为0的表示不选择该组数据
int node = 0;

void getBest(int i)
{
    node += 1;
    if(i>=N)            //递归结束的判定条件
    {
        if(cv>bestv)
            bestv=cv;
        return;
    }

    if(cw+w[i] <= c)    //进入该节点的右孩子（值为1的孩子）
    {
        X[i]=1;
        cw+=w[i];
        cv+=v[i];
        getBest(i+1);
        cw-=w[i];       //此处回溯
        cv-=v[i];
    }

    X[i]=0;             //进入该节点的右孩子（值为0的孩子）
    getBest(i+1);
}

int main()
{
    getBest(0);
    printf("最大值:%d 节点数:%d", bestv, node);
    return 0;
}
