#include<iostream>
using namespace std;
typedef struct TNode{
	int value;
	struct TNode *l, *r;
}Tree;

Tree CreateTree(int N)
{
	int x;
	Tree root;
	cin >> x;
	root.value = x;
	root.l = root.r = NULL;
	for(int i = 1; i < N; i++)
	{
		cin >> x;
		Tree *p = &root;
		while(true)
		{
			Tree *temp;
			if(p->value > x)
			{
				if(p->l == NULL)
				{
					temp = new Tree;
					temp->value = x;
					temp->r = temp->l = NULL;
					p->l = temp;
					break;
				}
				p = p->l;
			}
			else
			{
				if(p->r == NULL)
				{
					temp = new Tree;
					temp->value = x;
					temp->r = temp->l = NULL;
					p->r = temp;
					break;
				}
				p = p->r;
			}
		}
	}
	return root;
}

bool isSame(Tree *t1, Tree *t2)
{
	if(t1 == NULL && t2 == NULL)
		return true;
	else if(t1 == NULL || t2 == NULL)
		return false;
	else if(t1->value != t2->value)
		return false;
//	cout << t1->value << "=?" << t2->value << endl;	
	return isSame(t1->l, t2->l) && isSame(t1->r, t2->r);
}

int main()
{
	int N, L;
	while(cin >> N && N != 0)
	{
		cin >> L;
		Tree t = CreateTree(N);
		while(L--)
		{
			Tree t2 = CreateTree(N);
			cout << (isSame(&t, &t2) ? "Yes" : "No");
			putchar('\n');
		}
	}
}
