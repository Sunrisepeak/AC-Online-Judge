#include <iostream>
using namespace std;

#define MAXSIZE 50
typedef int KeyType;

typedef  struct                     
{ KeyType  key;                                             
} ElemType;  

typedef  struct
{ ElemType  *R; 
  int  length;
} SSTable;                      

void  Create(SSTable &T)
{ int i;
  T.R=new ElemType[MAXSIZE+1];
  cin>>T.length;
  for(i=1;i<=T.length;i++)
     cin>>T.R[i].key;   
}

int  Search_Bin(SSTable T, KeyType k);

int main () 
{  SSTable T;  KeyType k;
   Create(T);
   cin>>k;
   int pos=Search_Bin(T,k);
   if(pos==0) cout<<"NOT FOUND"<<endl;
   else cout<<pos<<endl;
   return 0;
}

/* 请在这里填写答案 */
int  Search_Bin(SSTable T, KeyType k)
{
  int left = 1, right = T.length;
  int ans = 0, mid;
  while(left < right - 1)
  {
    mid = (left + right) / 2;
//    cout << mid << endl;	//this is debug!
    if(T.R[mid].key > k)
      right = mid;
    else if(T.R[mid].key == k)
    {
      ans = mid;
      break;
    }
    else
      left = mid;
  }
  return ans;
}