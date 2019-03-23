List Merge( List L1, List L2 )
{
  if(L1->Next == NULL)
    return L2;
  if(L2->Next == NULL)
    return L1;
  List p1 = L1->Next, p2 = L2->Next;
  L2->Next = L1->Next = NULL;
  List Head = (List *)malloc(sizeof(struct Node));
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
  if(p1 == NULL)
    r->Next = p2;
  else
    r->Next = p1;
  return Head;
}