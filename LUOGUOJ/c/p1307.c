#include<stdio.h>
void upset(int n)
{
    int flag = 0;
    while(n)
    {
        if(n%10 || flag)
        {
            printf("%d", n%10);
            flag = 1;
        }
        n = n/10;
    }
}
int main()
{
    int n;
    scanf("%d", &n);
    if(n == 0)
        printf("0");
    else
        if(n < 0)
        {
            printf("-");
            upset(-1 * n);
        }
        else
            upset(n);
    return 0;
}