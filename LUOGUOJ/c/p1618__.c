// luogu-judger-enable-o2
#include<stdio.h>
int main()
{
    int a[9], f = 1;
    int a1, b1, c1, flag = 1;
    scanf("%d%d%d",&a1, &b1, &c1);
    for(int i=123;i<=987;i++)
    {
		if(c1*i/a1 > 987)
		    break;
        a[0]=i/100;a[1]=(i%100)/10;a[2]=i%10;
        a[3]=(b1*i/a1)/100;a[5]=((b1*i/a1)%100)/10;a[8]=(b1*i/a1)%10;
        a[4]=(c1*i/a1)/100;a[6]=((c1*i/a1)%100)/10;a[7]=(c1*i/a1)%10;
        for(int j = 0; j < 9; j++)
            for(int w = j + 1; w < 9; w++)
            {
                if(a[j] == a[w]||a[j]==0)
                {
                    j = 9;
                    f = 0;
                    break;
                }
            }
        if(f == 1)
        {
            flag = 0;
            printf("%d %d %d\n",i,b1*i/a1,c1*i/a1);
        }
        f = 1;
    }
    if(flag)
		 printf("No!!!\n");
	return 0;
}