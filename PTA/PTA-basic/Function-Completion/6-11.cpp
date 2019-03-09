#include <stdio.h>

#define MAXN 10
typedef float ElementType;

ElementType Median( ElementType A[], int N );

int main ()
{
    ElementType A[MAXN];
    int N, i;

    scanf("%d", &N);
    for ( i=0; i<N; i++ )
        scanf("%f", &A[i]);
    printf("%.2f\n", Median(A, N));

    return 0;
}
ElementType Median( ElementType A[], int N )
{
  int ans = 0;
  int left = 0, right = N - 1;
  ElementType key = A[left];
  while(ans != N/2)
  {
    while(A[right] >= key && right > left)
      right--;
    A[left] = A[right];
    while(A[left] <= key && left < right)
      left++;
    A[right] = A[left];
    if(left == right)
    {
//    printf("l:%d  r:%d ans=%d: [%f] key-->%f\n", left, right, ans, A[ans], key);
      A[left] = key;
      ans = left;
      if(ans > N/2)
      {
        left = 0;
        right--;
      }
      else
      {
        right = N - 1;
        left++;
      }
//	  ElementType key = A[left];   //once again declation key lead to put error,
							       //because of above key haven't use the value of key variable.
	  key = A[left];		// this is change value above declation key.
//	  printf("-----l:%d  r:%d key: %f\n", left, right, key);
    }
  }
/*  for(int i = 0; i < N; i++)
	  printf("%f ", A[i]);
*/ 
 return A[ans];
}
