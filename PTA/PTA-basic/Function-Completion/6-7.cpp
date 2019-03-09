#include <stdio.h>
#include <math.h>

int IsTheNumber ( const int N );

int main()
{
    int n1, n2, i, cnt;
	
    scanf("%d %d", &n1, &n2);
    cnt = 0;
    for ( i=n1; i<=n2; i++ ) {
        if ( IsTheNumber(i) )
            cnt++;
    }
    printf("cnt = %d\n", cnt);

    return 0;
}

/* 你的代码将被嵌在这里 */
int IsTheNumber ( const int N )
{
  if((int)sqrt(N)*sqrt(N) == N)
  {
    int a[10] = {0};
    int N_ = N;
    while(N_)
    {
      if(a[N_ % 10] == 1)
        return 1;
      a[N_ % 10] = 1;
      N_ /= 10;
    }
  }
  return 0;
}