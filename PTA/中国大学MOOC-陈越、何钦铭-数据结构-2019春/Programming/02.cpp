#include<iostream>
using namespace std;
int main()
{
  int n, a[2001][4] = {0};
  int c, index, mix_index = 1001;
  for(int i = 0; i < 2; i++)
  {
	    cin >> n; 
      for(int j = 0; j < n; j++)
      {
        cin >> c >> index;
//        cout << c << index << "test-----------" << endl;
        a[index][i] = c;
        if(index < mix_index)
          mix_index = index;
      }
  }
  int max = -1;
  for(int i = 0; i < 1001; i++)
  {
    if(a[i][0] != 0)
      for(int j = 0; j < 1001; j++)
      {
        if(a[j][1] != 0)
        {
//          cout << i << j << "this is i and j" << endl;
          a[i+j][2] +=  a[i][0] * a[j][1];
          if(i + j > max)
            max = i + j;
        }
      }
  }
  //output mul
  if(max >= 0)
  {
    cout << a[max][2] << " " << max;
    for(int i = max - 1; i >= 0; i--)
      if(a[i][2] != 0)
        cout << " " << a[i][2] << " " << i;
  }
  else
    cout << 0 << " " << 0;  //0多项式
  putchar('\n');
  //output sum
  int first = -1, lock = 1;
  for(int i = 1000; i >= mix_index; i--)
  {
    if((a[i][0] != 0 || a[i][1] != 0 ) && a[i][1] + a[i][0] != 0)
    {
      a[i][3] = a[i][1] + a[i][0];
      if(lock)
      {
        first = i;
        lock = 0;
      }
    }
  }
  if(first >= 0)
  {
    cout << a[first][3] << " " << first;
    for(int i = first - 1; i >= 0; i--)
      if(a[i][3] != 0)
        cout << " " << a[i][3] << " " << i;
  }
  else 
    cout << 0 << " " << 0;    //0 多项式
  return 0;
}
