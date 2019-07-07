#include<iostream>
using namespace std;
int a[2001];        //存回文的长度
int main()
{
    int l, q, k = 0;
    char *p = 0;        //定义指向字符数组的指针
    cin >> l >> q;
    p = new char[l*l+1];    //申请数组由于L阶的所以要申请lxl+1个（+1是为了从1开始存）
    for(int i = 1; i <= l*l; i++)
        cin >> p[i];    //二维数组的输入（只不过这里线性输入了）
    int x, y;   //定义回文中心的坐标
    for(int i = 0; i < q; i++)
    {
        int flag1 = 1, flag2 = 1;   //控制行列的标志变量
        cin >> x >> y;
        int h = 1, lie = 1;
        while(1)    //检测行和列上的回文串 半长+1（h，lie）
        {
            if(flag1 == 0 && flag2 == 0)
                break;          //当检测完行和列跳出循环
            if(flag1)   //这里检测列
            //边界检测 和 以中心点字母展开比较是否相等（即是否为回文）
            //这里p[(x-1)*l +1]即表示坐标二维矩阵中的(x,1)
                if(x + h - 1 <= (l -1) && x - h - 1 >= 0 && p[(x + h -1)*l + y] == p[(x - h -1)*l + y] )
                    h++;
                else
                    flag1 = 0;
            if(flag2)       //这里检测行
                //此处作用和上述相似
                if(y + lie <= l && y - lie > 0 && p[(x - 1)*l + (y - lie)] == p[(x - 1)*l + (y + lie)] )
                    lie++;
                else
                    flag2 = 0;  
        }
        if(lie >= h)    //找出最大回文长度，并存储
            a[k++] = 2*lie -1;
        else
            a[k++] = 2*h -1;
    }
    for(int i = 0; i < k; i++)
        cout << a[i] << endl;   //输出
    return 0;
}