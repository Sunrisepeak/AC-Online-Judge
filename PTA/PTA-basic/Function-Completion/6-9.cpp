#include <stdio.h>

int Count_Digit ( const int N, const int D );

int main()
{
    int N, D;
	
    scanf("%d %d", &N, &D);
    printf("%d\n", Count_Digit(N, D));
    return 0;
}

/* 你的代码将被嵌在这里 */
int Count_Digit ( const int N, const int D )
{
  int N_;
  if(N < 0)
    N_ = -N;
  else if(N == D)
    return 1;
  else
    N_ = N;
  int count = 0;
  while(N_){
    if(N_ % 10 == D)
      count++;
    N_ /= 10;
  }
  return count;
}