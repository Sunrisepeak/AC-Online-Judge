/*
*Problem	L1和L2是给定的带头结点的单链表，其结点存储的数据是递增有序的；
*函数Merge要将L1和L2合并为一个非递减的整数序列。应直接使用原序列中的结点，
*返回归并后的带头结点的链表头指针。
*
*
*合并后的链表 
*NULL
*NULL
*/
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
int flag = 1;
typedef int ElementType;
typedef struct Node *PtrToNode;
struct Node {
    ElementType Data;
    PtrToNode   Next;
};
typedef PtrToNode List;

List Read()
{
	List head, s;
	head = (List *)malloc(sizeof(struct Node));
	List r  = head;
	int i;
	for(i = 0; i < 5; i++)
	{
		s = (List *)malloc(sizeof(struct Node));
		s->Data = i*flag;
		r->Next = s;
		r = r->Next;
	}
	flag++;
	r->Next = NULL;
	return head;
}
void Print( List L )
{
	List p = L->Next;
	while(p)
	{
		printf("%d ", p->Data);
		p = p->Next;
	}
	putchar('\n');
}

List Merge( List L1, List L2 );		

int main()
{
    List L1, L2, L;
    L1 = Read();
    L2 = Read();
	Print(L1);
    Print(L2);
    L = Merge(L1, L2);
    Print(L);
//    if(L1 == L2)
// 		printf("sssss\n");
  	
    Print(L1);
    Print(L2);
    return 0;
}

/************以上为不能改动的代码，下面为您的代码*************/
List Merge( List L1, List L2 )
{
  if(L1->Next == NULL)
    return L2;
  if(L2->Next == NULL)
    return L1;
  List p1 = L1->Next, p2 = L2->Next, Head;
  L2->Next = L1->Next = NULL;
  /*这样处理有个问题。。。。这个指针是形参，
  //不能复用L1或L2的头节点
  if(p1->Data > p2->Data)
  {
    Head = L2;
    L2 = L1;
  }
  else
  {
    Head = L1;
    L1 = L2;
  }
  */
//  if(L1 == L2)
//  	printf("sssss\n");
  Head = (List *)malloc(sizeof(struct Node));	//这个空间不能省
  List r = Head;
  while(p1 != NULL && p2 != NULL)
  {
    if(p1->Data > p2->Data)
    {
      r->Next = p2;
      p2 = p2->Next;
    }
    else
    {
      r->Next = p1;
      p1 = p1->Next;
    }
    r = r->Next;
      
  }
//  printf("1:%d\n",L1->Next);
//  printf("1:%d\n",L2->Next);
  if(p1 == NULL)
    r->Next = p2;
  else
    r->Next = p1;
  return Head;
}
