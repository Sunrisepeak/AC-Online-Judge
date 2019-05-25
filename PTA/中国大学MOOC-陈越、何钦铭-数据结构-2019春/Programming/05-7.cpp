#include<iostream>
//#include<cmath>
//#include<stack>
#define MaxSize 1001
using std::cin;
using std::cout;
using std::endl;
typedef struct HNode{
	int data[MaxSize];
	int size;  	//Heap Element number
}MinHeap;
void CreateMinHeap(MinHeap &mheap, int N)
{
	int x;
	while(N--)
	{
		cin >> x;
		mheap.data[++mheap.size] = x;	//insert element
		for(int i = mheap.size; mheap.data[i/2] != 10001 && mheap.data[i] < mheap.data[i/2];i /= 2)
		{//adjust to minHeap
			int temp = mheap.data[i];
			mheap.data[i] = mheap.data[i/2];
			mheap.data[i/2] = temp;
		}
	}
}
void NodePath(MinHeap mheap, int pos)
{
	while(pos != 0)	//print path of node to root
	{
		cout << mheap.data[pos] << (pos/2 != 0 ? " " : "\n");
		pos = pos/2;
	}
}
int main()
{
	MinHeap mheap;
	mheap.size = 0;
	mheap.data[mheap.size] = 10001;
	int N, M;
	std::cin >> N >> M;
	CreateMinHeap(mheap, N);
	int pos;
	for(int i = 0; i < M; i++)
	{
		cin >> pos;
		NodePath(mheap, pos);
	}
	
	return 0;
}
