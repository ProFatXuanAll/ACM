#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cctype>
#include <cstring>
#include <iostream>
#include <map>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <string>

using namespace std;

#define MAX (50000)
#define INF INT_MAX

int s[MAX]; 

struct Node
{
	int valmax, valmin;
	Node *l, *r;

	void update(int v)
	{
		valmin=v;
		valmax=v;
	}

	void pull()
	{
		valmax=max(l->valmax,r->valmax);
		valmin=min(l->valmin,r->valmin);
	}
};

Node* build(int L,int R)
{
	// create new node
	Node* now=new Node();

	// (1) is this node a leaf
	if(L==R)
	{
		now->update(s[L]);
		return now;
	}

	int mid=(L+R)>>1;

	// (2) create left subtree
	now->l=build(L,mid);

	// (3) create right subtree
	now->r=build(mid+1,R);

	// (4) pull
	now->pull();

	return now;
}

int querymax(Node* now,int L,int R,int x,int y)
{
	// (1) There is no overlap between [L, R] and [x, y]
	//     => [x y L R] or [L R x y]
	if(x>R || y<L)
		return -INF;

	// (2) [x, y] completely include [L, R]
	//     => [x L R y]

	if(x<=L && y>=R)
		return now->valmax;

	// (3) Others (partial overlap)
	int mid=(L+R)>>1;

	return max( querymax(now->l,L,mid,x,y), querymax(now->r,mid+1,R,x,y));
}

int querymin(Node* now,int L,int R,int x,int y)
{
	// (1) There is no overlap between [L, R] and [x, y]
	//     => [x y L R] or [L R x y]
	if(x>R || y<L)
		return INF;

	// (2) [x, y] completely include [L, R]
	//     => [x L R y]

	if(x<=L && y>=R)
		return now->valmin;

	// (3) Others (partial overlap)
	int mid=(L+R)>>1;

	return min( querymin(now->l,L,mid,x,y), querymin(now->r,mid+1,R,x,y));
}

void clean(Node* now, int L, int R)
{
	if(L==R)
	{
		delete now;
		return;
	}

	int mid=(L+R)>>1;

	clean(now->l, L, mid);
	clean(now->r, mid+1, R);
	delete now;
}

int main(void)
{
	int N, Q, A, B;
	Node* head=NULL;

	while(scanf("%d%d",&N,&Q)!=EOF)
	{
		for(int i=0;i<N;++i)
		{
			scanf("%d",&s[i]);
		}
		
		head=build(0,N-1);

		for(int i=0;i<Q;++i)
		{
			scanf("%d%d",&A,&B);
			int valmin=querymin(head,0,N-1,A-1,B-1);
			int valmax=querymax(head,0,N-1,A-1,B-1);
			printf("%d\n",valmax-valmin);
		}

		clean(head,0,N-1);
		head=NULL;
	}

	return 0;
}
