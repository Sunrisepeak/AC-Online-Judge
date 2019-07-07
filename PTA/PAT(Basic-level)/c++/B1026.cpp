#include <iostream>
using namespace std;
int main()
{
	int c1{0}, c2{0};
	cin >> c1 >> c2;
	int c{0};
	//0.4/0//0.5/+1
	c = ((c2 - c1) % 100 >= 50 ? (c2 - c1) / 100 + 1 : (c2 - c1) / 100);
	int h, m, s;
	h = c / 3600;
	m = (c % 3600) / 60;
	s = c % 60;
	printf("%02d:%02d:%02d", h, m, s);
	return 0;
}
