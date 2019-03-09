#include <stdio.h>

void Print_Factorial ( const int N );

int main()
{
    int N;
	
    scanf("%d", &N);
    Print_Factorial(N);
    return 0;
}

/* 你的代码将被嵌在这里 */
void Print_Factorial ( const int N )
{
  if(N < 0 || N > 1000)
    printf("Invalid input");
  else if(N == 0 || N == 1)
    printf("%d", 1);
  else{
    int a[1000] = {0};
    a[0] = 1;
    int mark = 0, d;
    for(int i = 2; i <= N; i++)
    {
      d = 0;
      for(int j = 0; j <= mark; j++)
      {
        a[j] = a[j] * i + d;
        d = a[j]/1000000;
        if(a[j] >= 1000000)
        {
//          d = a[j]/1000000;   //carry ; no carry ; error
          a[j] %= 1000000;		//each bit of array save six number.
          if(mark < j + 1)
            mark++;
        }
      }
    }
    printf("%d", a[mark]);
    while(mark--)
      printf("%06d", a[mark]);
  }
}