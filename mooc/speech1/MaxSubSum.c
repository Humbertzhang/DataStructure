#include <stdio.h>

long long int MaxSubseqSum4(long long int A[], long long int N)
{
    int ThisSum, MaxSum;
    int i;
    ThisSum = MaxSum = 0;
    for(int i=0; i < N; i++) {
    	ThisSum += A[i];        //向右累加
        if (ThisSum > MaxSum)   //大于MaxSum则令MaxSum = ThisSum
        	MaxSum = ThisSum;
        else if(ThisSum < 0)    //若小于零则如果加下去只会更小
        	ThisSum = 0;        //故抛弃不要
    }
    return MaxSum;
}

int main()
{
  long long int K;
  scanf("%lld",&K);
  long long int A[K];
  for(long long int i = 0; i < K; i++){
    scanf("%lld", &A[i]);
  }
  long long int out = MaxSubseqSum4(A, K);
  printf("%lld", out);
}
