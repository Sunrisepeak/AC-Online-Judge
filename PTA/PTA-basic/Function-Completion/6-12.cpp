#include <stdio.h>

int even( int n );

int main()
{    
    int n;

    scanf("%d", &n);
    if (even(n))
        printf("%d is even.\n", n);
    else
        printf("%d is odd.\n", n);

    return 0;
}
// answer
int even( int n )
{
  return n % 2 == 0 ? 1 : 0;
}