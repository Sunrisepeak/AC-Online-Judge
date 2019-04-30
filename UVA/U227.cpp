//unknow issue

//#define DEBUG
#include<iostream>
#include<cctype>
#include<string>
using namespace std;
string map[5];
int count = 0;
void findBlankAndPrint(int &row, int &col, char c)
{
	if(c == 'p')
		printf("Puzzle #%d:\n",++count);
	for(int i = 0; i < 5; i++)
		for(int j = 0; j < 5; j++)
		{
			if(c == 'f')
			{
				if(isspace(map[i][j]))
				{
					row = i;
					col = j;
					break;
				}
			}
			else
			{
				if(j < 4)
					printf("%c ",map[i][j]);
				else
					printf("%c\n",map[i][j]);
			}
		}
}
bool move(int &row, int &col, char c)
{
	switch(c)
	{
		case 'A': 
				if(row - 1 < 0)
					return false;
				else
				{
					map[row][col] = map[--row][col];
					map[row][col] = ' ';
					break;
				}
				
		case 'B': 
				if(row + 1 >= 5)
					return false;
				else
				{
					map[row][col] = map[++row][col];
					map[row][col] = ' ';
					break;
				}
		case 'L': 
				if(col - 1 < 0)
					return false;
				else
				{
					map[row][col] = map[row][--col];
					map[row][col] = ' ';
					break;
				}
				
		case 'R': 
				if(col + 1 >= 5)
					return false;
				else
				{
					map[row][col] = map[row][++col];
					map[row][col] = ' ';
					break;
				}
	}
	return true;
}
int main()
{
	#ifdef DEBUG
		freopen("data.in","r",stdin);
	#endif
	int blankrow = 0;
	while(1)
	{
		for(int i = 0; i < 5; i++)
		{
			getline(cin, map[i]);
//			cout << "this is debug----------------"<< map[i] << endl; 
			if(map[0].size() == 1)
				return 0;
			if(blankrow){
				putchar('\n');
				blankrow = 0;
			}
		}
		int row = 0, col = 0;
		findBlankAndPrint(row, col, 'f');
		char a;
		int flag = 1;
		while((a = getchar()) != '0'){
			if(flag)
			if(!move(row, col, a))
			{
				printf("Puzzle #%d:\n",++count);
				printf("This puzzle has no final configuration.\n");
				flag = 0;
			}
		}
		if(flag)
			findBlankAndPrint(row, col, 'p');
		getchar();
		blankrow = 1;	
	}
	return 0;
}