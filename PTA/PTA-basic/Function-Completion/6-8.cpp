#include <stdio.h>

int Factorial( const int N );

int main()
{
    int N, NF;
	
    scanf("%d", &N);
    NF = Factorial(N);
    if (NF)  printf("%d! = %d\n", N, NF);
    else printf("Invalid input\n");

    return 0;
}

/* 你的代码将被嵌在这里 */
int Factorial( const int N )
{
  int ans = 1;
  if(N < 0)
    return 0;
  else if(N == 1 || N == 0)
    return 1;
  else
    for(int i = 2; i <= N; i++)
      ans *= i;
  return ans;
}