#include<iostream>
using namespace std;
int main()
{
  int n;
  cin >> n;
  int x, ans = 0, sum = 0;
  while(cin >> x && n--)
  {
    if(ans + x > 0)
    {
      sum += x;
      if(sum > ans)
        ans = sum;
    }
    else
      sum = 0;
  }
  cout << ans << endl;
  return 0;
}