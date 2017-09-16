#include <stdio.h>

 
void MaxSubseqSum(int *a,int N)//最大子列函数，在线处理
{
    int i=0;
    int pos=0;
    int maxSum=0;
    int thisSum=0;
    int start=0;
    int stop=0;
    start=i;
    for(i;i<N;i++)
    {
        thisSum+=a[i];
        if(thisSum>maxSum)
        {
            maxSum=thisSum;
            start=pos;
            stop=i;
        }
        else if(thisSum<0)
        {
            thisSum=0;
            pos=i+1;
        }
    }
    printf("%d %d %d", maxSum, a[start], a[stop]);
    return;
}
 

int main()
{
  int K;
  scanf("%d",&K);
  int A[K];
  int aneg = 1, allzero = 1;
  for(int i = 0; i < K; i++){
    scanf("%d", &A[i]);

    if(A[i] > 0){
        aneg = 0;
        allzero = 0;
    }
    
    if(A[i] == 0){
        aneg = 0;
    }

    else if(A[i] < 0)
        allzero = 0;

  }

  if(aneg){
    printf("0 0 %d",K);
    return 0;
  }

  if(allzero){
    printf("0 0 0");
    return 0;
  }

  MaxSubseqSum(A, K);
  return 0;
}
