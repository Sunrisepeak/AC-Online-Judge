#include<iostream>
using namespace std;
int sl_list[100000][2] = {0};
int main()
{
	int head, n, k;
	cin >> head >> n >> k;
	int address = 0;
	for(int i = 0; i < n; i++)
	{ 
		cin >> address;
		if(address < 100000)
			cin >> sl_list[address][0] >> sl_list[address][1];
	}
	int p = head;
	int *save = new int[n+1];
	int length = 0; 
	for(int i = 1; p != -1; i++)
	{
		length++;
		save[length] = p;
		p = sl_list[p][1];
	}
	int i, j;
	for(i = k; i <= length; i += k)
	{
		for(j = i; j > 1 + i - k; j--)
			printf("%05d %d %05d\n", save[j], sl_list[save[j]][0], save[j-1]);
		//对每次逆转后的最后一个结点进行特殊判断(这个地方卡了我5,6个小时)
		if(i <= length - k)
			printf("%05d %d %05d\n", save[j], sl_list[ save[j] ][0], save[i + k]);		
		else if(i < length)
			printf("%05d %d %05d\n", save[j], sl_list[ save[j] ][0], save[i + 1]);
		else
			printf("%05d %d %d\n", save[j], sl_list[ save[j] ][0], -1);
	}
	for(j = i -k + 1; j <= length; j++)
	printf("%05d %d %d\n", save[j], sl_list[save[j]][0], sl_list[save[j]][1]);
	delete [] save; 
	return 0;
}
//测试案例
 
/*剩k-1不反转 
00100 5 3 
00000 4 99999
00100 1 12309
33218 3 00000
99999 5 -1
12309 2 33218

//case 2  全反转 
00100 6 3
00000 4 99999
00100 1 12309
68237 6 -1
33218 3 00000
99999 5 68237
12309 2 33218
*/
