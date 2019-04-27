#include<iostream>
using namespace std;
typedef struct TNode{
		char data;
		int lchild, rchild;
}STree;
//read input_char and create Static_link Tree
int read_createST(STree t[])
{
		int n;
		cin >> n;
//		cout << n << endl;
		getchar();	//deal with '\n'
		char d, l, r;
		for(int i = 0; i < n; i++)
		{
				scanf("%c %c %c\n", &d, &l, &r);
				t[i].data = d;
				if(l != '-')
						t[i].lchild = l - '0';
				else
						t[i].lchild = -1; 
						
				if(r != '-')
						t[i].rchild = r - '0';
				else
						t[i].rchild = -1; 
		}
		int temp[11] = {0};
		for(int i = 0; i < n; i++)
		{
				temp[t[i].rchild] = 1;
				temp[t[i].lchild] = 1;
		}
		int i;
		for(i = 0; i < n; i++)
				if(temp[i] == 0)
						break;
		if(i == n)
		{
				return -1;
		}
		else
				return i;
}
//judge
bool isomorphic(STree t1[], STree t2[], int root1, int root2)
{
		if(root1 == -1 && root2 == -1)
				return true;
		else if(root1 == -1 || root2 == -1)
				return false;
		else if(t1[root1].data != t2[root2].data)
				return false;
		return (isomorphic(t1, t2, t1[root1].rchild,t2[root2].rchild) && isomorphic(t1, t2, t1[root1].lchild,t2[root2].lchild)) 
				||
		 (isomorphic(t1, t2, t1[root1].rchild,t2[root2].lchild) && isomorphic(t1, t2, t1[root1].lchild,t2[root2].rchild));

}

int main()
{
		STree T1[11], T2[11];
		int root1, root2;
		root1 = read_createST(T1);
//		cout << root1 << " root1" << endl;
		root2 = read_createST(T2);
//		cout << root2 << " root2" << endl;
		if(isomorphic(T1, T2, root1, root2))
				cout << "Yes";
		else
				cout << "No";
		return 0;
}
