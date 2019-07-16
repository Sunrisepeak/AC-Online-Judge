#include<iomanip>　　　　//cout输出格式控制
using namespace std;
double a[1001];
int main()
{
    int n1, n2, flag;
    memset(a, 0,sizeof(a));
    cin >> n1;
    for(int i = 0; i < n1; i++)
    {
        cin >> flag;
        cin >> a[flag];
    }
    cin >> n2;
    double x;
    for(int i = 0; i < n2; i++)
    {
        cin >> flag;
        cin >> x;
        if(a[flag] != 0)　　　　　　　　　　　　　　//减去A中存在项
            n1--;
        a[flag] += x;
        if(a[flag] == 0)
            n1--;　　　　　　                   	//减去和为0的项
        
    }
    cout << n1+n2;　　　　　　　　　　　　　　　　　//输出总的非0项，若多项式之和为0，这里输出一个0即可
    for(int i = 1000; i >= 0; i--)
    {
        if(a[i] != 0)
            cout << " " << i << " " << fixed << setprecision(1)<< a[i];　　　　//用fixed + setprecision(x),控制保留x位小数
    }
    return 0;
}