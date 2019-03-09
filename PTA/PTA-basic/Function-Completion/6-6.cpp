#include <stdio.h>
#include <stdlib.h>

typedef struct Node *PtrToNode;
struct Node {
    int Data; /* 存储结点数据 */
    PtrToNode Next; /* 指向下一个结点的指针 */
};
typedef PtrToNode List; /* 定义单链表类型 */

int FactorialSum( List L );

int main()
{
    int N, i;
    List L, p;

    scanf("%d", &N);
    L = NULL;
    for ( i=0; i<N; i++ ) {
        p = (List)malloc(sizeof(struct Node));
        scanf("%d", &p->Data);
        p->Next = L;  L = p;
    }
    printf("%d\n", FactorialSum(L));

    return 0;
}

/* 你的代码将被嵌在这里 */
void InitArry(int *a)
{
  for(int i = 0; i <= 20; i++)
    a[i] = 1;
}
int Factorial(int a[], int begin, int end)
{
  int fac = a[begin];
  for(int i = begin + 1; i <= end; i++)
    fac *= i;
  return fac;
}
int FactorialSum( List L )
{
  int ans = 0;
  PtrToNode p = L;
  int a[20];
  InitArry(a);    //init a by '1'
  while(p != NULL)
  {
    if(p->Data > 1 && a[p->Data] == 1) //memory search deal with
    {
      int begin;
      for(begin = p->Data; begin > 1; begin--)//find begin of value have min_distance  between begin and end; 
        if(a[begin] != 1)
          break;
      a[p->Data] = Factorial(a, begin, p->Data);  //save memory
    }
    ans += a[p->Data];
    p = (*p).Next;  //note ‘*’ level of priority, function is moving to next node;
  }
  return ans;
}