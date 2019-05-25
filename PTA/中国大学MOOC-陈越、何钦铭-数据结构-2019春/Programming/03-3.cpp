#include<iostream>
#include<string>
#include<stack>
using namespace std;
typedef struct TNode{
	string value;
	struct TNode *lchild, *rchild;
}Tree;

bool outputType = true;

Tree * CreatTree(){
	int n;
	cin >> n;
	n = 2*n;
	string str;
	Tree *node, *root, *pre;
	int flag = 1;
	stack<Tree *> s;
	bool isPush;
	getline(cin,str);	//处理换行符 
	while(n--){
		getline(cin,str);
		if(str.size() > 5)
		{
			node = new Tree;
			node->value = str[str.length() - 1];
			node->rchild = node->lchild = NULL;
			if(flag)	//第一个结点 
			{
				root = node;
				flag = 0;
			}else{
				if(isPush)
				{
					pre = s.top();
					pre->lchild = node;
				}
				else
					pre->rchild = node;
			}
			s.push(node);
			isPush = true;		//mark status to operator 
		}else{
			pre = s.top(); 
			s.pop();
			isPush = false;		//mark status to operator
		}
	}
	return root; 
}

void postorder(Tree *t)
{
	if(t != NULL)
	{
		postorder(t->lchild);
		postorder(t->rchild);
		cout << (outputType ? t->value : " " + t->value);
		outputType = false;
		delete t;
	}
}

int main()
{
	Tree *t;
	t = CreatTree();
	postorder(t);
	return 0;
}
