#include<iostream>
using namespace std;
int main()
{
  int n;
  cin >> n;
  int x, ans = 0, sum = 0;
  int first1 = -1,first2 = 0, end = 0;
  int flag = 1, begin;
  int lock = 1;
  while(cin >> x && n--)
  {
    if(flag)
    {
      begin = x;
      flag = 0;
    }
    if(sum + x >= 0)
    {
      sum += x;
      if(sum == x && lock)
	    {
        first1 = x;
		    lock = 0;
	    }
      if(sum > ans)
      {
		    first2 = first1;
        end = x;
        ans = sum;
      }
    }
    else
	  {
      sum = 0;
	    lock = 1;
	  }
  }
  if(ans == 0 && first1)
  {
    end = x;
    first2 = begin; 
  }
  cout << ans << " " << first2 <<  " "  << end << endl;
  return 0;
}