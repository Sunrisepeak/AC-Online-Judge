#include<iostream>
using namespace std;
int map[5][5] = {
	{0, -1, 1, 1, -1},
	{1, 0, -1, 1, -1},
	{-1, 1, 0, -1, 1},
	{-1, -1, 1, 0, 1},
	{1, 1, -1, -1, 0}
};
void input(int a[], int n)
{
	for(int i = 0; i < n; i++)
		cin >> a[i];
}
int main()
{
	int a[201], b[201];
	int  mark1 = 0, mark2 = mark1;
	int n, n1, n2;
	cin >> n >> n1 >> n2;
	input(a, n1);
	input(b, n2);
	for(int i = 0; i < n; i++)
	{
	//	cout <<"[" <<a[i%n1]<<"," << b[i%n2] <<"]"<<":"<< map[a[i%n1]][b[i%n2]]  << endl;
		if(map[a[i%n1]][b[i%n2]] > 0)
			mark1++;
		if(map[a[i%n1]][b[i%n2]] < 0)
			mark2++;
	}
	cout << mark1 << " " <<mark2;
	return 0;
}